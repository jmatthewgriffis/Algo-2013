#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    // This one listens to the same port that we were sending to in the other app.
    mReceiver.setup( 12345 );
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
        }
        
//        cout<<addr<<endl;
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    ofCircle( mousePos, 20 );
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
