#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate( 60 );
    ofSetVerticalSync( true );
    ofSetWindowPosition( ( ofGetScreenWidth() - ( ofGetWidth() * 2.0 ) ) / 2.0, ( ofGetScreenHeight() - ( ofGetHeight() * 2.0 ) ) / 2.0 ); // All four windows will be centered together, this one in the upper-left.
    
    // Instead of using localhost, could put the IP address of another computer running the receiver and it would work!
    mSender_s2.setup( "localhost", 12345 );
    mSender_s3.setup( "localhost", 54321 );
    mSender_s4.setup( "localhost", 99999 );
    ofBackground( 0 );
    
    pos = ofGetWindowSize() / 2;
    vel = ofVec2f( 10, 10 );
}

//--------------------------------------------------------------
void testApp::update(){

    pos += vel;
    
    if ( pos.x < 0 || pos.x > ofGetWindowWidth() * 2.0 ) {
        vel.x *= -1;
    }
    if ( pos.y < 0 || pos.y > ofGetWindowHeight() * 2.0) {
        vel.y *= -1;
    }
    
    ofxOscMessage m;
    // The slash is arbitrary but we'll use it to split messages when received.
    m.setAddress( "/ball/pos" ); // This is like the address on the envelope.
    m.addFloatArg( pos.x ); // These are like the contents of the envelope.
    m.addFloatArg( pos.y );
    
    mSender_s2.sendMessage( m );
    mSender_s3.sendMessage( m );
    mSender_s4.sendMessage( m );
}

//--------------------------------------------------------------
void testApp::draw(){

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
