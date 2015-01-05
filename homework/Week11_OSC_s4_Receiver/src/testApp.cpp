#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate( 60 );
    ofSetVerticalSync( true );
    ofSetWindowPosition( ( ofGetScreenWidth() - ( ofGetWidth() * 2.0 ) ) / 2.0 + ofGetWidth(), ( ofGetScreenHeight() - ( ofGetHeight() * 2.0 ) ) / 2.0 + ofGetHeight() ); // All four windows will be centered together, this one in the upper-right.
    
    // This one listens to the same port that we were sending to in the other app.
    mReceiver.setup( 99999 );
    
    ofBackground( 0 );
}

//--------------------------------------------------------------
void testApp::update(){
    
    checkOsc();
}

void testApp::checkOsc() {
    
    while( mReceiver.hasWaitingMessages() ) {
        ofxOscMessage m;
        mReceiver.getNextMessage( &m );
        
        string addr = m.getAddress();
        
        if ( addr == "/ball/pos") {
            float xPos = m.getArgAsFloat( 0 );
            float yPos = m.getArgAsFloat( 1 );
            
            ballPos.set( xPos, yPos );
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPushMatrix();{
        
        // Simulate one giant screen. The ball is mirrored across multiple apps, but the ball only bounces when it goes an entire screen width off the right of the sender or a height off the bottom, and then each receiver is translated an entire screen width/height in the appropriate direction, so the ball appears to move between screens. WHOA.
        ofTranslate( -ofGetWindowWidth(), -ofGetWindowHeight() );
        ofCircle( ballPos, 20 );
    }ofPopMatrix();
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
