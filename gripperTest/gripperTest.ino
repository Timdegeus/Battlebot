/*
07-02-2023 - V1.0
*/
//LIBRARIES
#include <Servo.h>
Servo grabber;

//PINNUMBERS
const int grabberPin = 2;      //grabber
const int triggerPin = 4;      //trigger
const int echoPin = 7;         //echo
const int leftMotorPin1 = 3;   //leftmotor1
const int leftMotorPin2 = 5;   //leftmotor2
const int rightMotorPin1 = 9;  //rightmotor1
const int rightMotorPin2 = 6;  //rightmotor2

//VARIABLES
int left = 255;
int right = 255;
unsigned int distance;         //checks the distance
unsigned long duration;        //checks the duration
bool grabberIsClosed = false;  //checks if the grabber is closed or not

//SETUP
void setup() {
  Serial.begin(9600);
  grabber.attach(grabberPin);
//PINMODES
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
}

//LOOP
void loop() {
//closes the grabber if an object is within 5cm
  senseDistance();
  if(distance < 5) {
    grabberClosed();
  } 
  else if(distance > 5) {
    grabberOpen();
  }
}

//FUNCTIONS
// closes the grabber
void grabberClosed() {
  grabber.write(45);
  grabberIsClosed = true;
}
// opens the grabber
void grabberOpen() {
  grabber.write(90);
  grabberIsClosed = false;
}

// senses the distance between the sensor and an object
void senseDistance() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(5);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH); 
  distance = duration * 0.034/2;
}

// enables the battlebot to drive forward
void driveForward() {
   left = 200;
   right = 200;
   analogWrite(leftMotorPin2, left);
   digitalWrite(leftMotorPin1, LOW);
   analogWrite(rightMotorPin2, right);
   digitalWrite(rightMotorPin1, LOW);   
}

//enables the battlebot to turn left
void turnLeft() {
  left = 200;
  right = 200;
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(leftMotorPin1, left);
  analogWrite(rightMotorPin2, right);
  digitalWrite(rightMotorPin1, LOW);
}

//enables the battlebot to turn right
void turnRight() {
  left = 200;
  right = 200;
  analogWrite(leftMotorPin2, left);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
  analogWrite(rightMotorPin1, right);
}

//enables the battlebot to turn around
void turnAround() {
  left = 200;
  right = 200;
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(leftMotorPin1, left);
  analogWrite(rightMotorPin2, right);
  digitalWrite(rightMotorPin1, LOW);
}

//enables the battlebot to stop
void brake() {
   left = 0;
   right = 0;
   analogWrite(leftMotorPin2, left);
   digitalWrite(leftMotorPin1, LOW);
   analogWrite(rightMotorPin2, right);
   digitalWrite(rightMotorPin1, LOW); 
}
