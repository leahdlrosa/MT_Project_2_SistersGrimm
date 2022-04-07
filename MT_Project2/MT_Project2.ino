
/*
   Hansel & Gretel
   Team Name: Sisters Grimm
   Team Members: Leah and Lizzie
   Description: button and servo program
*/

//Servo Code Library
#include<Servo.h>;

//VARIABLES
Servo myServo;
const int buttonPin = 7;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9); //using .attach to initialize servo to pin 9
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // if button is pressed, swivel servo 180 degrees
  if(digitalRead(buttonPin) == HIGH){
    myServo.write(180);
  } else {
    myServo.write(0);
  }
}
