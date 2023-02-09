const int leftMotorPin1 = 3;
const int triggerPin = 4;
const int leftMotorPin2 = 5;
const int rightMotorPin2 = 6;
const int echoPin = 7;
const int rightRotationPin = 8;
const int rightMotorPin1 = 9;
const int leftRotationPin = 10;


<<<<<<< Updated upstream
const int turn = 500;
const int around = 1000;
=======

//Variables
const int turn = 525;
const int around = 1025;
>>>>>>> Stashed changes
int left = 255;
int right = 255;
unsigned long duration;
unsigned int distance;
<<<<<<< Updated upstream

=======
bool checkedLeft = false;
>>>>>>> Stashed changes
bool checkedFrontL = false;
bool checkedLeftL = false;
bool checkedRightL = false;
bool checkingLeft = false;

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
  if(checkingLeft == false && distance < 8) {
    Serial.println("Checking left side");
    checkingLeft = true;
    brake();
    turnLeft();
    brake();
    driveForward();
    detectWall();
    while(checkedFrontL == false) {
      Serial.println("Checking Front");
      driveForward();
      detectWall();
      if(distance < 8) {
        Serial.println("Front wall detected");
        brake();
        turnLeft();
        brake();
        checkedFrontL = true;
      }
    }
    if(checkedFrontL == true) {     
      while(checkedLeftL == false) {
        Serial.println("Checking left");  
        driveForward();
        detectWall();  
        if(distance < 8) {
          Serial.println("Left wall detected");
          brake();
          turnAround();
          brake();
          checkedLeftL = true;
        }
      }
    }
    if(checkedLeftL == true) {     
      while(checkedRightL == false) {
        Serial.println("Checking right");  
        driveForward();
        detectWall();  
        if(distance < 8) {
          Serial.println("Right wall detected");
          brake();
          turnAround();
          brake();
          checkedRightL = true;
        }
      }
    }
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
   right = 210;
   analogWrite(leftMotorPin2, left);
   digitalWrite(leftMotorPin1, LOW);
   analogWrite(rightMotorPin2, right);
   digitalWrite(rightMotorPin1, LOW);   
}

<<<<<<< Updated upstream
void brake() {
=======
void brake() {                          //This function deactivates both motors and will make the battlebot stop driving for a short time
>>>>>>> Stashed changes
   left = 0;
   right = 0;
   analogWrite(leftMotorPin2, left);
   digitalWrite(leftMotorPin1, LOW);
   analogWrite(rightMotorPin2, right);
   digitalWrite(rightMotorPin1, LOW); 
   delay(500);
}

<<<<<<< Updated upstream
void turnRight() {
=======
void stop() {                          //This function deactivates both motors and will make the battlebot stop driving
   left = 0;
   right = 0;
   analogWrite(leftMotorPin2, left);
   digitalWrite(leftMotorPin1, LOW);
   analogWrite(rightMotorPin2, right);
   digitalWrite(rightMotorPin1, LOW); 
}

void turnRight() {                      //This function will make the battlebot make a 90 degree right turn
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
void checkLeft() {
  if(checkedFrontL = false) {
=======
void checkLeft() {                      //This function will make the battlebot check the left side to see if its the right path to take
  Serial.println("Checking left side");
  if(checkedFrontL == false) {
    Serial.println("Checking front");
>>>>>>> Stashed changes
    brake();
    turnLeft();     
    brake();
    driveForward();
    detectWall();
    if(distance < 8) {
      checkedFrontL = true;
      if(checkedFrontL == true && checkedLeftL == false && distance < 8) {
        Serial.println("Checking left");
        brake();
        turnLeft();
        brake();
        if(distance < 8) {
          checkedLeftL = true;
        }
      }
    }
  }
  else {
    Serial.println("Already checked left side");
  }
}
