#include <Servo.h>
Servo myServo;

int  trgg = 9;
int  echo = 8;
long time = 0;
long dist = 0;

void setup()
{
 myServo.attach(2);
 Serial.begin(9600);
 pinMode(echo, INPUT);
 pinMode(trgg, OUTPUT);
}

void loop()
{
  digitalWrite(trgg, LOW);
  delay(5);
  digitalWrite(trgg, HIGH);
  delay(5);
  digitalWrite(trgg, LOW);
  time = pulseIn (echo, HIGH);
  dist = time * 0.034/2;
  
 if( dist >= 332 || dist <= 0)
 {
Serial.println("OUT of BOUNDARIES");
 }
 else 
 {
 Serial.println(dist);
 }
  myServo.write(dist);
  delay(2000);
}