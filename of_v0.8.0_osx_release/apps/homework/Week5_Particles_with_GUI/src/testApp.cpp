#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    
    for (int i = 0; i < initParticles; i++) {
        addParticle();
    }

}

void testApp::addParticle() {
    
    Particle tmp;
    tmp.setup();
    particleList.push_back(tmp);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].update();
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].draw();
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
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
