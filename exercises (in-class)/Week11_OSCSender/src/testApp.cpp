#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate( 60 );
    ofSetVerticalSync( true );
    
    // Instead of using localhost, could put the IP address of another computer running the receiver and it would work!
    mSender.setup( "localhost", 12345 );
    ofBackground( 0 );
    
    pos = ofGetWindowSize() / 2;
    vel = ofVec2f( 10, 0 );
}

//--------------------------------------------------------------
void testApp::update(){

    pos += vel;
    
    if ( pos.x < 0 || pos.x > ofGetWindowWidth() * 2.0 ) {
        vel.x *= -1;
    }
    if ( pos.y < 0 || pos.y > ofGetWindowHeight() ) {
        vel.y *= -1;
    }
    
    ofxOscMessage m2;
    // The slash is arbitrary but we'll use it to split messages when received.
    m2.setAddress( "/ball/pos" ); // This is like the address on the envelope.
    m2.addFloatArg( pos.x ); // These are like the contents of the envelope.
    m2.addFloatArg( pos.y );
    
    mSender.sendMessage( m2 );
}

//--------------------------------------------------------------
void testApp::draw(){

//    ofCircle( mousePos, 20 );
    ofCircle( pos, 20 );
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

    mousePos.set( x, y );
    
    ofxOscMessage m;
    // The slash is arbitrary but we'll use it to split messages when received.
    m.setAddress( "/mouse/pos" ); // This is like the address on the envelope.
    m.addIntArg( mousePos.x ); // These are like the contents of the envelope.
    m.addIntArg( mousePos.y );
    
    mSender.sendMessage( m );
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
