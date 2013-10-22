#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSeedRandom();

    ofSetVerticalSync(true);
    ofSetFrameRate(60);

    // Blue car.
    car_blue.setParams( ofVec2f( ofRandomWidth(), ofRandomHeight() ), ofVec2f( 10, -5 ) );
    dest_blue = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    
    // Red car.
    car_red.setParams( ofVec2f( ofRandomWidth(), ofRandomHeight() ), ofVec2f( 10, -5 ) );
    dest_red = ofVec2f( ofRandomWidth(), ofRandomHeight() );

    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){

    car_blue.seek( dest_blue );
    car_blue.update();
    
    car_red.seek( dest_red );
    car_red.update();

    // I didn't know this was a method for distance; cool!
    if( car_blue.pos.distance(dest_blue) < 5){
        dest_blue = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car_red.pos.distance(dest_red) < 5){
        dest_red = ofVec2f( ofRandomWidth(), ofRandomHeight() );
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor( 0, 0, 255 );
    car_blue.draw();
    
    ofSetColor( 255, 0, 0 );
    car_red.draw();

    ofSetColor(0,0,255);
    ofCircle( dest_blue, 4 );
    
    ofSetColor(255,0,0);
    ofCircle( dest_red, 4 );
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    // reset
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
