/*
  Based on the HCSR04 simple example and the base servo setup showed in class
  Autored by:
  - Aileen D
  - Jiayun Qiu
  - Juan Sulca
  - Xinzhou Zhang
*/

#include <HCSR04.h>
#include <Servo.h>

// Servo pin definitions
#define SERVO_1_PIN 9
#define SERVO_2_PIN 10
#define SERVO_3_PIN 11

// Distance sensors setup
UltraSonicDistanceSensor distanceSensor(2, 3, 120);   // Initialize sensor that uses digital pins 2 and 3.
UltraSonicDistanceSensor distanceSensor2(5, 6, 120);  // Initialize sensor that uses digital pins 5 and 6.
// Servo motor setup
Servo servo1;
Servo servo2;
Servo servo3;

void setup() {
  Serial.begin(9600);  // Setup for serial communication
  // Attach servo motors to pins
  servo1.attach(SERVO_1_PIN);
  servo2.attach(SERVO_2_PIN);
  servo3.attach(SERVO_3_PIN);
  // Set servos to 180 degrees
  servo1.write(180);
  servo2.write(180);
  servo3.write(180);
}

void loop() {
  // Measure distance to the right
  float distance = distanceSensor.measureDistanceCm();
  Serial.print("R: ");
  Serial.println(distance);
  delay(300);
  // Measure distance to the left
  float distanceL = distanceSensor2.measureDistanceCm();
  Serial.print("L: ");
  Serial.println(distanceL);
  // Right distance sequences
  if (distance > 0 && distance < 65) { // if there is no erros and the distance is less than 65cm
    short r = random(1, 4); // get random number between 1 and 4
    Serial.print("Rn -> ");
    Serial.println(r);
    switch (r) { // pich a random movement sequence
      case 1:
        servo1_2Motion1();
        break;
      case 2:
        heartBeatMotionServo3();
        break;
      default:
        heartBeatMotionServo2();
    }
  }

  // Left distance sequences
  if (distanceL > 0 && distanceL < 65) { // if there is no erros and the distance is less than 65cm
    short r = random(1, 4); // pick random value between 1 and 3
    Serial.print("Ln -> ");
    Serial.println(r);
    switch (r) { // pich a random movement sequence
      case 1:
        heartBeatMotionServo2();
        break;
      case 2:
        servo3Motion1();
        break;
      default:
        servo1_2_3Motion1();
    }
  }
  delay(700); // Delay 700 ms inbetween cicles
}

void servo3Motion1() { // wiggly back and forward movement
  int pause = random(300, 1000); // use a random delay betwen 300 and 1000
  servo3.write(135);
  delay(150);
  servo3.write(165);
  delay(150);
  servo3.write(105);
  delay(150);
  servo3.write(125);
  delay(150);
  servo3.write(85);
  delay(150);
  servo3.write(35);
  delay(pause);
  servo3.write(180);
  delay(pause);
}

void servo1_2Motion1() { // wiggly back and forward movement
  int pause = random(300, 1000); // use a random delay betwen 300 and 1000
  servo1.write(135);
  servo2.write(135);
  delay(150);
  servo1.write(165);
  servo2.write(165);
  delay(150);
  servo1.write(105);
  servo2.write(105);
  delay(150);
  servo1.write(125);
  servo2.write(125);
  delay(150);
  servo1.write(85);
  servo2.write(85);
  delay(150);
  servo1.write(35);
  servo2.write(35);
  delay(pause);
  servo1.write(180);
  servo2.write(180);
  delay(pause);
}

void servo1_2_3Motion1() { // Push all servos forward one by one and them pull them back
  int pause = random(300, 1000);
  servo1.write(35);
  delay(400);
  servo2.write(35);
  delay(300);
  servo3.write(35);
  delay(pause);
  servo1.write(180);
  delay(400);
  servo2.write(180);
  delay(400);
  servo3.write(180);
  delay(pause);
}

void heartBeatMotionServo3() { // Heartbeat motion
  servo3.write(35);
  delay(600);
  servo3.write(65);
  delay(400);
  servo3.write(35);
  delay(400);
  servo3.write(65);
  delay(400);
  servo3.write(35);
  int pause = random(300, 1000);
  delay(pause);
  servo3.write(180);
}

void heartBeatMotionServo2() { // Heartbeat motion
  servo2.write(35);
  delay(600);
  servo2.write(65);
  delay(400);
  servo2.write(35);
  delay(400);
  servo2.write(65);
  delay(400);
  servo2.write(35);
  int pause = random(300, 1000);
  delay(pause);
  servo2.write(180);
}

void heartBeatMotionServo1() { // Heartbeat motion
  servo1.write(35);
  delay(600);
  servo1.write(65);
  delay(400);
  servo1.write(35);
  delay(400);
  servo1.write(65);
  delay(400);
  servo1.write(35);
  int pause = random(300, 1000);
  delay(pause);
  servo1.write(180);
}

