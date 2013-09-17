#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetCircleResolution(60);
    background = 0;
    ofBackground(background);
    
    amplitudeY = 200;
    rad = 20;
    angle = 0;
    angleVel = 1;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    angle += angleVel;
    
    if (angle > 90 || angle < -90) angleVel *= -1;
    
}

//--------------------------------------------------------------
void testApp::draw(){

    ofPushMatrix();{
        
        ofSetColor(255);
        ofTranslate(ofGetWindowSize()/2);
        ofLine(ofPoint(0,0),pos);
        pos.x = amplitudeY * sin(ofDegToRad(angle));
        pos.y = amplitudeY * cos(ofDegToRad(angle));
        ofCircle(pos, rad);
        
        ofDrawBitmapString("Frictionless, accelerationless sinusoidal pendulum", ofPoint(0,0));
        ofDrawBitmapString("as seen in nature", ofPoint(amplitudeY/2,amplitudeY));
        
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
