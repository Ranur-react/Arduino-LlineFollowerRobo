//A13  sensor nomor 1
//#define 
int tc1=A13;
//A4  sensor nomor 2
int tc2=A4;
//A5  sensor nomor 3
int tc3=A5;
//A14  sensor nomor 4
int tc4=A14;
#include <AFMotor.h>
AF_DCMotor motor1(2);
AF_DCMotor motor2(1);
int FrontLight=52;
void setup() {
  Serial.begin(9600);// set up Serial library at 9600 bps
  Serial.println("Robo Run...!");
}
void loop(){
int La1=analogRead(tc1);
int Lb2=analogRead(tc2);
int Lc3=analogRead(tc3);
int Ld4=analogRead(tc4);


      if(La1<32 & Lb2>32 & Lc3>200 & Ld4<32){//B dan C "Hitam" --Lurus
        analogWrite(A15,128);
              Serial.println("Jalan HITAm -> Lurus");
                  maju(100);
                    }
       else if(La1<32 & Lb2>32 & Lc3<200 & Ld4<32){//B dan C "Hitam" --Lurus-- Stabil
              Serial.println("Jalan HITAm -> Lurus");
                  belokKiri(100,100);// 
                    }
            else if(La1<32 & Lb2<32 & Lc3>200 & Ld4<32){//B dan C "Hitam"--Lurus-- Stabil
              Serial.println("Jalan HITAm -> Lurus");
                  belokKanan(100,100); //kanan
                    }
      else if(La1<32 & Lb2>32 & Lc3>200 & Ld4>32){ //B dan C "Putih-Hitam" --Belok Kanan
              Serial.println("tak ada Jalan -> Belok kanan 1 detik");
                  belokKanan(100,100); //kanan
                  delay(500);
                  maju(100);
               }
      else if(La1>32 & Lb2>32 & Lc3>200 & Ld4<32){ //B dan C "Hitam-Putih" --Belok Kiri
              Serial.println("tak ada Jalan -> Belok kiri 1 detik");
                belokKiri(100,100);//                                                                                                                                                     90); //kanan
                delay(500);
               }
      else if(La1>32 & Lb2>32 & Lc3>200 & Ld4>32){ //B dan C "Hitam-Putih" --Stop
              Serial.println("tak ada Jalan -> Berhenti");
              maju(0);
               }
               
}




void loopX() {
 
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
