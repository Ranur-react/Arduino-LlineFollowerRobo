#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
const int trigPin = A4;
const int echoPin = A3;

long duration;
int distance;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
   motor1.setSpeed(255);
    motor2.setSpeed(255);
    pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
}

void loop() {
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

  
  // put your main code here, to run repeatedly:
int L=analogRead(A1);
int R=analogRead(A2);
int thr=100;
//Serial.print("L: ");
//Serial.print(L);
//Serial.print("R: ");
//Serial.println(R);

if(distance<=20){
while(true){


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
                int L=analogRead(A1);
                int R=analogRead(A2);


                    motor1.run(BACKWARD);
                    motor2.run(BACKWARD);
                    if(L>thr&&R>thr){

                   motor1.run(BACKWARD);
                    motor2.run(BACKWARD);
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

          if(distance>=75){
            
                    motor1.run(BACKWARD);
                   motor2.run(FORWARD);
                   delay(1500);
            break;
            }
  }
  }
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
