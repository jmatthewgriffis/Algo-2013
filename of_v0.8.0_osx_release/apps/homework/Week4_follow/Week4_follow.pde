Rectangle myRect = new Rectangle();

void setup() {
  
  size(600,600);
  smooth();
  frameRate(60);

  myRect.setup();
}

void draw() {
  
  background(0);
  
//  myRect.update();
  
  myRect.xenoToPoint(mouseX, mouseY);
  
  myRect.draw();
}
