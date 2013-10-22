/*
This is a port of Albert Kim's Whitney-inspired composition in openFrameworks, here:
 https://github.com/thealkimist/kim_algo2013/tree/master/wk3_whitneyInspiration
 */

float myCirclesX[] = new float[20];
float myCirclesY[] = new float[20];
float myCirclesX2[] = new float[100];
float myCirclesY2[] = new float[100];

void setup() {
  size( 1024, 768 );
  smooth();
  frameRate( 60 );

  for ( int i = 0; i < 20; i++ ) {
    myCirclesX[ i ] = width / 2;
    myCirclesY[ i ] = height / 2;
  }

  for ( int i = 0; i < 100; i++ ) {
    myCirclesX2[ i ] = width / 2;
    myCirclesY2[ i ] = height / 2;
  }
}

void draw() {
  background( 0 );

  for ( int i = 0; i < 20; i++ ) {
    float sinOfTime = sin( millis() / 2.5 );
    float sinMapped = map( sinOfTime, -1, 1, 1, 480 );
    stroke( 50, 255, 200 );
    strokeWeight( i + 3.0 );
    noFill();
    ellipse( myCirclesX[ i ], myCirclesY[ i ], sinMapped + ( i * 20 ), sinMapped + ( i * 20 ) );
  }

  for ( int i = 0; i < 20; i++ ) {
    float sinOfTime = sin( millis() / 1.5 );
    float sinMapped = map( sinOfTime, -1, 1, -30, 480 );
    stroke( 255, 55, 120 );
    strokeWeight( i + 2.0 );
    noFill();
    ellipse( myCirclesX[ i ], myCirclesY[ i ], sinMapped + ( i * 21 ), sinMapped + ( i * 21 ) );
  }

  for ( int i = 0; i < 20; i++ ) {
    float sinOfTime = sin( millis() / 2.5 );
    float sinMapped = map( sinOfTime, -1, 1, 1, 800 );
    stroke( 50, 55, 255 );
    strokeWeight( i + 2.0 );
    noFill();
    ellipse( myCirclesX2[ i ], myCirclesY2[ i ], sinMapped + ( i * 21 ), sinMapped + ( i * 21 ) );
  }

  for ( int i = 0; i < 20; i++ ) {
    float sinOfTime = sin( millis() / 7.5 );
    float sinMapped = map( sinOfTime, 1, -1, 1, 500 );
    stroke( 150, 55, 255 );
    strokeWeight( i + 2.0 );
    noFill();
    ellipse( myCirclesX2[ i ], myCirclesY2[ i ], sinMapped + ( i * 21 ), sinMapped + ( i * 21 ) );
  }

  for ( int i = 0; i < 20; i++ ) {
    float sinOfTime = sin( millis() / 5.5 );
    float sinMapped = map( sinOfTime, 1, -1, 1, 500 );
    stroke( 35, 35, 50 );
    strokeWeight( i + 1.1 );
    noFill();
    ellipse( myCirclesX2[i], myCirclesY2[i], sinMapped + ( i * 14 ), sinMapped + ( i * 14 ) );
  }
}

