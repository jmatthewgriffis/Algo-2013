#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // This prevents screen tearing, which is when things are on-screen and there's an update in the middle of the drawing frame. That could mean that the top of an object were in one place and the bottom in another.
    ofSetVerticalSync(true);
    
    // Cool math note about Xeno's paradox: math proves that 0.99 repeating is equal to 1. Why? 1/3 is 0.33 repeating. Multiply that by 3 and you get 0.99 repeating. But 1/3 * 3 = 1. Therefore 0.99 repeating = 1.
    
    myRect.pos.x = ofGetWindowWidth()/2;
    myRect.pos.y = ofGetWindowHeight()/2;
    
    // Interpolate origin
    myRect.posA.x = 10;
    myRect.posA.y = 100;
    // Interpolate destination
    myRect.posB.x = 500;
    myRect.posB.y = 340;
    
//    myRect.interpolateByPct(0.0f); // I don't know that we need this.
    
    pct = 0;

}

//--------------------------------------------------------------
void testApp::update(){
    
    // Turn this on for jitter movement:
//    myRect.update();
    
    
    
    // Turn this on for interpolation-based movement:
//    pct += 0.001f; // Slower movement.
//    pct += 0.01f; // Faster movement.
//    if (pct > 1) pct = 0; // Prevent the percentage from growing beyond 100.
//    myRect.interpolateByPct(pct);
    
    
    
    // Turn this on for Xeno-based movement:
    myRect.xenoToPoint(mouseX, mouseY);

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(50);
    myRect.draw();
    ofSetColor(255); // This is for the benefit of the text.
    
//    ofDrawBitmapString(ofToString(pct),ofPoint(10,10)); // Debug percentage.
    
    // Does this Xeno thing really work (i.e. never reach the goal)?
    if (myRect.pos.x == mouseX && myRect.pos.y == mouseY) {
        ofDrawBitmapString("Take that, Xeno!", ofPoint(myRect.pos.x-50, myRect.pos.y-50));
    }
    // Apparently it does.
    else if (myRect.pos.x >= mouseX-0.01 && myRect.pos.x <= mouseX+0.01 && myRect.pos.y >= mouseY-0.01 && myRect.pos.y <= mouseY+0.01) {
        ofDrawBitmapString("You win, Xeno.", ofPoint(myRect.pos.x-50, myRect.pos.y-50));
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    // Make the tweening (i.e. interpolation) interactive; note that we have to "cast" the numbers as floats to tell the compiler that the numbers and their result should be treated as such (the mouseMoved function takes the y pos as an int):
//    pct = float(y)/float(ofGetWindowHeight());
    
//    myRect.interpolateByPct(pct);

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
