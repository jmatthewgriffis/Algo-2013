#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    // The usual oF setup stuff.
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    
}

//--------------------------------------------------------------
void testApp::update(){

    // Update the particles.
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].update(angle);
    }
    
    // Limit vector size.
    if (particleList.size() > 3) {
        particleList.erase(particleList.begin());
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){

    // Draw the particles.
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].draw();
    }
    
    // Draw a line from the center to the mouse.
    ofLine(ofGetWindowSize()/2, ofPoint(mouseX, mouseY));
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    // Reset button.
    if (key == 'r') {
        particleList.clear();
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
    
    // Calculate the angle for particle generation.
    float dx = mouseX - ofGetWindowWidth()/2;
    float dy = mouseY - ofGetWindowHeight()/2;
    angle = atan2( dy, dx );
    
    // Make a particle and add it to the vector.
    Particle tmp;
    tmp.setup();
    particleList.push_back(tmp);

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
