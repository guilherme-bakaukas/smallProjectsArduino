                                                                                                                                                                                                                                                                                                                                                         #include <Servo.h>
#include <Ultrasonic.h>

Ultrasonic ultrassom(6,7);//trig porta 6, echo porta 7
long distance;

#define pinServo 4

Servo myServo;

void setup(){
  myServo.attach(pinServo);
  myServo.write(110);//posição do servo inicialmente em 110
}

void loop(){
  distance=ultrassom.Ranging(CM);
  //caso haja algo a uma distancia menor que 8cm do sensor, devemos acionar o motor
  if(distance<8){
    turnOn(); 
  }
  delay(50);
}


void turnOn(){
  //acionamos o motor de maneira gradual
  for (int i = 110; i<179; i+=2){
    myServo.write(i);
    delay(3);
  }
  delay(20);
  myServo.write(110);
}
