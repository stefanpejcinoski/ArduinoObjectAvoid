// defines pins numbers
const int trigPin = 8;
const int echoPin = 9;
const int turn=200;
const int maxDistance=70;
// defines variables
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(4 , OUTPUT);
pinMode(5,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
digitalWrite(4,HIGH);
digitalWrite(5,HIGH);
digitalWrite(11,HIGH);
digitalWrite(12,HIGH);
Serial.begin(9600); // Starts the serial communication
}
void left (int ms) 
 {
  digitalWrite(5 , LOW);
  digitalWrite(12 , LOW); 
  delay(ms); 
  digitalWrite(5 , HIGH);
  digitalWrite(12 , HIGH);
 }
void Object (int del) 
 {
 
   Stop();
   right (del);
   Stop();
   left (3*del);
   Stop();
   right (del);
   Stop();
 }
 
 void right (int ms )
 {
  digitalWrite(4 , LOW); 
  digitalWrite(12 , LOW);
  delay(ms);
  digitalWrite(4, HIGH);
  digitalWrite(12 , HIGH);
 }

void startMotor (void)
{
  digitalWrite(12 , LOW); 
}
void stopMotor(void)
{
  if(digitalRead(12))
  digitalWrite(12 , LOW);
  if(digitalRead(11))
  digitalWrite(11 , LOW);
}
void Stop (void)
{
  int state=digitalRead(12);
  digitalWrite(12 , HIGH);
  digitalWrite(11 , HIGH); 
  if(state)
  {
  digitalWrite(11 , LOW);
  delay(turn/2);
  digitalWrite(11 , HIGH);
 }
else 
{
  digitalWrite(12 , LOW); 
  delay(turn/2);
  digitalWrite(12 , HIGH); 
}
}


 void rew (void)
 {
  digitalWrite(11 , LOW);
 }
void loop() {

while(true)
{
  if(sensorFunction()>maxDistance)
  {
    Object (turn);
  }
  startMotor();
  delay(turn/2);
  stopMotor();
  rew();
  delay(turn/5);
}

 
}
 
int sensorFunction(){
 
  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
 
return distance;
 
  }
