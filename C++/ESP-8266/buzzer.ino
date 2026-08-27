// Deklarasi Pin
const int ledPin = D1;    // GPIO5
const int buzzerPin = D2; // GPIO4

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  digitalWrite(buzzerPin, HIGH); 
  delay(500);
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);  
  delay(500);
}