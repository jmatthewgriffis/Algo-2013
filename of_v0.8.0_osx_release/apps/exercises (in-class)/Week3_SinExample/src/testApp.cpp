#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
    ofBackground(0);
    ofSetCircleResolution(100);
    
    amplitudeX = ofGetWindowWidth()/2;
    amplitudeY = ofGetWindowHeight()/2;
    period = 5000.0;
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    // Change size with sin.
    /*float sinOfTime = sin(ofGetElapsedTimef() * 2);
    float sinMapped = ofMap(sinOfTime, -1, 1, 50, 80);
    
    ofCircle(ofGetWindowWidth()/2, ofGetWindowHeight()/2, sinMapped);*/
    
    // Move with sin.
    ofPoint pos;
    pos.x = amplitudeX * sin((ofGetElapsedTimeMillis() / period) * TWO_PI);
    pos.y = amplitudeY * cos((ofGetElapsedTimeMillis() / period) * TWO_PI);
    
    ofPushMatrix();{
        
        ofTranslate(ofGetWindowSize()/2);
        ofCircle(pos, 20);
        
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
    
    // This function runs whenever the window is resized. We recalculate the amplitude accordingly to adapt to the new size.
    amplitudeX = w / 2.0;
    amplitudeY = h / 2.0;

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
