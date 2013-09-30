#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    ofEnableAlphaBlending();
    
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
        particleList[i].c = ofColor(0,0,255);
    }
    
    // "Collision detection" between the particles:
    for (int i = 0; i < particleList.size(); i++) {
        for (int j = 0; j < particleList.size(); j++) {
            // Prevent a particle from checking against itself.
            if (i != j) {
                // If particles get close enough...
                float dist = (particleList[i].pos - particleList[j].pos).length();
                if (dist < particleList[i].soClose) {
                    particleList[i].randomMove = false;
                    float pct = 0.03;
                    // If particle is attracted...
                    if (particleList[i].behavior == 1) {
                        particleList[i].c = ofColor(0,255,0);
                        // Move toward and follow the other particle.
                        particleList[i].pos = (1-pct)*particleList[i].pos + pct*particleList[j].pos;
//                        particleList[i].claustrophobe = true; // Increased likelihood to become repelled.
                    }else if (particleList[i].behavior == 2) { // Repelled?
                        particleList[i].c = ofColor(255,0,0);
                        //particleList[i].pos -= (1-pct)*particleList[j].pos - pct*particleList[i].pos; // Uncomment this for a cool effect when you hold the restart button.
                        particleList[i].pos += (particleList[i].soClose-dist);
                    }
                }else {
                    particleList[i].randomMove = true;
                }
            }
        }
        particleList[i].update();
        particleList[i].c.a = 255*(0.8);
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
