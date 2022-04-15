/*
   Hansel & Gretel
   Team Name: Sisters Grimm
   Team Members: Leah and Lizzie
   Description: button and servo program
*/

//Servo Code Library
#include <Servo.h>
#define numberOfLights 5

const int ledPathPins[] = {13, 12, 11, 10, 9};  // number of Path LED pins
int ledPathPinState[numberOfLights];      // LED pin states
long int changeTime[numberOfLights];      
int flashRate[numberOfLights];
long flashChange;                 // how often to change the flashing patterns

const int ledFire = 8;              // the number of the fire LED pin
int ledPireState = LOW;             // state of the fire led 

const int cageSwitchPin = 7;          // the numbers of the switch pins
const int gretelOvenSwitchPin = 6;
const int witchOvenSwitchPin = 5;
int cageSwitchState;              // states of the switches
int gretelOvenSwitchState;
int witchOvenSwitchState;

Servo hanselArmServo;             // servo varible initialization
Servo ovenDoorServo;
//const int hanselArmServoPin = 1;        // the numbers of the servo pins
//const int ovenDoorServoPin = 0;

bool witchAtCage = false;           // booleans to state if the characters are on/off the switches
bool witchAtOven = false;
bool gretelAtOven = false;


// -------------------- set up --------------------

void setup(){
  // LED setup
  for(int i = 0; i < numberOfLights; i++) {
    pinMode(ledPathPins[i], OUTPUT);
    changeTime[0] = millis() + 200;
    changeTime[1] = millis() + 300;
  changeTime[2] = millis() + 400;
    changeTime[3] = millis() + 500;
    changeTime[4] = millis() + 600;
    ledPathPinState[i] = LOW;
  }
  setFlashTime();
  
  
  // switch setup
  pinMode (cageSwitchPin, INPUT);
  pinMode (gretelOvenSwitchPin, INPUT);
  pinMode (witchOvenSwitchPin, INPUT);
  
  // servo setup
  hanselArmServo.attach(1);             // attaches the Hansel servo on pin 1
  ovenDoorServo.attach(0);              // attaches the oven door servo on pin 0
}


// -------------------- pseudocode --------------------

// Witch is placed on the Cage Switch
  // Cage Switch triggers Hansel Arm Servo to move ~100 degrees 
  // Cage Switch triggers LED Path to light
    // LED Path has the lights turning on from the cage to the oven, 1-2 on at a time
    //(Stretch: Witch leaves Cage Switch, Hansel Arm Servo goes back to original state)

// Witch & Gretel placed on Oven Switch
  // Oven Switch triggers Oven Door Servo to move ~<180 degrees
  // Oven Switch triggers LED Path to turn off
  // Oven Switch triggers LED Fire to turn on

// Witch is placed inside the oven
  // No Witch on Oven Switch, oven door closes oven after 10-15 seconds(?)


// -------------------- functions --------------------

// led Path
void ledPath() {
  for (int i = 0; i < numberOfLights; i++) {
    if(changeTime[i] <= millis()) {
      ledPathPinState[i] = ~ledPathPinState[i];
      digitalWrite(ledPathPins[i], ledPathPinState[i]);
      changeTime[i] = millis() + flashRate[i];
    }
  }
  if(flashChange <= millis()) setFlashTime();
}

// servo movement
void hanselArmMove() {
  if (digitalRead(cageSwitchPin) == HIGH) {
    hanselArmServo.write(100);        // degrees not final. please test!
  } else {
    hanselArmServo.write(0);
  }
}

void ovenDoorOpen() {
  if (digitalRead(gretelOvenSwitchPin && witchOvenSwitchPin) == HIGH) {
    ovenDoorServo.write(180); // degrees not final. please test!
  } else {
    ovenDoorServo.write(0);
  }
}


// -------------------- loop --------------------

void loop(){
  ledPath();
}


// -------------------- LED Path Flash Timing --------------------

void setFlashTime(){
    for(int i= 0; i<numberOfLights; i++){
      flashRate[i] = 650;
    }
  flashChange = millis() + 2000;  // next time to change pattern
}
