//includes
#include <AFMotor.h>


//defines
#define bps 2400


//AFMotor declaration
AF_DCMotor motor1(4);
AF_DCMotor motor2(3);


//vars
String data;
String entryA;





void setup() {

  //setup comm.

  Serial.begin(bps);
  Serial.setTimeout(45);




//setup moteur
  motor1.setSpeed(0);
  motor2.setSpeed(0);

  motor1.run(RELEASE);
  motor2.run(RELEASE);

}

void loop() {
  uint8_t i;



  if (Serial.available()>0){

   data = Serial.readString();


   entryA = data.substring(12,16);
   leftspeed = entryA.toInt();

   entryA = data.substring(16,20);
   rightspeed = entryA.toInt();


   //left motor speed set
   if(leftspeed<400){
     motor1.run(BACKWARD);
     motor1.setSpeed(180);
    }
    else if(400<leftspeed<600){
     motor1.run(RELEASE);
    }
    else if(600<leftspeed<1024){
     motor1.run(FORWARD);
     leftspeed=map(leftspeed,600,1024,100,250);
     motor1.setSpeed(leftspeed);
    }




    //right motor speed set
    if(rightspeed<400){
     motor2.run(BACKWARD);
     motor2.setSpeed(180);
    }
    else if(400<rightspeed<600){
     motor2.run(RELEASE);
    }
    else if(600<rightspeed<1024){
     motor2.run(FORWARD);
     rightspeed=map(rightspeed,600,1024,100,250);
     motor2.setSpeed(rightspeed);
    }


  }else{

    
  }




 }
