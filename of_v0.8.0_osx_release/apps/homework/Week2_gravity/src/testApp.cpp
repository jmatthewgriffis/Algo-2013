#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    ofSetCircleResolution(60);
    ofSetVerticalSync(true);
    
    pos = ofPoint(ofGetWindowWidth()/2, 0);
    rad = 30;
    groundOffset = 20;
    vel = 0;
    gravity = (9.8/60); // Divide meters per second by 60 frames per second.
    onGround = false;

}

//--------------------------------------------------------------
void testApp::update(){
    
    // If the ball reaches the "ground," prevent it from moving lower and note that it's on the ground.
    if (pos.y >= ofGetWindowHeight()-groundOffset-rad) {
//        onGround = true;
        pos.y = ofGetWindowHeight()-groundOffset-rad;
        vel *= -0.9; // Bounce and lose some force to friction.
    }
//    else onGround = false;
    
    vel += gravity; // Modify the velocity every frame by gravity.
    pos.y += vel; // And modify the position every frame by the velocity.
        
//    if (onGround) vel = 0; // Set vel to zero if the ball is on the ground.
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    
    // Draw the ball.
    ofCircle(pos, rad);
    
    // Draw the ground.
    ofLine(0, ofGetWindowHeight()-groundOffset, ofGetWindowWidth(), ofGetWindowHeight()-groundOffset);
    
    // Debug--draw the velocity.
    ofDrawBitmapStringHighlight(ofToString(vel), ofPoint(10,10));

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    // Reset
    if (key == 'r') setup();
    
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

//    if (onGround) vel = -100;
    
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
