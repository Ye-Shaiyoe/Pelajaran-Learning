
#define sensor D2
#define buzzerPin D3
#define ledPin D5

void bakar();
void alarm(int jumlah = 1);

void setup() {
  Serial.begin(115200);

  pinMode(sensor, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
}

void bakar() {
  int kondisiApi = digitalRead(sensor);

  if (kondisiApi == LOW) {
    Serial.println("Ada api!");
    alarm(5);
  } else {
    Serial.println("Tidak ada api.");
  }
}

void alarm(int jumlah) {
  for (int x = 0; x < jumlah; x++) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    delay(250);
  }
}

void loop() {
  bakar();
  delay(500);
}
