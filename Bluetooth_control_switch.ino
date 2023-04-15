void setup()
{
  pinMode(12, OUTPUT); // left motors forward
  pinMode(11, OUTPUT); // left motors reverse
  pinMode(10, OUTPUT); // right motors forward
  pinMode(9, OUTPUT);  // right motors reverse
  pinMode(7, OUTPUT);  // Back-light
  pinMode(6, OUTPUT);  // Front-light
  Serial.begin(9600);
}
void loop()
{
  char t;
  if (Serial.available() > 0)
  {
    t = Serial.read();
    Serial.println(t);
    switch (t)
    {
    case 'F':
      forward();
      break;
    case 'B':
      back();
      break;
    case 'R':
      left();
      break;
    case 'L':
      right();
      break;
    case 'W':
      flighton();
      break;
    case 'w':
      flightoff();
      break;
    default:
      Stop();
    }
  }
}

//        Funcation Defination

void forward()
{
  digitalWrite(12, HIGH);
  digitalWrite(10, HIGH);
}

void back()
{
  digitalWrite(11, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(7, HIGH);
}

void left()
{
  digitalWrite(12, HIGH);
  digitalWrite(9, HIGH);
}

void right()
{
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
}

void Stop()
{
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
}

// Light Sections

void flighton()
{
  digitalWrite(6, HIGH);
}
void flightoff()
{
  digitalWrite(6, LOW);
}
