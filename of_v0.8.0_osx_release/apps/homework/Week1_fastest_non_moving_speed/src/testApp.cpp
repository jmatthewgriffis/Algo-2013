#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetRectMode(OF_RECTMODE_CENTER);

    wide = 50;
    xPos = ofGetWidth()-wide;
    xVel = 0.005;
    inc = 0.0001;
    multi = 100;
    shift = false;
}

//--------------------------------------------------------------
void testApp::update(){

    xPos -= xVel;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(50);
    ofSetColor(120,75,240);
    ofRect(xPos, ofGetHeight()/2, wide, wide);
    ofSetColor(255);
    ofDrawBitmapString("r to restart", ofGetWidth()/2-50, 20);
    ofDrawBitmapString("LEFT/RIGHT to change xVel; SHIFT for greater change; current = " + ofToString(xVel), ofGetWidth()/2-250, ofGetHeight()-10);
    if (shift) ofDrawBitmapString("(SHIFT)", 10, ofGetHeight()-10);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    // Reset on "r."
    if (key=='r') setup();
    
    // Change the xVel; use SHIFT for greater change.
    if (key==OF_KEY_LEFT) {
        if (shift) xVel -= inc*multi;
        else xVel -= inc;
    }
    if (key==OF_KEY_RIGHT) {
        if (shift) xVel += inc*multi;
        else xVel += inc;
    }
    
    if (key==OF_KEY_SHIFT) shift = true;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    if (key==OF_KEY_SHIFT) shift = false;

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
