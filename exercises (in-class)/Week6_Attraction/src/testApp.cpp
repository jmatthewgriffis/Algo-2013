#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync( true );
    ofSetFrameRate( 60 );
    
    earth.pos = ofGetWindowSize() / 2;
    earth.mass = 2;
    
    moon.mass = 0.5;
    moon.pos = ofVec2f( 100, 300 );
}

//--------------------------------------------------------------
void testApp::update(){

    ofVec2f pull = earth.attract( moon );
    
    moon.applyForce( pull );
    moon.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    earth.draw();
    moon.draw();
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
