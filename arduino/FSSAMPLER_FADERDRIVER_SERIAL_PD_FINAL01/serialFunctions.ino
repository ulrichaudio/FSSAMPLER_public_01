void sendFaderData() {
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


//map (fader1,0,1023,0,255);

  //Serial.print(" ");
  Serial.print(fader1);
  Serial.print(" ");
  Serial.print(fader2);
  Serial.print(" ");
  Serial.print(fader3);
  Serial.print(" ");
  Serial.print(fader4);
  Serial.print(" ");
  Serial.print(fader5);
  Serial.print(" ");
  Serial.print(fader6);
  Serial.print(" ");
  Serial.print(fader7);
  Serial.print(" ");
  Serial.println(fader8);
}





void serialListen() {
  Dword = Serial.read();


  if (Dword == '1') {
    resetTrack1();
  }

  if (Dword == '2') {
    resetTrack2();
  }

  if (Dword == '3') {
    resetTrack3();
  }

  if (Dword == '4') {
    resetTrack4();
  }

}
