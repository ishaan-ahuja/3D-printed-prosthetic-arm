#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Servo settings
#define SERVO_CHANNEL 5
#define SERVOMIN 150
#define SERVOMAX 600

#define MIN_ANGLE 0
#define MAX_ANGLE 250

void setup() {
  Serial.begin(9600);

  pwm.begin();
  pwm.setPWMFreq(50);
  delay(10);

  Serial.println("Enter an angle between 0 and 250:");
}

void loop() {

  if (Serial.available() > 0) {
    int angle = Serial.parseInt();

    if (angle >= MIN_ANGLE && angle <= MAX_ANGLE) {
      setServoAngle(SERVO_CHANNEL, angle);

      Serial.print("Moving servo to: ");
      Serial.println(angle);
    } 
    else {
      Serial.println("Angle out of range (0-250)");
    }
  }
}

// Converts angle to PWM value
void setServoAngle(uint8_t channel, float angle) {
  angle = constrain(angle, MIN_ANGLE, MAX_ANGLE);
  uint16_t pulse = map(angle, 0, 270, SERVOMIN, SERVOMAX);
  pwm.setPWM(channel, 0, pulse);
}