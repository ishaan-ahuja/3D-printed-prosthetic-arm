#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9);   // signal pin
}

void loop() {
    myServo.write(90);
}