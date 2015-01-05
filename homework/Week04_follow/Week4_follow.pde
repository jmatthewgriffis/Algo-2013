// CHALLENGE: These core ideas translate across any language. Make a version of 
// the line follow creature - in processing (processing.org) The processing 
// docs are quite good as well http://processing.org/reference/.

Rectangle myRect = new Rectangle();

void setup() {
  
  size(600,600);
  smooth();
  frameRate(60);

  myRect.setup();
}

void draw() {
  
  background(0);
  
  myRect.xenoToPoint(mouseX, mouseY);
  
  myRect.draw();
}
