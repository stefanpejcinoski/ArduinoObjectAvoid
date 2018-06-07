// defines pins numbers
const int trigPin = 8;
const int echoPin = 9;
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
void loop() {
 
int temp;
 
  temp = SensorFunction();
 
 if(temp > 100 ){
  digitalWrite(12 ,LOW );
 }
 else
 {
 
    digitalWrite(12,HIGH);
    digitalWrite(11 ,LOW );
    delay(3000);
    digitalWrite(11,HIGH);
 
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
