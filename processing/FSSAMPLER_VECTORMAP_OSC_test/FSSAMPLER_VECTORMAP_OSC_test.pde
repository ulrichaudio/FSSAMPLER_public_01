//import hypermedia.net.*;
import oscP5.*;
import netP5.*;

PShape world;
int sizeX=1800;
int sizeY= 1000;

int lange;
int breite;
int radius;

void setup() {
  size(1024, 608);
  // The file "bot1.svg" must be in the data folder
  // of the current sketch to load successfully
  world = loadShape("worldmap.svg");
} 

void draw() {
  background(102);
  shape(world, 0, 0, width, height);  // Draw at coordinate (110, 90) at size 100 x 100


  //COVER THE WATERMARK




  //print("MOUSEX:", mouseX);
  //print("MOUSEY:", mouseY);

  watermark();
}


void watermark() {
  rect(40, 400, 200, 100);
  noStroke();
}



void mouseReleased()
{
    float breite = mouseX;
  float lange = mouseY;
  breite=(map(breite,0,1024,-180,180)+8);
  lange=(map(lange,0,600,90,-90)+25);
  radius=(radius * 40);
  println("Länge: ", breite);
  println("Breite: ", lange);
  println("DIAMETER: ", radius);
}
