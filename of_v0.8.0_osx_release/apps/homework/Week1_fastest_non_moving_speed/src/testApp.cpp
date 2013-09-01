#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetLineWidth(8);
    ofSetFrameRate(60);

    wide = 50;
    xPos = ofGetWidth()-wide;
    yPos = ofGetHeight()/2;
    xVel = 0.0037;
    inc = 0.001;
    multi = 10;
    red = 0.1;
    more = false;
    less = false;
    frames = 0;
    hours = 0;
    minutes = 0;
    seconds = 0;
    reachMe = 25;
}

//--------------------------------------------------------------
void testApp::update(){

    if (xPos - wide/2 > reachMe) {
        frames++;
        xPos -= xVel;
    }
    
    // Update the clock:
    if (frames >= 60) {
        seconds++;
        frames = 0;
    }
    if (seconds >= 60) {
        minutes++;
        seconds = 0;
    }
    if (minutes >= 60) {
        hours++;
        minutes = 0;
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(50);
    
    // Tell the player what's up.
    ofSetColor(255);
    ofDrawBitmapString("r to reset  |  click to set new position", ofGetWidth()/2-170, 20);
    
    ofDrawBitmapString("LEFT/RIGHT to change xVel  |  hold UP/DOWN for greater/lesser change  |  current = " + ofToString(xVel), ofGetWidth()/2-350, ofGetHeight()-10);
    
    // Indicate modified controls.
    if (more && !less) ofDrawBitmapString("(more)", 658, ofGetHeight()-25);
    else if (!more && less) ofDrawBitmapString("(less)", 658, ofGetHeight()-25);
    
    // Comment.
    ofDrawBitmapString("     Welcome to the\nWorld's most boring race", ofGetWidth()/2-110, ofGetHeight()/2);
    
    // Display elapsed time.
    ofDrawBitmapString("Time: " + ofToString(hours) + ":" + ofToString(minutes) + ":" + ofToString(seconds), ofGetWidth()/2-50, 50);
    
    // Draw the finish line.
    ofLine(reachMe, 0, 25, ofGetHeight());
    ofPushMatrix();
    ofTranslate(-10, 17);
    ofDrawBitmapString("F", ofPoint(50, ofGetHeight()/2-50));
    ofDrawBitmapString("I", ofPoint(50, ofGetHeight()/2-35));
    ofDrawBitmapString("N", ofPoint(50, ofGetHeight()/2-20));
    ofDrawBitmapString("I", ofPoint(50, ofGetHeight()/2-5));
    ofDrawBitmapString("S", ofPoint(50, ofGetHeight()/2+10));
    ofDrawBitmapString("H", ofPoint(50, ofGetHeight()/2+25));
    ofPopMatrix();
    
    // Draw our heroic rectangle.
    ofSetColor(120,75,240);
    ofRect(xPos, yPos, wide, wide);

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
