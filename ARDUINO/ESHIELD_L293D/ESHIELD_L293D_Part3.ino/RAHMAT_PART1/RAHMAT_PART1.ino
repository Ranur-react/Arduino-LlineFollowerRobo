#define echoPin 9 //Echo Pin
#define trigPin 10 //Trigger Pin
long duration, distance; //waktu untuk kalkulasi jarak

#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.print("Deteksi jarak");

}

void loop() {
ultrasonic();
}
void ultrasonic(){
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration/58.2;

Serial.println("jarak-->"); 
Serial.println(distance); 
Serial.println(""); 
maju();
delay(10);
if(distance<=21){
  henti();
  delay(500);
  maju_Kanan();
  delay(500);
  }

  }
void maju(){
 motor1.setSpeed(200);
 motor1.run(BACKWARD);
 motor2.setSpeed(200);
 motor2.run(BACKWARD);
  }

  void maju_Kanan(){
 motor1.setSpeed(200);
 motor1.run(BACKWARD);
 motor2.setSpeed(200);
 motor2.run(FORWARD);
   }

     void maju_kiri(){
 motor1.setSpeed(200);
 motor1.run(FORWARD);
 motor2.setSpeed(200);
 motor2.run(BACKWARD);
   }

  void henti(){
 motor1.setSpeed(0);
 motor2.setSpeed(0);
    }
