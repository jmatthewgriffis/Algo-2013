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
    friction = 0.7;
    onGround = false;

}

//--------------------------------------------------------------
void testApp::update(){
    
    // If the ball reaches the "ground," prevent it from moving lower and note that it's on the ground.
    if (pos.y >= ofGetWindowHeight()-groundOffset-rad) {
        onGround = true;
        pos.y = ofGetWindowHeight()-groundOffset-rad;
        vel *= -friction; // Bounce and lose some force to friction.
    }
    else onGround = false;
    
    vel += gravity; // Modify the velocity every frame by gravity.
    pos.y += vel; // And modify the position every frame by the velocity.
    
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    
    // Draw the ball.
    ofCircle(pos, rad);
    
    // Draw the ground.
    ofLine(0, ofGetWindowHeight()-groundOffset, ofGetWindowWidth(), ofGetWindowHeight()-groundOffset);
    
    // Debug--draw the velocity.
    ofDrawBitmapStringHighlight("vel = " + ofToString(vel), ofPoint(10,10));
    
    // Explain gravity controls.
    ofDrawBitmapStringHighlight("gravity = " + ofToString(gravity*60) + " meters per second | use UP and DOWN to change the gravity. | CLICK to launch the stopped ball.", ofPoint(100, ofGetWindowHeight()-10));

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    // Reset
    if (key == 'r') setup();
    if (key == OF_KEY_UP) gravity += (0.1/60);
    if (key == OF_KEY_DOWN) gravity -= (0.1/60);
    
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

    if (onGround) vel = ofRandom(-20, -5); // Must be still.
    
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
