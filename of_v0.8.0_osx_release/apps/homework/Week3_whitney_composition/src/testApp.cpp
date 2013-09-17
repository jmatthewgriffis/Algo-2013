#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    
    rectOffset = 10;
    
    // Create a vector of 9 rects, arranged in a 3 x 3 grid which is centered.
    for (int i = 0; i < numRects; i++) {
        Rectangle tmpRect;
        if (i < 3) {
            tmpRect.pos.x = rectOffset * (i+1) + tmpRect.wide * i + tmpRect.wide/2;
            tmpRect.pos.y = rectOffset + tmpRect.tall/2;
        }
        else if (i < 6) {
            tmpRect.pos.x = rectOffset * (i-2) + tmpRect.wide * (i-3) + tmpRect.wide/2;
            tmpRect.pos.y = rectOffset * 2 + tmpRect.tall * 1.5;
        }
        else {
            tmpRect.pos.x = rectOffset * (i-5) + tmpRect.wide * (i-6) + tmpRect.wide/2;
            tmpRect.pos.y = rectOffset * 3 + tmpRect.tall * 2.5;
        }
        rectList.push_back(tmpRect);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < rectList.size(); i++) {
        
        rectList[i].wide--; // Shrink the rects.
        rectList[i].tall = rectList[i].wide * 0.75; // Keep them proportional.
        
        // Need to recalculate the pos as per setup to keep rects centered.
        if (i < 3) {
            rectList[i].pos.x = rectOffset * (i+1) + rectList[i].wide * i + rectList[i].wide/2;
            rectList[i].pos.y = rectOffset + rectList[i].tall/2;
        }
        else if (i < 6) {
            rectList[i].pos.x = rectOffset * (i-2) + rectList[i].wide * (i-3) + rectList[i].wide/2;
            rectList[i].pos.y = rectOffset * 2 + rectList[i].tall * 1.5;
        }
        else {
            rectList[i].pos.x = rectOffset * (i-5) + rectList[i].wide * (i-6) + rectList[i].wide/2;
            rectList[i].pos.y = rectOffset * 3 + rectList[i].tall * 2.5;
        }
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPushMatrix();{
        
        ofTranslate(ofGetWindowWidth()/2 - rectList[0].wide * 1.5 - rectOffset * 2, ofGetWindowHeight()/2 - rectList[0].tall * 1.5 - rectOffset * 2);
        
        for (int i = 0; i < rectList.size(); i++) {
            rectList[i].draw();
        }
        
    }ofPopMatrix();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == 'r') {
        rectList.clear();
        setup();
    }
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
