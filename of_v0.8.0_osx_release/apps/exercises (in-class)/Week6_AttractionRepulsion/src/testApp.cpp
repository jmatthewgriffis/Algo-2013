#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync( true );

    for ( int i = 0; i < 1000; i++ ) {
        Particle myParticle;
        
        ofVec2f newPos( ofRandomWidth(), ofRandomHeight() );
        
        myParticle.pos = newPos;
        
        particleList.push_back( myParticle );
    }
    
    ofBackground( 0 );
}

//--------------------------------------------------------------
void testApp::update(){

    for ( int i = 0; i < particleList.size(); i++ ) {
        
        particleList[i].addAttractionForce( mouseX, mouseY, 1000, 0.1 );
        particleList[i].addRepulsionForce( mouseX, mouseY, 60, 1 );
        
        particleList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    for ( int i = 0; i < particleList.size(); i++ ) {
        particleList[i].draw();
    }
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
