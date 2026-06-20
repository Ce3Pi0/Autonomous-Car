#define RED_LED 2
#define GREEN_LED 3

#define GREEN_DELAY 5000 // 5 seconds
#define RED_DELAY 7000 // 7 seconds

void turnGreen();
void turnRed();

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop () {
  turnGreen();
  turnRed();
}

void turnGreen() {
  digitalWrite(GREEN_LED, HIGH);
  delay(GREEN_DELAY);
  digitalWrite(GREEN_LED, LOW);
}

void turnRed() {
  digitalWrite(RED_LED, HIGH);
  delay(RED_DELAY);
  digitalWrite(RED_LED, LOW);
}