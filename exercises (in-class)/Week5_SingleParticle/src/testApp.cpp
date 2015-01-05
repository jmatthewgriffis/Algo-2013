#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(255);
    
    //    myParticle.setParams(300, 300, ofRandom(-1, 1), ofRandom(-1, 1));
    
    for (int i = 0; i < 1000; i++) {
        addParticle();
    }
    
}

void testApp::addParticle() {
    Particle tmpParticle;
    
    float vx = ofRandom(-4, 4);
    float vy = ofRandom(-4, 4);
    
    tmpParticle.setParams(300, 300, vx, vy);
    
    particleList.push_back(tmpParticle);
}

//--------------------------------------------------------------
void testApp::update(){
    
    /*
     myParticle.resetForces();
     myParticle.addForce( ofVec2f(0, 0.1) );
     myParticle.addDampingForce();
     myParticle.update();
     */
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].resetForces();
        particleList[i].addForce( ofVec2f(0, 0.1) );
        particleList[i].addDampingForce();
        particleList[i].update();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //    myParticle.draw();
    
    for (int i = 0; i < particleList.size(); i++) {
        particleList[i].draw();
    }
    
    /*
     // Doing iterators in C++ 11 is easier.
     for (auto p : particleList ) {
     p.draw();
     }
     */
    
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
    
//    myParticle.setParams(x, y, ofRandom(-1, 1)*10, ofRandom(-1, 1)*10);
    
    for (int i = 0; i < particleList.size(); i++) {
        
//        float vx = ofRandom(-4, 4);
//        float vy = ofRandom(-4, 4);
        
        float circVal = ofRandom(TWO_PI);
        
        float vx = cos (circVal) * ofRandom(0, 4);
        float vy = sin (circVal) * ofRandom(0, 4);
        
        particleList[i].setParams(x, y, vx, vy);
        
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
