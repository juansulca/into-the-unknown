#include <Servo.h>
#include <HCSR04.h>

#define SERVO_1_PIN 6
#define SERVO_2_PIN 7
#define SERVO_3_PIN 8

UltraSonicDistanceSensor distanceSensor1(2, 3);  // Initialize sensor that uses digital pins 2 and 3.
UltraSonicDistanceSensor distanceSensor2(4, 5);

Servo servo1;
Servo servo2;
Servo servo3;

unsigned long time;
unsigned long pastTime;

void setup() {
  Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
  pinMode(13, OUTPUT);

  servo1.attach(SERVO_1_PIN);
  servo2.attach(SERVO_2_PIN);
  servo3.attach(SERVO_3_PIN);

  pastTime = millis();
}

void loop() {
  if (time - pastTime > 1000) { //tick
    digitalWrite(13, LOW);
    float distance1 = distanceSensor1.measureDistanceCm();
    float distance2 = distanceSensor2.measureDistanceCm();
    Serial.println(distance1);
    if (distance1 <= 50) {
      digitalWrite(13, HIGH);
      servoL.write(angle_l);
      servoC.write(angle_c);
      servoR.write(angle_r);
    }
  }
  // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.

  // delay(500);
  
}
