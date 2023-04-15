int trigPin = 9;
int echoPin = 10;
int led = 7;
long duration, distance;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(100);

  if ((distance <= 10))
  {
    digitalWrite(led, HIGH);
  }
  else if (distance > 10)
  {
    digitalWrite(led, LOW);
  }
}
