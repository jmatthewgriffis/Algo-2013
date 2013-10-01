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
        particleList[i].update();
    }
    
    // Limit vector size.
    if (particleList.size() > 4) {
        particleList.erase(particleList.begin(), particleList.begin()+3);
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
    
    for (int i = 0; i < numParticles; i++) {
        
        // Calculate the angle for particle generation.
        float dx = mouseX - ofGetWindowWidth()/2;
        float dy = mouseY - ofGetWindowHeight()/2;
        ofVec2f vec = ofVec2f( dx,dy );
        
//        angle = - ofRadToDeg(atan2( dy, dx )); // Right.
        angle = 90 - ofRadToDeg(atan2( dy, dx )); // Top.
//        angle = 180 - ofRadToDeg(atan2( dy, dx )); // Left.
//        angle = 270 - ofRadToDeg(atan2( dy, dx )); // Bottom.
        
        // Make a particle and add it to the vector.
        Particle tmp;
        tmp.setup(angle, vec, i);
        particleList.push_back(tmp);
        
    }
    
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
