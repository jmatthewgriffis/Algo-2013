class Particle {

  float x, y;
  float velX, velY;
  float accelX, accelY;

  float wide, tall;
  color c;

  boolean plunger, gravity;

  Particle( float _x, float _y ) {

    wide = 20;
    tall = wide;
    c = color( 204 ); // Silver

    // Centered.
    x = _x;
    y = _y;

    // Zeroed.
    velX = velY = 0;
    accelX = accelY = 0;

    plunger = true;
    gravity = false;
  }

  void applyForce( float x, float y ) {

    accelX += x;
    accelY += y;
  }

  void update() {

    if ( gravity ) {
      applyForce( 0.0, 0.1 );
    }

    // Update vel.
    velX += accelX;
    velY += accelY;

    // Update pos.
    x += velX;
    y += velY;

    // Dampen velocity.
    velX *= 0.99;
    velY *= 0.99;

    // Reset acceleration every frame.
    accelX = accelY = 0;

    // Bounce.
    /*if ( y > height ) {
     velY *= -1;
     }*/
  }

  void drawMe() {

    fill( c );
    ellipse( x, y, wide, tall );
  }
}

