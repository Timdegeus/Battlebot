const int leftMotorPin1 = 3;
const int triggerPin = 4;
const int leftMotorPin2 = 5;
const int rightMotorPin2 = 6;
const int echoPin = 7;
const int rightRotationPin = 8;
const int rightMotorPin1 = 9;
const int leftRotationPin = 10;


const int turn = 500;
const int around = 1000;
int left = 255;
int right = 255;
unsigned long duration;
unsigned int distance;

bool checkedFrontL = false;
bool checkedLeftL = false;
bool checkedRightL = false;

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightRotationPin, INPUT);
  pinMode(leftRotationPin, INPUT);
}

void loop() {
  detectWall();
  if(distance < 10) {
    checkLeft();  
  }
  else {
    driveForward();
  }
}

void detectWall() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(5);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH); 
  distance = duration * 0.034/2;
}

void driveForward() {
   left = 200;
   right = 200;
   analogWrite(leftMotorPin2, left);
   digitalWrite(leftMotorPin1, LOW);
   analogWrite(rightMotorPin2, right);
   digitalWrite(rightMotorPin1, LOW);   
}

void brake() {
   left = 0;
   right = 0;
   analogWrite(leftMotorPin2, left);
   digitalWrite(leftMotorPin1, LOW);
   analogWrite(rightMotorPin2, right);
   digitalWrite(rightMotorPin1, LOW); 
   delay(500);
}

void turnRight() {
  left = 200;
  right = 200;
  analogWrite(leftMotorPin2, left);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
  analogWrite(rightMotorPin1, right);
  delay(turn);
}

void turnLeft() {
  left = 200;
  right = 200;
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(leftMotorPin1, left);
  analogWrite(rightMotorPin2, right);
  digitalWrite(rightMotorPin1, LOW);
  delay(turn);
}

void turnAround() {
  left = 200;
  right = 200;
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(leftMotorPin1, left);
  analogWrite(rightMotorPin2, right);
  digitalWrite(rightMotorPin1, LOW);
  delay(around);
}

void checkLeft() {
  if(checkedFrontL = false) {
    brake();
    turnLeft();
  }
}
