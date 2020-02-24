#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMSbot(0x61); // Rightmost jumper closed
Adafruit_MotorShield AFMStop(0x60); // Default address, no jumpers

Adafruit_DCMotor *fader0 = AFMStop.getMotor(1);
Adafruit_DCMotor *fader1 = AFMStop.getMotor(2);
Adafruit_DCMotor *fader2 = AFMStop.getMotor(3);
Adafruit_DCMotor *fader3 = AFMStop.getMotor(4);

Adafruit_DCMotor *fader4 = AFMSbot.getMotor(1);
Adafruit_DCMotor *fader5 = AFMSbot.getMotor(2);
Adafruit_DCMotor *fader6 = AFMSbot.getMotor(3);
Adafruit_DCMotor *fader7 = AFMSbot.getMotor(4);

void setup() {
  while (!Serial);
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("MMMMotor party!");

  AFMSbot.begin(); // Start the bottom shield
  AFMStop.begin(); // Start the top shield

  // turn on the DC motor
  fader0->setSpeed(200);
  fader1->setSpeed(200);
  fader2->setSpeed(200);
  fader3->setSpeed(200);
  fader4->setSpeed(200);
  fader5->setSpeed(200);
  fader6->setSpeed(200);
  fader7->setSpeed(200);

  fader0->run(RELEASE);
  fader1->run(RELEASE);
  fader2->run(RELEASE);
  fader3->run(RELEASE);
  fader4->run(RELEASE);
  fader5->run(RELEASE);
  fader6->run(RELEASE);
  fader7->run(RELEASE);
}


void loop() {
  fader0->run(FORWARD);



  fader0->run(BACKWARD);


}
