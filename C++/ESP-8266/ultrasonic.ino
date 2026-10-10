#define triggerPin D8
#define echoPin D7
#define buzzerPin D5

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  long duration, jarak;
  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  jarak = (duration / 2) / 29.1;

  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");

  if (jarak > 0 && jarak <= 50) { 
    int delayBuzzer = map(jarak, 2, 50, 50, 500);
    delayBuzzer = constrain(delayBuzzer, 50, 500); // Pembatas nilai delay

    digitalWrite(buzzerPin, HIGH);
    delay(50); 
    digitalWrite(buzzerPin, LOW);
    delay(delayBuzzer);
  } else {
    digitalWrite(buzzerPin, LOW);
    delay(200);
  }
}
