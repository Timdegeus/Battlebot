//Pinnumbers
const int leftMotorPin1 = 3;
const int triggerPin = 4;
const int leftMotorPin2 = 5;
const int rightMotorPin2 = 6;
const int echoPin = 7;
const int rightRotationPin = 8;
const int rightMotorPin1 = 9;
const int leftRotationPin = 10;



//Variables
const int turn = 500;
const int around = 1000;
int left = 255;
int right = 255;
unsigned long duration;
unsigned int distance;
bool checkedFrontL = false;
bool checkedLeftL = false;
bool checkedRightL = false;



//Setup
void setup() {
  pinMode(triggerPin, OUTPUT);        //Ultra sonic distance sensor trigger
  pinMode(echoPin, INPUT);            //Ultra sonic distance sensor echo
  Serial.begin(9600);                 //Serial.begin for testing purposes
  pinMode(rightMotorPin1, OUTPUT);    //Right motor
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);     //Left motor
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightRotationPin, INPUT);   //Right rotation sensor
  pinMode(leftRotationPin, INPUT);    //Left rotation sensor
}



//Loop
void loop() {
  detectWall();
  if(distance < 10) {
    checkLeft();  
  }
  else {
    driveForward();
  }
}



//Functions
void detectWall() {                     //This function activates the ultra sonic distance sensor and it calculates the distance of the object 
  digitalWrite(triggerPin, LOW);        //in front of it in centimetres
  delayMicroseconds(5);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH); 
  distance = duration * 0.034/2;
}

void driveForward() {                   //This function activates both motors and will make the battlebot drive forward
   left = 200;
   right = 200;
   analogWrite(leftMotorPin2, left);
   digitalWrite(leftMotorPin1, LOW);
   analogWrite(rightMotorPin2, right);
   digitalWrite(rightMotorPin1, LOW);   
}

void brake() {                          //This function deactivates both motors and will make the battlebot stop driving
   left = 0;
   right = 0;
   analogWrite(leftMotorPin2, left);
   digitalWrite(leftMotorPin1, LOW);
   analogWrite(rightMotorPin2, right);
   digitalWrite(rightMotorPin1, LOW); 
   delay(500);
}

void turnRight() {                      //This function will make the battlebot make a 90 degree right turn
  left = 200;
  right = 200;
  analogWrite(leftMotorPin2, left);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(rightMotorPin2, LOW);
  analogWrite(rightMotorPin1, right);
  delay(turn);
}

void turnLeft() {                       //This function will make the battlebot make a 90 degree left turn
  left = 200;
  right = 200;
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(leftMotorPin1, left);
  analogWrite(rightMotorPin2, right);
  digitalWrite(rightMotorPin1, LOW);
  delay(turn);
}

void turnAround() {                     //This function will make the battlebot make a 180 degree turn
  left = 200;
  right = 200;
  digitalWrite(leftMotorPin2, LOW);
  analogWrite(leftMotorPin1, left);
  analogWrite(rightMotorPin2, right);
  digitalWrite(rightMotorPin1, LOW);
  delay(around);
}

void checkLeft() {                      //This function will make the battlebot check the left side to see if its the right path to take
  if(checkedFrontL == false) {
    brake();
    turnLeft();
  }
}
