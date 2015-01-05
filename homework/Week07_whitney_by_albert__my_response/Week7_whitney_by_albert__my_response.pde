/*
This is based on Albert Kim's Whitney-inspired composition, here:
 https://github.com/thealkimist/kim_algo2013/tree/master/wk3_whitneyInspiration
 First I had to port it to Processing.
 */

float myCirclesX[] = new float[20];
float myCirclesY[] = new float[20];
float myCirclesX2[] = new float[100];
float myCirclesY2[] = new float[100];

boolean eyeOpen;
int redEyeTimer;

PImage fingerPic;

void setup() {
  size( 1024, 768 );
  smooth();
  frameRate( 60 );
  imageMode( CENTER );
  noCursor();

  for ( int i = 0; i < 20; i++ ) {
    myCirclesX[ i ] = width / 2;
    myCirclesY[ i ] = height / 2;
  }

  for ( int i = 0; i < 100; i++ ) {
    myCirclesX2[ i ] = width / 2;
    myCirclesY2[ i ] = height / 2;
  }

  eyeOpen = true;
  redEyeTimer = 0;

  // Image src is http://juliabehrens.net/pointer-finger-hi.png
  fingerPic = loadImage( "pointer-finger-hi.png" );
}

void update() {
  if ( redEyeTimer > 0 ) {
    redEyeTimer--;
  }
}

void draw() {
  background( 0 );

  update();

  // Only draw the eye if it should be open.
  if ( eyeOpen ) {

    for ( int i = 0; i < 20; i++ ) {
      float sinOfTime = sin( millis() / 2.5 );
      float sinMapped = map( sinOfTime, -1, 1, 1, 480 );

      // Make it red if angry; else make it regular color.
      if ( redEyeTimer > 0 ) {
        stroke( 255, 0, 0 );
      } 
      else {
        stroke( 50, 255, 200 );
      }

      strokeWeight( i + 3.0 );
      noFill();
      ellipse( myCirclesX[ i ], myCirclesY[ i ], sinMapped + ( i * 20 ), sinMapped + ( i * 20 ) );
    }

    for ( int i = 0; i < 20; i++ ) {
      float sinOfTime = sin( millis() / 1.5 );
      float sinMapped = map( sinOfTime, -1, 1, -30, 480 );

      // Make it red if angry; else make it regular color.
      if ( redEyeTimer > 0 ) {
        stroke( 225, 0, 0 );
      } 
      else {
        stroke( 255, 55, 120 );
      }

      strokeWeight( i + 2.0 );
      noFill();
      ellipse( myCirclesX[ i ], myCirclesY[ i ], sinMapped + ( i * 21 ), sinMapped + ( i * 21 ) );
    }

    for ( int i = 0; i < 20; i++ ) {
      float sinOfTime = sin( millis() / 2.5 );
      float sinMapped = map( sinOfTime, -1, 1, 1, 800 );

      // Make it red if angry; else make it regular color.
      if ( redEyeTimer > 0 ) {
        stroke( 200, 0, 0 );
      } 
      else {
        stroke( 50, 55, 255 );
      }

      strokeWeight( i + 2.0 );
      noFill();
      ellipse( myCirclesX2[ i ], myCirclesY2[ i ], sinMapped + ( i * 21 ), sinMapped + ( i * 21 ) );
    }

    for ( int i = 0; i < 20; i++ ) {
      float sinOfTime = sin( millis() / 7.5 );
      float sinMapped = map( sinOfTime, 1, -1, 1, 500 );

      // Make it red if angry; else make it regular color.
      if ( redEyeTimer > 0 ) {
        stroke( 185, 0, 0 );
      } 
      else {
        stroke( 150, 55, 255 );
      }

      strokeWeight( i + 2.0 );
      noFill();
      ellipse( myCirclesX2[ i ], myCirclesY2[ i ], sinMapped + ( i * 21 ), sinMapped + ( i * 21 ) );
    }

    for ( int i = 0; i < 20; i++ ) {
      float sinOfTime = sin( millis() / 5.5 );
      float sinMapped = map( sinOfTime, 1, -1, 1, 500 );

      // Make it red if angry; else make it regular color.
      if ( redEyeTimer > 0 ) {
        stroke( 150, 0, 0 );
      } 
      else {
        stroke( 35, 35, 50 );
      }

      strokeWeight( i + 1.1 );
      noFill();
      ellipse( myCirclesX2[i], myCirclesY2[i], sinMapped + ( i * 14 ), sinMapped + ( i * 14 ) );
    }
  } // End "if( eyeOpen )"
  else {
    strokeWeight( 1 );
    rect( 0, height / 2, width, 1 );
  }

  // Draw the hand. Vary position based on click.
  if ( eyeOpen ) {
    image( fingerPic, mouseX, mouseY );
  } 
  else {
    image( fingerPic, mouseX, mouseY - 50 );
  }
}

void mousePressed() {
  eyeOpen = false;
}

void mouseReleased() {
  eyeOpen = true;
  redEyeTimer = 60;
}

