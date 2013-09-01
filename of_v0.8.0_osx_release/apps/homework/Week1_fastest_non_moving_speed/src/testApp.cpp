#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetRectMode(OF_RECTMODE_CENTER);

    wide = 50;
    xPos = ofGetWidth()-wide;
    yPos = ofGetHeight()/2;
    xVel = 0.005;
    inc = 0.001;
    multi = 10;
    red = 0.1;
    more = false;
    less = false;
}

//--------------------------------------------------------------
void testApp::update(){

    xPos -= xVel;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(50);
    ofSetColor(120,75,240);
    ofRect(xPos, yPos, wide, wide);
    ofSetColor(255);
    ofDrawBitmapString("r to restart  |  click to set new position", ofGetWidth()/2-175, 20);
    ofDrawBitmapString("LEFT/RIGHT to change xVel  |  hold UP/DOWN for greater/lesser change  |  current = " + ofToString(xVel), ofGetWidth()/2-350, ofGetHeight()-10);
    if (more && !less) ofDrawBitmapString("(more)", 658, ofGetHeight()-25);
    else if (!more && less) ofDrawBitmapString("(less)", 658, ofGetHeight()-25);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    // Reset on "r."
    if (key=='r') setup();
    
    // Change the xVel; use UP/DOWN for greater/lesser change.
    if (key==OF_KEY_LEFT) {
        if (more) xVel -= inc*multi;
        else if (less) xVel -= inc*red;
        else xVel -= inc;
    }
    if (key==OF_KEY_RIGHT) {
        if (more) xVel += inc*multi;
        else if (less) xVel += inc*red;
        else xVel += inc;
    }
    
    if (key==OF_KEY_UP) more = true;
    if (key==OF_KEY_DOWN) less = true;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    if (key==OF_KEY_UP) more = false;
    if (key==OF_KEY_DOWN) less = false;

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    xPos = mouseX;
    yPos = mouseY;
    
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
