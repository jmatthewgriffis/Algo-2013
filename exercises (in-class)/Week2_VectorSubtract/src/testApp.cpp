#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
    ofSetFrameRate(60); // 60 is good for installations; 30 is good for web.
    ofBackground(100);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofVec2f result;
    
    // Cool trick. Use brackets outside of a function context to trick the IDE into automatically indenting what's inside. It doesn't affect the compiler (which is smart enough to tell the difference between this and a function).
    ofPushMatrix();{
        
        ofTranslate(ofGetWindowSize()/2); // Tech note: openGL does translation before rotation, even if the rotate command comes earlier in the code. DOUBLE-CHECK THIS.
        
        ofVec2f mousePos(mouseX, mouseY);
        ofVec2f center = ofGetWindowSize()/2; // Another cool trick. ofGetWindowSize() returns an ofPoint, i.e. with x AND y.
        
        result = mousePos - center;
        // Can get a lot of control by normalizing the vector and then multiplying it by a set magnitude.
        result.normalize(); // Convert the vector into a "unit vector."
        result *= 50.0;
        
        ofLine( ofVec2f(0,0), result);
        
    }ofPopMatrix();
    
    float mag = result.length();
    
    ofDrawBitmapStringHighlight(ofToString(mag), ofPoint(20,20))
    ;
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
