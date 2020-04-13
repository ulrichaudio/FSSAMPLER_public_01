#include <Wire.h>
#include <Adafruit_MotorShield.h>


Adafruit_MotorShield AFMSbot(0x61); // Rightmost jumper closed
Adafruit_MotorShield AFMStop(0x60); // Default address, no jumpers


Adafruit_DCMotor *mFader6 = AFMSbot.getMotor(1);
Adafruit_DCMotor *mFader8 = AFMSbot.getMotor(2);
Adafruit_DCMotor *mFader1 = AFMSbot.getMotor(3);
Adafruit_DCMotor *mFader3 = AFMSbot.getMotor(4);

Adafruit_DCMotor *mFader2 = AFMStop.getMotor(1);
Adafruit_DCMotor *mFader4 = AFMStop.getMotor(2);
Adafruit_DCMotor *mFader5 = AFMStop.getMotor(3);
Adafruit_DCMotor *mFader7 = AFMStop.getMotor(4);


int motorSpeed = 150;
int Dword;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  //Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMSbot.begin();  // create with the default frequency 1.6KHz
  AFMStop.begin();

  // Set the speed to start, from 0 (off) to 255 (max speed)
  mFader1->setSpeed(motorSpeed);
  mFader2->setSpeed(motorSpeed);
  mFader3->setSpeed(motorSpeed);
  mFader4->setSpeed(motorSpeed);
  mFader5->setSpeed(motorSpeed);
  mFader6->setSpeed(motorSpeed);
  mFader7->setSpeed(motorSpeed);
  mFader8->setSpeed(motorSpeed);


}

int testnumber = 3;

void loop() {
readAllFader();
serialListen();
sendFaderData();
}
