//#include <AccelStepper.h>
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor party!");
  
//  motor1.setSpeed(200);
//  motor1.run(RELEASE);
//  motor2.setSpeed(200);
//  motor2.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("maju..");
//  maju();
  maju_Kanan();
  delay(500);
  henti();
  delay(5000);
  maju_kiri();
  delay(500);
  henti();
  delay(5000);    


//Jalan_Lurus
  while(true){
    maju();
    delay(5000);
    break;
    }





  
}

void maju(){
 motor1.setSpeed(200);
 motor1.run(FORWARD);
 motor2.setSpeed(200);
 motor2.run(FORWARD);
  }

  void maju_Kanan(){
 motor1.setSpeed(200);
 motor1.run(FORWARD);
 motor2.setSpeed(200);
 motor2.run(BACKWARD);
   }

     void maju_kiri(){
 motor1.setSpeed(200);
 motor1.run(BACKWARD);
 motor2.setSpeed(200);
 motor2.run(FORWARD);
   }

  void henti(){
 motor1.setSpeed(0);
 motor2.setSpeed(0);
    }
