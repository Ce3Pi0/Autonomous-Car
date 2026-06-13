#include <Servo.h>

#define SERVO_PIN 3

#define DELAY_INTERVAL 3000 // 3 seconds

#define SERVO_LEFT 0
#define SERVO_RIGHT 180

Servo myServo;

void turnServo(int);

void setup() {
  myServo.attach(SERVO_PIN);
}

void loop() {
  turnServo(SERVO_LEFT);
  turnServo(SERVO_RIGHT);
}

void turnServo(int angle) {
  myServo.write(angle);
  delay(DELAY_INTERVAL);
}