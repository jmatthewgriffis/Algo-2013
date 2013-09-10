#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // This prevents screen tearing, which is when things are on-screen and there's an update in the middle of the drawing frame. That could mean that the top of an object were in one place and the bottom in another.
    ofSetVerticalSync(true);
    
    // Cool math note about Xeno's paradox: math proves that 0.99 repeating is equal to 1. Why? 1/3 is 0.33 repeating. Multiply that by 3 and you get 0.99 repeating. But 1/3 * 3 = 1. Therefore 0.99 repeating = 1.
    
    // Setup the rects.
    for (int i = 0; i < numRects; i++) {
        tempRct.setup(ofColor(50*i,50*(i*0.5),255-(15*i),255*0.5), ofRandom(0.01f, 0.07f));
        tempRct.pos.x = ofRandom(0,ofGetWidth());
        tempRct.pos.y = ofRandom(0,ofGetHeight());
        myRects.push_back(tempRct);
    }
    
    offset = 100;
    surrounded = false;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    /*
     0 -1/3, -1/3
     1 0, -1/3
     2 1/3, -1/3
     3 -1/3, 0
     4 1/3, 0
     5 -1/3, 1/3
     6 0, 1/3
     7 1/3, 1/3
     */
    
    myRects[0].xenoToPoint(mouseX-offset, mouseY-offset);
    myRects[1].xenoToPoint(mouseX, mouseY-offset);
    myRects[2].xenoToPoint(mouseX+offset, mouseY-offset);
    myRects[3].xenoToPoint(mouseX-offset, mouseY);
    myRects[4].xenoToPoint(mouseX+offset, mouseY);
    myRects[5].xenoToPoint(mouseX-offset, mouseY+offset);
    myRects[6].xenoToPoint(mouseX, mouseY+offset);
    myRects[7].xenoToPoint(mouseX+offset, mouseY+offset);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(50);
    
    
    // Tell the player what's up.
    ofSetColor(255);
    ofDrawBitmapString("r to reset  |  move the mouse", ofGetWidth()/2-110, 20);
    
    
    // Draw the rects.
    for (int i = 0; i < numRects; i++) myRects[i].draw();
    
    
    // Rects can talk.
    ofSetColor(255);
    // Check if mouse is surrounded.
    for (int i = 0; i < numRects; i++) {
        if (ofDist(myRects[i].pos.x, myRects[i].pos.y, mouseX, mouseY) > offset*1.45) {
            surrounded = false;
            break; // If a rect is too far away, start the loop over.
        }
        else if (i == numRects-1) surrounded = true; // If i gets to the last value, consider the mouse surrounded.
    }
    // Mouse is surrounded.
    if (surrounded) ofDrawBitmapString("We have you surrounded!", ofPoint(myRects[1].pos.x-90, myRects[1].pos.y-50));
    // Chase the mouse.
    else {
        ofDrawBitmapString("S/he's getting away! After, er, 'them'!", ofPoint(myRects[1].pos.x-90, myRects[1].pos.y-50));
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == 'r') {
        myRects.clear(); // Empty the vector before re-running setup.
        setup(); // Reset
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
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
