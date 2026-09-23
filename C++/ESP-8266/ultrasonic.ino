#define triggerPin D8
#define echoPin D7

void setup() {
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
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
  delay(1000);
}
