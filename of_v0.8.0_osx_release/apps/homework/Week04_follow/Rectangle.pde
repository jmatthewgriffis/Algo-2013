class Rectangle {

  // For the rect.
  float x, y;
  int wide, tall;
  
  // For the eyeballs.
  Eyeball leftEye = new Eyeball();
  Eyeball rightEye = new Eyeball();

  void setup() {

    rectMode(CENTER);
    
    x = width/2;
    y = height/2;
    wide = 100;
    tall = wide;
  }

  void draw() {

    fill(50, 50, 255);
    rect(x, y, wide, tall);
    leftEye.draw(x-25, y-10);
    rightEye.draw(x+25, y-10);
  }

  void xenoToPoint(float catchX, float catchY) {
    
    float catchUpSpeed = 0.03;
    
    x = catchUpSpeed * catchX + (1-catchUpSpeed) * x;
    y = catchUpSpeed * catchY + (1-catchUpSpeed) * y;
  }
}

