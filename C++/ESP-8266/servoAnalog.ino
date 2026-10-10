#include <Servo.h>

#define xPin A0
#define servoPin D6
#define swPin D5

#define centerX 828
#define deadZone 10
int servoPosition = 90;
Servo myservo;

void setup() {
  Serial.begin(115200);
  pinMode (swPin, INPUT_PULLUP);
  myservo.attach(servoPin);
  myservo.write(servoPosition);
}
void loop() {
  int x = analogRead(xPin);

  if (digitalRead(swPin) == LOW) {
    for (int y = servoPosition; y <= 180; y++) {
      myservo.write(y);
      delay(5);
    }
    for (int y = 180; y >= 0; y--) {
      myservo.write(y);
      delay(5);
    }
    for (int y = 0; y <= 90; y++) {
      myservo.write(y);
      delay(5);
    }

    servoPosition = 90;

    while (digitalRead(swPin) == LOW) {
      delay(10);
    }
  }

  if (x > centerX + deadZone) {
    servoPosition += 5;
  } else if (x < centerX - deadZone) {
    servoPosition -= 5;
  }

  servoPosition = constrain(servoPosition, 0, 180);
  myservo.write(servoPosition);

  Serial.print("Nilai x: ");
  Serial.print(x);
  Serial.print(" | Posisi Servo: ");
  Serial.println(servoPosition);

  delay(20);
}
