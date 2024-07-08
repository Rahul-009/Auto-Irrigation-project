int IN1 = 13;
int IN2 = 12; //motor back
int IN3 = 11;
int IN4 = 10; // motor2 back
char val;
int soilMoistureValue = 0;
int percentage=0;

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  Serial.begin(9600);
  
}
void loop()
{
  // code for watering
  soilMoistureValue = analogRead(A0);
// Serial.print(soilMoistureValue);
// Serial.print("  ");
percentage = map(soilMoistureValue, 490, 1023, 100, 0);
Serial.println(percentage);
if(percentage < 70)  
{
  Serial.println(" pump on");
  digitalWrite(3,LOW);
}
if(percentage >90)
{
  Serial.println("pump off");
  digitalWrite(3,HIGH);
}


  // code for car
  if (Serial.available() > 0)
  {
    val = Serial.read();
    Serial.println(val);

    if ( val == 'F') // Forward
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
    else if (val == 'B') // Backward
    {
      // digitalWrite(IN1, LOW);
      // digitalWrite(IN2, HIGH);
      // digitalWrite(IN3, LOW);
      // digitalWrite(IN4, HIGH);
    }

    else if (val == 'L') //Left
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
    else if (val == 'R') //Right
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }

    else if (val == 'S') //Stop
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }
  }

  
}


