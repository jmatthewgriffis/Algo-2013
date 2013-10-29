#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // Maintenance
    ofSetVerticalSync( true );
    ofSetFrameRate( 60 );
    ofBackground( 0 );
    
    vel = 15.0;
    yPos = ofGetHeight() - 50;
    allowChange = true;
    
    myBox.setup();
    myBox.pos.y = yPos;
    myBox.pos.x = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    
    if ( myBox.pos.x < -200 || myBox.pos.x > ofGetWidth() + 200 ) {
        if ( allowChange ) {
            vel *= -1;
            yPos -= 200;
            myBox.pos.y = yPos;
            allowChange = false;
        }
    } else if ( myBox.pos.x > 100 && myBox.pos.x < ofGetWidth() - 100 ) {
        allowChange = true;
    }
    
    if ( ofGetElapsedTimeMillis() % 50 == 0 ) {
        myBox.anticipation( ofVec2f( vel, 0.0 ) );
    }
    myBox.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    myBox.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if ( key == 'r' ) {
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
