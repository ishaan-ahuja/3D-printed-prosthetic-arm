#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Servo channels
#define NUM_SERVOS 5
uint8_t servoChannels[NUM_SERVOS] = {0, 1, 2, 3, 4};

// Open and close angles for each servo
uint16_t servoOpenAngle[NUM_SERVOS]  = {40, 10, 60, 60, 10};
uint16_t servoCloseAngle[NUM_SERVOS] = {220, 145, 220, 200, 50};

// PCA9685 min/max pulse values
#define SERVOMIN 150  // ~0 degrees
#define SERVOMAX 600  // ~180 degrees

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);
  delay(10);

  Serial.println("Commands:");
  Serial.println("open0-close4 or openAll/closeAll");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();  // remove whitespace

    // Individual servo commands
    for (int i = 0; i < NUM_SERVOS; i++) {
      if (input.equalsIgnoreCase("open" + String(i))) {
        setServoAngle(servoChannels[i], servoOpenAngle[i]);
        Serial.print("Servo "); Serial.print(i); Serial.println(" opened");
      } else if (input.equalsIgnoreCase("close" + String(i))) {
        setServoAngle(servoChannels[i], servoCloseAngle[i]);
        Serial.print("Servo "); Serial.print(i); Serial.println(" closed");
      }
    }

    // All servos commands
    if (input.equalsIgnoreCase("openAll")) {
      for (int i = 0; i < NUM_SERVOS; i++) setServoAngle(servoChannels[i], servoOpenAngle[i]);
      Serial.println("All servos opened");
    } else if (input.equalsIgnoreCase("closeAll")) {
      for (int i = 0; i < NUM_SERVOS; i++) setServoAngle(servoChannels[i], servoCloseAngle[i]);
      Serial.println("All servos closed");
    }
  }
}

// Convert angle to PWM and move servo
void setServoAngle(uint8_t channel, uint16_t angle) {
  angle = constrain(angle, 0, 250); // allow up to 250° since some angles exceed 180
  uint16_t pulse = map(angle, 0, 250, SERVOMIN, SERVOMAX);
  pwm.setPWM(channel, 0, pulse);
  Serial.print("Servo ");
  Serial.print(channel);
  Serial.print(" set to angle ");
  Serial.println(angle);
}