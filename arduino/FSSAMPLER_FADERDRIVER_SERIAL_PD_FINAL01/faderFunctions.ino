void readAllFader() {
  //TRACK1
  int fader1 = analogRead(A15);
  int fader2 = analogRead(A11);
  //TRACK2
  int fader3 = analogRead(A14);
  int fader4 = analogRead(A10);
  //TRACK3
  int fader5 = analogRead(A13);
  int fader6 = analogRead(A9);
  //TRACK4
  int fader7 = analogRead(A12);
  int fader8 = analogRead(A8);
}

void resetTrack1() {
  int fader1 = analogRead(A15);
  int fader2 = analogRead(A11);
  if (fader1 >= 1) {
    mFader1->run(BACKWARD);
  }
  delay(200);
  mFader1->run(RELEASE);

  if (fader2 >= 1) {
    mFader2->run(BACKWARD);
  }
  delay(200);  mFader2->run(RELEASE);
}

void resetTrack2() {
  int fader3 = analogRead(A14);
  int fader4 = analogRead(A10);

  if (fader3 >= 1) {
    mFader3->run(FORWARD);
  }
  delay(220);
  mFader3->run(RELEASE);

  if (fader4 >= 1) {
    mFader4->run(FORWARD);
  }
  delay(220);  mFader4->run(RELEASE);
}

void resetTrack3() {
  int fader5 = analogRead(A13);
  int fader6 = analogRead(A9);

  if (fader5 >= 1) {
    mFader5->run(BACKWARD);
  }
  delay(250);
  mFader5->run(RELEASE);

  if (fader6 >= 1) {
    mFader6->run(BACKWARD);
  }
  delay(250);
  mFader6->run(RELEASE);
}

void resetTrack4() {
  int fader7 = analogRead(A12);
  int fader8 = analogRead(A8);
  if (fader7 >= 1) {
    mFader7->run(FORWARD);
  }
  delay(250);
  mFader7->run(RELEASE);

  if (fader8 >= 1) {
    mFader8->run(FORWARD);
  }
  delay(250);
  mFader8->run(RELEASE);
}
