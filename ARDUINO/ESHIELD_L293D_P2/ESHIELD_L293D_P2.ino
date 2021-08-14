//#include <AccelStepper.h>
#include <AFMotor.h>

AF_DCMotor motor1(2);
AF_DCMotor motor2(1);
int FrontLight=52;

void setup() {
  // put your setup code here, to run once:,
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor party!");
//  pinMode(A15,OUTPUT);
  

}
void loopx(){

  analogWrite(A15,128);
  Serial.print("Nili Analog Cahaya: 128" );
  delay(1000);
  analogWrite(A15,120);
  Serial.print("Nili Analog Cahaya: 120");
  delay(1000);
    analogWrite(A15,255);
  Serial.print("Nili Analog Cahaya: 255");
  delay(1000);
}
void loop() {
 
  Serial.print("maju..");

//Jalan_Lurus
  while(true){
    maju(200);
    delay(1000);
    belokKanan(100,100); //kanan
    delay(500);
    maju(0);
    delay(1000);
    belokKiri(100,100);//                                                                                                                                                     90); //kanan
    delay(500);
    maju(0);
    delay(1000);
    break;
    }
//    henti();
maju(0);
    delay(5000);

  
}

void maju(int spd){

 motor1.run(FORWARD);
  motor1.setSpeed(spd);

 motor2.run(FORWARD);
  motor2.setSpeed(spd);
  }

void belokKanan(int spdL,int spdR){
 
 motor1.run(FORWARD);//front
 motor1.setSpeed(spdL);

 motor2.run(BACKWARD);//back
  motor2.setSpeed(spdR);
  }

  void belokKiri(int spdL,int spdR){

 motor1.run(BACKWARD);//back
  motor1.setSpeed(spdL);

 motor2.run(FORWARD);//front
  motor2.setSpeed(spdR);
  }
