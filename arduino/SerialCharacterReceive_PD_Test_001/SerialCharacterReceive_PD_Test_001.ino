int Dword;
void setup(){
pinMode(13,OUTPUT);
 Serial.begin(9600);
 Serial.write("Power On");
}

void loop(){
Dword=Serial.read();

if(Dword=='1'){
 Serial.write("i got a 1");
 digitalWrite(13,HIGH);
 delay(500);
  digitalWrite(13,LOW);
}
if(Dword=='2'){
 Serial.write("but now i got a 2");
  digitalWrite(13,HIGH);
 delay(500);
  digitalWrite(13,LOW);
  delay(500);
   digitalWrite(13,HIGH);
 delay(500);
  digitalWrite(13,LOW);
}
if(Dword=='3'){
 Serial.write("then i get a 3");
  digitalWrite(13,HIGH);
 delay(500);
  digitalWrite(13,LOW);
  delay(500);
   digitalWrite(13,HIGH);
 delay(500);
  digitalWrite(13,LOW);
    delay(500);
   digitalWrite(13,HIGH);
 delay(500);
  digitalWrite(13,LOW);
}
if(Dword=='4'){
 Serial.write("finally i got a 4");
  digitalWrite(13,HIGH);
 delay(500);
  digitalWrite(13,LOW);
  delay(500);
   digitalWrite(13,HIGH);
 delay(500);
  digitalWrite(13,LOW);
    delay(500);
   digitalWrite(13,HIGH);
 delay(500);
  digitalWrite(13,LOW);
    delay(500);
   digitalWrite(13,HIGH);
 delay(500);
  digitalWrite(13,LOW);
}


}
