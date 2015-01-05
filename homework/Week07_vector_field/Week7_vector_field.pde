/*
NOTE: I attempted to port this from the openFrameworks example found here:
 https://github.com/cwhitney/algo2013/tree/master/Week7/01_VectorField
 It was an epic battle but in the end I couldn't make it work.
 */
FlowField myField;

void setup() {
  size( 1024, 768 );

  myField = new FlowField();
  myField.setupMe( width, height, 20 );
}

void draw() {
  background( 0 );

  myField.drawMe();
}

void keyPressed() {
  if ( key == '1' ) {
    myField.setRandom();
  }
  else if ( key == '2' ) {
    myField.setPerlin();
  }
}

