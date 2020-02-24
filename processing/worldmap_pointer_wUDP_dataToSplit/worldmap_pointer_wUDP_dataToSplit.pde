
import processing.serial.*;
import hypermedia.net.*;


//Initialisiere PImage

PImage bg;
UDP udp;  // define the UDP object

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

  // create a new datagram connection on port 6000
  // and wait for incomming message
  udp = new UDP( this, 6000 );
  udp.log( true );     // <-- printout the connection activity
  udp.listen( true );

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
//}

//void keyPressed() {
  int breite = mouseX;
  int lange = mouseY;
  String CoordinateWidth = str(breite);
  String CoordinateLength = str(lange);
  String content = str(radius);
  
  String message  = ( CoordinateWidth +" "+ CoordinateLength +" "+ content );  // the message to send
  String ip       = "localhost";  // the remote IP address
  int port        = 5005;    // the destination port

  // formats the message for Pd
  message = message;
  // send the message
  udp.send( message, ip, port );

  println (message);
}
