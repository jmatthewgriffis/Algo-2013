#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync( true );
    ofSetFrameRate( 60 );
    ofBackground( 0 );
    
    // This gets box2d going.
    box2d.init();
    
    box2d.setGravity( 0, 10 );
    box2d.setFPS( 30.0 ); // How frequently the physics update.
//    box2d.createGround();
    box2d.createBounds();
    box2d.registerGrabbing();
    
    // Physics must be set before the setup.
    boxCircle.setPhysics( 1.0, 0.5, 1.0 );
    boxCircle.setup( box2d.getWorld(), 200, 200, 20 );
}

//--------------------------------------------------------------
void testApp::update(){

    box2d.update();
}

//--------------------------------------------------------------
void testApp::draw(){

    boxCircle.draw();
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
