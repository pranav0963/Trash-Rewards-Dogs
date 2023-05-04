//////TRASH REWARDS DOGS///////

//set pins of ultrasound_1
const int trigPin1 = 8;
const int echoPin1 = 9;

//set pins of ultrasound_2
const int trigPin2 = 10;
const int echoPin2 = 11;

//including servo package
#include <Servo.h>

Servo servo1;
Servo servo2;

int pos = 0;
long duration;
int distance=10;

void setup() {

  Serial.begin(9600); //setting up serial communication

  //ultrasound_1
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  //ultrasound_2
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  //servo_1
  servo1.attach(12);

  //servo_2
  servo2.attach(13);
}

void loop() {
  //ask ultrasound_1 for response
  while(distance > 9) {
      digitalWrite(trigPin1, LOW);
      delayMicroseconds(2);

      digitalWrite(trigPin1, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin1, HIGH);

      duration = pulseIn(echoPin1, HIGH);
      distance = duration*0.034/2;

      Serial.print("Distance from servo 1: ");
      Serial.println(distance);
      delay(300);
    }

  distance=10;

  //open servo_1
  for (pos = 0; pos <= 90; pos += 10) {
    servo1.write(pos);
  }

  //ask ultrasound_2 for response
  while(distance > 3.5) {
      digitalWrite(trigPin2, LOW);
      delayMicroseconds(2);

      digitalWrite(trigPin2, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin2, HIGH);

      duration = pulseIn(echoPin2, HIGH);
      distance = duration*0.034/2;

      Serial.print("Distance of servo 2: ");
      Serial.println(distance);
    }

  distance=10;

  //close servo_1
  for (pos = 90; pos >= 0; pos -= 10) {
    servo1.write(pos);
  }

  delay(500);
  
  //open servo_2
  for (pos = 0; pos <= 90; pos += 10) {
    servo2.write(pos);
  }

  delay(500);

  //close servo_2
  for (pos = 90; pos >= 0; pos -= 10) {
    servo2.write(pos);
  }

  delay(500);
}

