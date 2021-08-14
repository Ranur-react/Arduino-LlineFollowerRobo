//#include <AccelStepper.h>
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor party!");
  
  motor1.setSpeed(200);
  motor1.run(RELEASE);
  motor2.setSpeed(200);
  motor2.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("maju..");
  maju();
  delay(1000);
}

void maju(){
 motor1.setSpeed(200);
  motor1.run(FORWARD);
 motor2.setSpeed(200);
  motor2.run(FORWARD);
  }
