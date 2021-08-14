#include <AccelStepper.h>
#include <AFMotor.h>

AF_Stepper motor1(200, 1);
AF_Stepper motor2(200, 2);

void forwardstep1() {  
  motor1.onestep(FORWARD, SINGLE);
}
void backwardstep1() {  
  motor1.onestep(BACKWARD, SINGLE);
}
// wrappers for the second motor!
void forwardstep2() {  
  motor2.onestep(FORWARD, SINGLE);
}
void backwardstep2() {  
  motor2.onestep(BACKWARD, SINGLE);
}
AccelStepper maju (forwardstep1, forwardstep2);
AccelStepper kanan_maju (forwardstep1, backwardstep2);
AccelStepper kiri_maju(forwardstep2, backwardstep1);


void setup() {
  // put your setup code here, to run once:
      maju.setMaxSpeed(200.0);
    maju.setAcceleration(100.0);
    maju.moveTo(24);
//    kanan_maju.setMaxSpeed(200.0);
//    kanan_maju.setAcceleration(100.0);
//    kanan_maju.moveTo(24);
//    
//    kiri_maju.setMaxSpeed(300.0);
//    kiri_maju.setAcceleration(100.0);
//    kiri_maju.moveTo(24);
}

void loop() {
  // put your main code here, to run repeatedly:
maju.run();
delay(1000);
//kiri_maju.run();
//delay(1000);
}
