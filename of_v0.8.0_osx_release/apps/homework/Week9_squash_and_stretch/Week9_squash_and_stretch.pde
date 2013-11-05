// J. Matthew Griffis presents: Serendipity

Particle ball;
Particle attractor;
Particle repeller1;
Particle repeller2;
Particle repeller3;

PFont font;

void setup() {
  size( 600, 600 );
  frameRate( 60 );
  smooth();

  ball = new Particle( width - 40, height - 40 );
  attractor = new Particle ( width - 100, 100 );
  repeller1 = new Particle ( 400, 200 );
  repeller2 = new Particle ( 200, 350 );
  repeller3 = new Particle ( 450, 500 );

  fill( 0 );
  font = loadFont( "Garamond-48.vlw" );
  textFont( font, 24 );
//  text( "Click to launch, 'r' to reload.\nLaunch at least twice.", 10, 25 );
}

// Calculate the distance between a given particle and the ball.
float calcDist( Particle closeTo ) {
  float distance = dist( ball.x, ball.y, closeTo.x, closeTo.y );
  return( distance );
}

// Apply the appropriate forces based on proximity.
void attractAndRepulse() {
  if ( calcDist( attractor ) < 100 ) {
    ball.applyForce( -0.035, 0.0 );
  }

  if ( calcDist( repeller1 ) < 50 ) {
    ball.applyForce( -0.035, -0.5 );
  }

  if ( calcDist( repeller2 ) < 50 ) {
    ball.applyForce( 0.4, -1.0 );
  }

  if ( calcDist( repeller3 ) < 50 ) {
    ball.applyForce( -1.0, -1.25 );
  }
}

void update() {
  attractAndRepulse();
  ball.update();
}

void draw() {
  // Originally this was going to be "Mime Pinball, which it is
  // if you refresh the background. But it's better this way.
  background( 0 );
  
  fill( 255 );
  font = loadFont( "Garamond-48.vlw" );
  textFont( font, 24 );
  text( "Click to launch. 'r' to reload.", 10, 25 );
  
  update();
  ball.drawMe();

  println(ball.velY);

  // Draw only to debug.
  /*attractor.drawMe();
   repeller1.drawMe();
   repeller2.drawMe();
   repeller3.drawMe();*/
}

void mousePressed() {
  if ( ball.plunger ) {
    ball.gravity = true;
    ball.applyForce( 0.0, -14.0 );
    ball.plunger = false;
  }
}

void keyPressed() {
  if ( key == 'r' ) {
    setup();
  }
}

