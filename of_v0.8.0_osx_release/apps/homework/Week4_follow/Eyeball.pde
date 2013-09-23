class Eyeball {
  // Courtesy of Charlie's in-class example.  

  float x, y;
  float angle;

  void draw(float _x, float _y) {
    
    x = _x;
    y = _y;
    
    pushMatrix();
    {
      translate( x, y );
//      println("x = " + x);
//      println("y = " + y);

      float dx = mouseX - x;
      float dy = mouseY - y;

      angle = atan2( dy, dx );

//      rotate( degrees(angle) );

      fill( 0 );

      // outline
      fill(255);
      ellipse(0, 0, 50, 50);

      // pupil
      fill( 0 );
      ellipse(12, 0, 25, 25);
    }
    popMatrix();
  }
}

