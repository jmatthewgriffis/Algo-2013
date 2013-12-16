#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // Maintenance
    ofSetVerticalSync( true );
    ofSetFrameRate( 60 );
    ofBackground( 0 );
    
    myBox.setup();
    vel = 15.0;
    yPos = ofGetHeight() - myBox.tall / 2;
    allowChange = scoochMode = true;
    squish = false;
    myBox.pos.y = yPos;
    myBox.pos.x = - 150;
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
    
    if ( myBox.pos.y <= ofGetHeight() - 50 - 200 * 3 && myBox.pos.x <= ofGetWidth() / 2 ) {
        scoochMode = false;
    }
    
    if ( scoochMode ) {
        if ( ofGetElapsedTimeMillis() % 50 == 0 ) {
//            if ( myBox.allowScooch ) {
                myBox.anticipation( ofVec2f( vel, 0.0 ) );
                myBox.allowScooch = false;
//            }
        }
    } else {
        if ( yPos < ofGetHeight() - myBox.tall * 0.5 ) {
            myBox.acc.set( 0.0, 2 );
        } else {
            myBox.acc.set( 0 );
            myBox.vel.set( 0 );
        }
    }
    
    if ( myBox.pos.y > ofGetHeight() - myBox.tall / 2 ) {
        myBox.pos.y = ofGetHeight() - myBox.tall / 2;
        squish = true;
    }
    
    if ( squish ) {
        if ( myBox.tall > 1 ) {
            myBox.tall--;
            myBox.wide++;
        } else {
            setup();
        }
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
