//A13  sensor nomor 1
#define tc1=A13;
//A4  sensor nomor 2
#define tc2=A4;
//A5  sensor nomor 3
#define tc3=A5;
//A14  sensor nomor 4
#define tc4=A14;
#include <AFMotor.h>
AF_DCMotor motor1(2);
AF_DCMotor motor2(1);

void setup() {
  Serial.begin(9600);// set up Serial library at 9600 bps
  Serial.println("Robo Run...!");
}
void loop(){
int Ls1=analogRead(tc1);
int Ls2=analogRead(tc2);
int Ls3=analogRead(tc3);
int Ls4=analogRead(tc4);


      if(Ls2>32&LS3>200){//B dan C membaca jalan hitam
              Serial.println("Jalan HITAm -> Lurus");
                    }
      else if(Ls2<32&LS3<200){ //B dan C TIDAK membaca jalan hitam
              Serial.println("tak ada Jalan -> Belok kanan 1 detik");
               }
               
Serial.println(b);
delay(400);
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
