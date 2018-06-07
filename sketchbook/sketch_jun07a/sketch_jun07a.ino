// defines pins numbers
const int trigPin = 8;
const int echoPin = 9;
const int turn=200;
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

 void right (int ms )
 {
  digitalWrite(4 , LOW); 
  digitalWrite(12 , LOW);
  delay(ms);
  digitalWrite(4, HIGH);
  digitalWrite(12 , HIGH);
 }

void fwd (void)
{
  digitalWrite(12 , LOW); 
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


int temp=0;
 
  temp = SensorFunction();
 
 if(temp > 70 ){
  fwd (); 
 }
 else
 {
 
   Stop();
   right (turn);
   Stop();
   left (3*turn);
   Stop();
   right (turn);
   Stop();
   
 
 }
 
}
 
int SensorFunction(){
 
  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
 
return distance;
 
  }
