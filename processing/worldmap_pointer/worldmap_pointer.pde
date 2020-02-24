//Initialisiere PImage
PImage bg;

import processing.serial.*;


//variablen
Serial myPort;
int val;
int y;
int radius=1;
int m=255;


void setup() {
  //frameRate(25);
  size(1024, 600);

  stroke(255, 0, 0, m--);
  fill(255, 0, 0, 200);
  
  bg = loadImage("map.jpg");
  
    String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}


void draw() {
  background(bg);
//fadenkreuz zeichnen
  line(0, mouseY, width, mouseY);  
  line(mouseX, 0, mouseX, height); 
//aiming point
  circle();
}

void circle() {
//aiming point wächst bei gedrückter maustaste
  if (mousePressed == true) {
    ellipse(mouseX, mouseY, radius++, radius++);
    fill(255, 0, 0, m--);
  } else {

    radius=1;
    m=255;
  }
}


//ausgabe der koordinaten nach release maus
void mouseReleased() {
  println("MOUSE_X: ", mouseX);
  println("MOUSE_Y: ", mouseY);
  println("DIAMETER: ", radius);
  
  myPort.write(mouseX);
    myPort.write(mouseY);
  myPort.write(radius);

  
}
