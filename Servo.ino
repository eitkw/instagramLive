#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
}

void loop() {
  myservo1.write(0);
  myservo2.write(180);
 delay(5000);
  myservo1.write(180);
  myservo2.write(0);
  delay(5000);
}
