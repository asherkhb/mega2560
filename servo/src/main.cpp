#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN 3
#define DELAY 1000
Servo myservo;

void setup()
{
  myservo.attach(SERVO_PIN); // control line (yellow) 
  myservo.write(90);         // set servo to 90° (center)
}

void loop() 
{
  myservo.write(90);
  delay(DELAY);
  myservo.write(60);
  delay(DELAY);
  myservo.write(90);
  delay(DELAY);
  myservo.write(150);
  delay(DELAY);
}
