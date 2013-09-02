#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // This prevents screen tearing, which is when things are on-screen and there's an update in the middle of the drawing frame. That could mean that the top of an object were in one place and the bottom in another.
    ofSetVerticalSync(true);
    
    // Cool math note about Xeno's paradox: math proves that 0.99 repeating is equal to 1. Why? 1/3 is 0.33 repeating. Multiply that by 3 and you get 0.99 repeating. But 1/3 * 3 = 1. Therefore 0.99 repeating = 1.
    
    for (int i = 0; i < numRects; i++) {
        myRects[i].setup(ofColor(50*i,50*(i*0.5),255-(15*i),255*0.5), ofRandom(0.01f, 0.07f));
        myRects[i].pos.x = ofRandom(0,ofGetWidth());
        myRects[i].pos.y = ofRandom(0,ofGetHeight());
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < numRects; i++) {
        myRects[i].xenoToPoint(mouseX, mouseY);
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(50);
    
    for (int i = 0; i < numRects; i++) myRects[i].draw();
    
    /*ofSetColor(255); // This is for the benefit of the text.
    // Does this Xeno thing really work (i.e. never reach the goal)?
    if (myRect1.pos.x == mouseX && myRect1.pos.y == mouseY) {
        ofDrawBitmapString("Take that, Xeno!", ofPoint(myRect1.pos.x-50, myRect1.pos.y-50));
    }
    // Apparently it does.
    else if (myRect1.pos.x >= mouseX-0.01 && myRect1.pos.x <= mouseX+0.01 && myRect1.pos.y >= mouseY-0.01 && myRect1.pos.y <= mouseY+0.01) {
        ofDrawBitmapString("You win, Xeno.", ofPoint(myRect1.pos.x-50, myRect1.pos.y-50));
    }*/
    
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
