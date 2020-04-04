import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import oscP5.*; 
import netP5.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class FSSAMPLER_VECTORMAP_OSC_WORKING01_radius extends PApplet {

//import hypermedia.net.*;



OscP5 oscP5;
NetAddress myRemoteLocation;

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

public void setup() {
  
  
    myRemoteLocation = new NetAddress("127.0.0.1", 12000);
    
  stroke(255, 0, 0, m--);
  fill(255, 0, 0, 200);

  world = loadShape("worldmap.svg");
} 

public void draw() {
  background(102);
  shape(world, 0, 0, width, height);  // Draw at coordinate (110, 90) at size 100 x 100



  //fadenkreuz zeichnen
  line(0, mouseY, width, mouseY);  
  line(mouseX, 0, mouseX, height); 
  //aiming point
  circle();



  //print("MOUSEX:", mouseX);
  //print("MOUSEY:", mouseY);

}


public void circle() {
  //aiming point wächst bei gedrückter maustaste
  if (mousePressed == true) {
    ellipse(mouseX, mouseY, radius++, radius++);
    fill(255, 0, 0, m--);
  } else {

    radius=1;
    m=255;
  }
}



public void mouseReleased()
{
    float breite = mouseX;
  float lange = mouseY;
  breite=(map(breite,0,1024,-180,180)+8);
  lange=(map(lange,0,600,90,-90)+25);
  radius=(radius * 40);
  println("Länge: ", breite);
  println("Breite: ", lange);
  println("DIAMETER: ", radius);
  
    String CoordinateWidth = str(breite);
  String CoordinateLength = str(lange);
  String content = str(radius);
  String message  = ( CoordinateWidth +" "+ CoordinateLength +" "+ content );  // the message to send
  
  OscMessage myOscMessage = new OscMessage("/incommingWLR");
  myOscMessage.add(breite);
  myOscMessage.add(lange);
  myOscMessage.add(radius);
  OscP5.flush(myOscMessage,myRemoteLocation);

  println (message);
}
  public void settings() {  size(1024, 608); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "--present", "--window-color=#666666", "--hide-stop", "FSSAMPLER_VECTORMAP_OSC_WORKING01_radius" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
