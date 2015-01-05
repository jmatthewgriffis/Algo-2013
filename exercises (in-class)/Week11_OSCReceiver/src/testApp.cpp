#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    // This one listens to the same port that we were sending to in the other app.
    mReceiver.setup( 12345 );
    
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
        
        if ( addr == "/mouse/pos" ) {
            
            int xPos = m.getArgAsInt32( 0 );
            int yPos = m.getArgAsInt32( 1 );
            
            mousePos.set( xPos, yPos );
//            cout<<addr<<endl;
        } else if ( addr == "/ball/pos") {
            float xPos = m.getArgAsFloat( 0 );
            float yPos = m.getArgAsFloat( 1 );
            
            ballPos.set( xPos, yPos );
        }
        
//        cout<<addr<<endl;
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    ofPushMatrix();{
        
        // Simulate one giant screen. The ball is mirrored across both apps, but the ball only bounces when it goes an entire screen width off the right of the sender, and then the receiver is translated an entire screen width to the left, so the ball appears to move from the left of the sender to the right of the receiver and back. WHOA.
        ofTranslate( -ofGetWindowWidth(), 0 );
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
