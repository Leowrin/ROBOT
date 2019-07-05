//includes
#include <AFMotor.h>


//defines
#define bps 2400


//AFMotor declaration
AF_DCMotor motor1(4);
AF_DCMotor motor12(3);

AF_DCMotor motor21(2);
AF_DCMotor motor22(1);


//vars
String data;
String entryA;
int leftspeed;
int rightspeed;
long timeA;
long timeB;




void setup() {

  //setup comm.

  Serial.begin(bps);
  Serial.setTimeout(45);




//setup moteur
  motor11.setSpeed(200);
  motor12.setSpeed(200);//

  motor21.setSpeed(200);
  motor22.setSpeed(200);//

  motor11.run(RELEASE);
  motor12.run(RELEASE);//

  motor21.run(RELEASE);
  motor22.run(RELEASE);//

}






void loop() {
  uint8_t i;







  if (Serial.available()>0){

   data = Serial.readString();
   timeA=millis();

   entryA = data.substring(12,16);
   leftspeed = entryA.toInt();

   entryA = data.substring(16,20);
   rightspeed = entryA.toInt();


   //left motor speed set
   if(leftspeed<400){
     leftspeed = 100;
     motor11.run(BACKWARD);
     motor12.run(BACKWARD);//

     motor11.setSpeed(leftspeed);
     motor12.setSpeed(leftspeed); //

    }
    else if(400<leftspeed  && leftspeed<600){
     motor11.run(RELEASE);
     motor12.run(RELEASE);//

    }
    else if(600<leftspeed && leftspeed<1024){
     motor1.run(FORWARD);
     leftspeed=map(leftspeed,600,1024,100,255);
     motor1.setSpeed(leftspeed);
    }




    //right motor speed set
    if(rightspeed<400){
     rightspeed = 100:
     motor2.run(BACKWARD);
     motor2.setSpeed(rightspeed);
    }
    else if(400<rightspeed<600){
     motor2.run(RELEASE);
    }
    else if(600<rightspeed<1024){
     motor2.run(FORWARD);
     rightspeed=map(rightspeed,600,1024,100,255);
     motor2.setSpeed(rightspeed);
    }


  }else{
    timeB=millis();
    if((timeB-timeA)<1000){
        motor1.setSpeed(leeftspeed);
        motor2.setSpeed(rightspeed);
      }else{
      motor1.run(RELEASE);
      motor2.run(RELEASE);
    }
  }




 }
