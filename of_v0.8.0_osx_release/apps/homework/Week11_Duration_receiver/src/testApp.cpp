#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetFrameRate( 60 );
    ofSetVerticalSync( true );
    
    mReceiver.setup( 12345 );
    
    ofBackground( 0 );
    
    ballPos = ofGetWindowSize() / 2.0;
    ballRad = 10;
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
        
        /*if ( addr == "/ball/pos") {
         float xPos = m.getArgAsFloat( 0 );
         float yPos = m.getArgAsFloat( 1 );
         
         ballPos.set( xPos, yPos );
         }*/
        
        if ( addr == "/ball/size") {
            ballRad += 10;
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofCircle( ballPos, ballRad );
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
