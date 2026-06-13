// ***********************
// INCLUDE Pixy2 and IrSensorArray Libraries !!!
// ***********************

#include <Pixy2.h>
#include <Servo.h>
#include <IrSensorArray.hpp>

#define FWD_SPEED  1400
#define NEUTRAL_SPEED 1500
#define REV_SPEED 1600

#define MIN_PULSE_W 1000
#define MAX_PULSE_W 2000

#define STARTUP_DELAY 5000 // 5 seconds

#define RED 1
#define GREEN 3

// Servo PIN
#define SERVO_PIN A0
#define MOTOR_PIN A4

// IR Sensors
#define IR_L_1 A5
#define IR_L_2 A6
#define IR_L_3 A7

#define IR_R_1 A3
#define IR_R_2 A2
#define IR_R_3 A1

// Servo range: 20 - 160
#define SERVO_STRAIGHT 90
#define SERVO_LEFT 160
#define SERVO_RIGHT 20

#define MAX_ERROR 5.72

// PID
#define Kp 12.0
#define Ki 0.1
#define Kd 0.8

Pixy2 pixy;

Servo servoMotor;
Servo ESC;

float oldD = 0.0;
float prevError = 0.0;
float integral = 0.0;
unsigned long prevTime = 0;

int normalizeIrReading(int);
void printValues(int*, int); 
bool trafficLightCheck();
void fwd();
void stop();

void setup() {
  Serial.begin(9600);

  servoMotor.attach(SERVO_PIN);
  ESC.attach(MOTOR_PIN, MIN_PULSE_W, MAX_PULSE_W);

  pinMode(IR_L_1, INPUT);
  pinMode(IR_L_2, INPUT);
  pinMode(IR_L_3, INPUT);

  pinMode(IR_R_1, INPUT);
  pinMode(IR_R_2, INPUT);
  pinMode(IR_R_3, INPUT);

  pixy.init();

  ESC.writeMicroseconds(NEUTRAL_SPEED);
  delay(STARTUP_DELAY);
}

void loop() {  
  const int sensL1 = normalizeIrReading(analogRead(IR_L_1));
  const int sensL2 = normalizeIrReading(analogRead(IR_L_2));
  const int sensL3 = normalizeIrReading(analogRead(IR_L_3));
  const int sensR1 = normalizeIrReading(analogRead(IR_R_1));
  const int sensR2 = normalizeIrReading(analogRead(IR_R_2));
  const int sensR3 = normalizeIrReading(analogRead(IR_R_3));

  const int irSensorArrayReadings[] = {sensL3, sensL2, sensL1, sensR1, sensR2, sensR3}; 

  IrSensorArray irSensorArray(irSensorArrayReadings);

  printValues(irSensorArray.getValues(), irSensorArray._NUM_SENSORS);

  if (trafficLightCheck() && irSensorArray.isValid()) {
    const float error = irSensorArray.sumWeights();

    unsigned long now = millis();
    float dt = (now - prevTime) / 1000.0;
    if (dt <= 0.0) dt = 0.001;

    const float P = error;
    integral += error * dt;
    const float rawD = (error - prevError) / dt;
    const float D = 0.8 * oldD + 0.2 * rawD;

    integral = constrain(integral, -10.0, 10.0);

    const float correction = Kp * P+  Kd * D + Ki * integral;
    int servoAngle = SERVO_STRAIGHT + (int)correction;
    servoAngle = constrain(servoAngle, SERVO_RIGHT, SERVO_LEFT);

    Serial.println(servoAngle);

    servoMotor.write(servoAngle);

    fwd();

    oldD = D;
    prevError = error;
    prevTime = now;
  } else stop();
}

int normalizeIrReading(int reading) {
  return map(reading, 0, 1024, 0, 2);
}

void printValues(int* values, int size) {
  for (int i = 0; i < size; i++) {
    Serial.print(values[i]);
    Serial.print(" ");
  }
  Serial.println();
}

bool trafficLightCheck() {
  pixy.ccc.getBlocks();

  for (int i = 0; i < pixy.ccc.numBlocks; i++) {
    switch (pixy.ccc.blocks[i].m_signature) {
      case GREEN:
        return true;
      case RED:
        return false;
    }
 }

 return true;
}

void fwd() {
  ESC.writeMicroseconds(FWD_SPEED);
}

void stop() {
  servoMotor.write(SERVO_STRAIGHT);
  ESC.writeMicroseconds(NEUTRAL_SPEED);
  Serial.println("STOP");
}