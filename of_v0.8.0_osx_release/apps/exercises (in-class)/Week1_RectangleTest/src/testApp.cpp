#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // This prevents screen tearing, which is when things are on-screen and there's an update in the middle of the drawing frame. That could mean that the top of an object were in one place and the bottom in another.
    ofSetVerticalSync(true);
    
    // Cool math note about Xeno's paradox: math proves that 0.99 repeating is equal to 1. Why? 1/3 is 0.33 repeating. Multiply that by 3 and you get 0.99 repeating. But 1/3 * 3 = 1. Therefore 0.99 repeating = 1.
    
    myRect.pos.x = ofGetWindowWidth()/2;
    myRect.pos.y = ofGetWindowHeight()/2;
    
    myRect.posA.x = 10;
    myRect.posA.y = 100;
    myRect.posB.x = 500;
    myRect.posB.y = 340;
    
    myRect.interpolateByPct(0.0f);
    
    pct = 0;

}

//--------------------------------------------------------------
void testApp::update(){
    
//    myRect.update();
    
//    pct += 0.001f; // Slower movement.
//    pct += 0.01f; // Faster movement.
    
//    if (pct > 1) pct = 0; // Prevent the percentage from growing beyond 100.
    
    // This is "tweening"--a Flash term similar to interpolation:
//    myRect.interpolateByPct(pct);
    
    myRect.xenoToPoint(mouseX, mouseY);

}

//--------------------------------------------------------------
void testApp::draw(){
    
    myRect.draw();
    
    ofSetColor(255);
    
//    ofDrawBitmapString(ofToString(pct),ofPoint(10,10)); // Debug percentage.

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    // Make the tweening (i.e. interpolation) interactive:
//    pct = float(y)/float(ofGetWindowHeight()); // We have to "cast" the numbers as floats to tell the compiler that the numbers and their result should be treated as such (the mouseMoved function takes the y pos as an int).
    
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
