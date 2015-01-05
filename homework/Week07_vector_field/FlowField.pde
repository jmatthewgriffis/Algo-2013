//-------------------------------------------------
// Don't have vectors here. :( Have to make my own.
/*class Vector {
 float x, y;
 
 Vector( float _x, float _y ) {
 x = _x;
 y = _y;
 }
 }*/
// I WAS WRONG. THERE IS PVECTOR.

//-------------------------------------------------
// Couldn't figure out how to put an arrayList inside another directly. :(
// Have to make a class.
class VectorList {
  ArrayList< PVector > pointList;

  VectorList() {}

  void add( PVector tmp ) {
    pointList.add( tmp );
  }

  int size() {
    return pointList.size();
  }

  PVector get( int x ) {
    PVector tmp = pointList.get( x );
    return tmp;
  }
}

//-------------------------------------------------
class FlowField {
  ArrayList< VectorList > flowList;
  int fieldWidth, fieldHeight, resolution;

  FlowField() {};

  void setupMe( int wide, int tall, int res ) {
    fieldWidth = wide;
    fieldHeight = tall;
    resolution = res;

    int cols = fieldWidth / resolution;
    int rows = fieldHeight / resolution;

    // Make a big list of forces.  We will store them in a 2 dimensional vector. -Charlie
    for ( int y = 0; y < rows; y++ ) {
      VectorList myList = new VectorList();
      flowList.add( myList );

      for ( int x = 0; x < rows; x++ ) {
        PVector dir = new PVector( 1, 0 );
        VectorList currList = flowList.get( y );
        currList.add( dir );
      }
    }
  }

  // Set all the forces in the field to random values -Charlie
  void setRandom() {
    for ( int y = 0; y < flowList.size(); y++ ) {
      VectorList currList = flowList.get( y );
      for ( int x = 0; x < currList.size(); x++ ) {
        PVector currVector = currList.get( x );
        currVector.x = random( -1, 1 );
        currVector.y = random( -1, 1 ) ;
      }
    }
  }

  // Set all the forces in the field based on perlin noise -Charlie
  void setPerlin() {
    for ( int y = 0; y < flowList.size(); y++ ) {
      VectorList currList = flowList.get( y );
      for ( int x = 0; x < currList.size(); x++ ) {
        float noise = map( noise( x * 0.05, y * 0.05 ), 0, 1, 0, TWO_PI );
        PVector currVector = currList.get( x );
        currVector.x = cos(noise);
        currVector.y = sin(noise);
      }
    }
  }

  void drawMe() {
    for ( int y = 0; y < flowList.size(); y++ ) {
      VectorList currList = flowList.get( y );
      for ( int x = 0; x < currList.size(); x++ ) {
        PVector currVector = currList.get( x );
        PVector np = new PVector( x * resolution, y * resolution );
        drawVectorAt( currVector, np );
      }
    }
  }

  void drawVectorAt( PVector vec, PVector pos ) {
    PVector vec_n;
    vec.normalize( vec_n );
    PVector vec_n_m;
    vec_n.mult( vec_n, 5.0, vec_n_m );
    PVector np;
    vec_n_m.sub( pos, vec_n_m, np );
    PVector np_2;
    np.add( np, vec_n, np_2 );
    PVector np_3;
    np_2.mult( np_2, 10.0, np_3 );
    //    drawVector( pos, np_3, 5, 3 ); // And...I'm defeated. I need this function after all and I can't port the
    // madness below. So close, yet so far. I wish I could see what this would look like.
  }

  // I believe this is the one out of Cinder; I am not even going to attempt to port this to Processing. -Matt
  /**
   * This is a complicated one!  It's a translation of the one right out of the Cinder source, no need to understand it,
   * but it's an interesting one to look at anyway!
   * https://github.com/cinder/Cinder/blob/master/src/cinder/gl/gl.cpp line 915 if you're interested -Charlie
   */
  /*
  void FlowField::drawVector( const ofVec3f &start, const ofVec3f &end, float headLength, float headRadius ) {
   const int NUM_SEGMENTS = 32;
   float lineVerts[3*2];
   ofVec3f coneVerts[NUM_SEGMENTS+2];
   glEnableClientState( GL_VERTEX_ARRAY );
   glVertexPointer( 3, GL_FLOAT, 0, lineVerts );
   lineVerts[0] = start.x; 
   lineVerts[1] = start.y; 
   lineVerts[2] = start.z;
   lineVerts[3] = end.x; 
   lineVerts[4] = end.y; 
   lineVerts[5] = end.z;
   glDrawArrays( GL_LINES, 0, 2 );
   
   // Draw the cone
   ofVec3f axis = ( end - start ).normalized();
   ofVec3f temp = ( axis.dot( ofVec3f(0, 1, 0) ) > 0.999f ) ? axis.crossed( ofVec3f(1, 0, 0) ) : axis.crossed( ofVec3f(0, 1, 0) );
   ofVec3f left = ofVec3f(axis.crossed( temp )).normalized();
   ofVec3f up = axis.crossed( left ).normalized();
   
   glVertexPointer( 3, GL_FLOAT, 0, &coneVerts[0].x );
   coneVerts[0] = ofVec3f( end + axis * headLength );
   for ( int s = 0; s <= NUM_SEGMENTS; ++s ) {
   float t = (float)s / (float)NUM_SEGMENTS;
   coneVerts[s+1] = ofVec3f( end + left * headRadius * cos( t * 2.0f * 3.14159f )
   + up * headRadius * sin( t * 2.0f * 3.14159f ) );
   }
   glDrawArrays( GL_TRIANGLE_FAN, 0, NUM_SEGMENTS+2 );
   
   // draw the cap
   glVertexPointer( 3, GL_FLOAT, 0, &coneVerts[0].x );
   coneVerts[0] = end;
   for ( int s = 0; s <= NUM_SEGMENTS; ++s ) {
   float t = s / (float)NUM_SEGMENTS;
   coneVerts[s+1] = ofVec3f( end - left * headRadius * (float)cos( t * 2 * 3.14159f )
   + up * headRadius * (float)sin( t * 2 * 3.14159f ) );
   }
   glDrawArrays( GL_TRIANGLE_FAN, 0, NUM_SEGMENTS+2 );
   
   glDisableClientState( GL_VERTEX_ARRAY );
   }
   */
};

