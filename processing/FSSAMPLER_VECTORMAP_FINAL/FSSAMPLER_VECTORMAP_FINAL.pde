//import hypermedia.net.*;
import oscP5.*;
import netP5.*;
import controlP5.*;

OscP5 oscP5;
OscP5 oscP52;

NetAddress myRemoteLocation;

ControlP5 cp5;

Textarea myTextarea;
Println console;

String value1;
int c = 0;

PShape world;
int sizeX=1800;
int sizeY= 1000;

int lange;
int breite;
int radius;

int val;
int y;
int radiusC=1;
int m=255;

void setup() {
  size(1024, 608);
  //define receive and send port
  oscP52 = new OscP5(this,12001);
  myRemoteLocation = new NetAddress("127.0.0.1", 12000);
  //initialize CP5 object
  cp5 = new ControlP5(this);
  cp5.enableShortcuts();
  
    myTextarea = cp5.addTextarea("txt")
                  .setPosition(8, 540)
                  .setSize(700, 60)
                  .setFont(createFont("", 10))
                  .setLineHeight(10)
                  .setColor(color(0))
                  .setColorBackground(color(255, 0))
                  .setColorForeground(color(255, 100));
  ;
  console = cp5.addConsole(myTextarea);//
  
  stroke(255, 0, 0, m--);
  fill(255, 0, 0, 200);

  world = loadShape("worldmap.svg");
} 
void draw() {
  background(102);
  shape(world, 0, 0, width, height);  // Draw at coordinate (110, 90) at size 100 x 100

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

void mouseReleased()
{
  float breite = mouseX;
  float lange = mouseY;
  breite=(map(breite, 0, 1024, -180, 180)+8);
  lange=(map(lange, 0, 600, 90, -90)+25);
  radius=(radius * 40);
  println("Länge: ", breite);
  println("Breite: ", lange);
  println("Radius: ", radius);

  String CoordinateWidth = str(breite);
  String CoordinateLength = str(lange);
  String content = str(radius);
  String message  = ( CoordinateWidth +" "+ CoordinateLength +" "+ content );  // the message to send

  OscMessage myOscMessage = new OscMessage("/incommingWLR");
  myOscMessage.add(breite);
  myOscMessage.add(lange);
  myOscMessage.add(radius);
  OscP5.flush(myOscMessage, myRemoteLocation);

  println (message);
}

void oscEvent(OscMessage theOscMessage) {
  // Således ser det ud for modtagelse af kun én OSC besked:
  value1 = theOscMessage.get(0).stringValue();
  print(" value1: "+value1);
  

}
