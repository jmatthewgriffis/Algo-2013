#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    /*
     Hooke's law:
     F = -k * x;
     k is a constant, the "springiness" of the spring.
     */
    
    ofSetVerticalSync( true );
    ofSetFrameRate( 60 );
    ofBackground( 0 );
    
    k = 0.05;
    restLength = 200.0;
    
    anchor = ofVec2f( ofGetWindowWidth() / 2.0, 10 );
    handle = ofVec2f( ofGetWindowWidth() / 2.0, restLength + 100 + 10 );
    
    bIsDragging = false;
}

//--------------------------------------------------------------
void testApp::update(){
    
    if ( bIsDragging ) {
        return;
    }
    
    ofVec2f force = handle - anchor;
    float len = force.length();
    float stretchLen = len - restLength;
    
    force.normalize();
    force *= -1 * k * stretchLen;
    
    applyForce( force );
    applyForce( ofVec2f( 0, 1.0 ) );
    
    // Do physics stuff
    vel += acc;
    vel *= 0.95; // damping
    
    handle += vel;
    
    acc.set( 0 );
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofLine( anchor, handle );
    
    ofCircle( anchor, 10 );
    ofCircle( handle, 20 );
}

//--------------------------------------------------------------
void testApp::applyForce( ofVec2f _force ) {

    acc += _force;
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
    
    if ( bIsDragging ) {
        handle.set( x, y );
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    if ( ofVec2f( x, y ).distance( handle ) < 20 ) {
        handle.set( x, y );
        vel.set( 0 );
        bIsDragging = true;
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    bIsDragging = false;
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
