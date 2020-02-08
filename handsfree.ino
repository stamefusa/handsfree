#include <Servo.h>
Servo s;

int val = 0,  preval = 0;
int deg1 = 160, deg2 = 30;
int deg = deg1;
int threshold = 200;

void setup() {
  // put your setup code here, to run once:
  //pinMode(10, INPUT);
  s.attach(7);
  s.write(deg);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(0);
  if (val < threshold && preval > threshold) {
    if (deg == deg1) {
      deg = deg2;
    } else {
      deg = deg1;
    }
  }
  Serial.println(deg);
  s.write(deg);
  delay(100);
  preval = val;
}
