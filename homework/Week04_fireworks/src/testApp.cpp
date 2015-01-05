#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    // make 50 particles up front!
    for( int i=0; i<50; i++ ){
        addParticle(ofGetWindowSize()/2);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    // This is how you loop through and delete a particle using iterators and vectors
    // Note how we don't put it++ up in the top of the loop.
    for( vector<Particle>::iterator it=pList.begin(); it!=pList.end(); ){
        it->update();
        
        if( it->bIsDead ){
            it = pList.erase(it);   // When we erase one, it returns the next particle automatically.  It's done the "it++" for us!
            ofLog( OF_LOG_NOTICE, "size is " + ofToString(pList.size()) );
        }else {
            it++;
        }
        
        // When the current batch of fireworks runs out, spawn a new batch at the location of the last firework.
        if (pList.size() <= 1) {
            for( int i=0; i<50; i++ ){
                if (it->pos.x > 0 && it->pos.x < ofGetWindowWidth() && it->pos.y > 0 && it->pos.y < ofGetWindowHeight()) {
                    addParticle(it->pos);
                }else {
                    addParticle(ofGetWindowSize()/2); // If the pos is offscreen, relocate to the center of the screen.
                }
            }
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for( vector<Particle>::iterator it = pList.begin(); it!=pList.end(); it++){
        it->draw();
    }
}

void testApp::addParticle(ofPoint pos){
    Particle p;
    
    // we'll pick a random direction for our particle to move initially
    ofVec2f rVel = ofVec2f( ofRandom(1.0), ofRandom(1.0) ) * 10.0 - 5.0;
    p.setup( rVel );
    p.pos.x = pos.x;
    p.pos.y = pos.y;
    pList.push_back( p );
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
    
    // add 50 more particles on click!
    /*for( int i=0; i<50; i++ ){
        addParticle(ofGetWindowSize()/2);
    }*/
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
