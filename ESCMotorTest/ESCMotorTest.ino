#include <Servo.h>

#define MOTOR_PIN A4

#define FWD_SPEED  1400
#define NEUTRAL_SPEED 1500
#define REV_SPEED 1600

#define MIN_PULSE_W 1000
#define MAX_PULSE_W 2000

#define STARTUP_DELAY 5000 // 5 seconds
#define TEST_INTERVAL_DELAY 3000 // 3 Seconds

Servo ESC;

void setup() {
  ESC.attach(MOTOR_PIN, MIN_PULSE_W, MAX_PULSE_W);

  ESC.writeMicroseconds(NEUTRAL_SPEED);
  delay(STARTUP_DELAY);
}

void fwd();
void stop();

void loop() {
  fwd();
  stop();
} 

void fwd() {
  ESC.writeMicroseconds(FWD_SPEED);
  delay(TEST_INTERVAL_DELAY);
}

void stop() {
  ESC.writeMicroseconds(NEUTRAL_SPEED);
  delay(TEST_INTERVAL_DELAY);
}