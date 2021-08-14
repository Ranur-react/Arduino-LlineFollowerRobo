#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
const int trigPin = A4;
const int echoPin = A5;
long duration;
int distance;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);

}

void loop() {

  speedmotor(100);
  
  // put your main code here, to run repeatedly:
int L=analogRead(A2);
int R=analogRead(A1);
int Lx=analogRead(A3);
int Rx=analogRead(A0);

int thr=50;
Serial.print("L: ");
Serial.print(L);
Serial.print("R: ");
Serial.println(R);




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
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
//
//if(distance<=20){
//  }


// L="B" R="B" 
if(L>thr&&R>thr){

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  }
if(L<thr&&R<thr){
    motor1.run(BACKWARD);
  motor2.run(FORWARD);
  } 
if(L<thr&&R>thr){
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  } 
if(L>thr&&R<thr){
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  
  } 

}

void speedmotor(int spd){
  for(int i=0;i<spd;i++){
       motor1.setSpeed(i);
    motor2.setSpeed(i);
    }
  }
