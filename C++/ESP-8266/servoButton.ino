#include <Servo.h>

Servo myservo;  
const int buttonPin = 2; 
int pos = 0; // Variabel untuk menyimpan posisi servo

void setup() {
  myservo.attach(15);  
  pinMode(buttonPin, INPUT_PULLUP);
  myservo.write(pos); 
  Serial.begin(115200);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    if (pos < 180) {
      pos++;
      myservo.write(pos);
      Serial.print("Bergerak ke: ");
      Serial.println(pos);
      delay(15);
    }
  } else {
    if (pos > 0) {
      pos--;
      myservo.write(pos);
      Serial.print("Kembali ke: ");
      Serial.println(pos);
      delay(15);
    }
  }
}
