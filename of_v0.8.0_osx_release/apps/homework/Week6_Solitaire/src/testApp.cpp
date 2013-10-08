#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync( true );
    ofSetFrameRate( 60 );
    ofBackground( 0, 130, 0 );
    ofSetBackgroundAuto( false );
    
    myCard.setup();
    
    // Set the positions for the deck and the four suits:
    float yPos = myCard.tall;
    posDeck = ofVec2f( 100, yPos );
    posClub = ofVec2f( ofGetWindowWidth() - 100, yPos );
    posSpade = ofVec2f( posClub.x - 100, yPos );
    posHeart = ofVec2f( posSpade.x - 100, yPos );
    posDiamond = ofVec2f( posHeart.x - 100, yPos );

}

//--------------------------------------------------------------
void testApp::drawCardPos(){
    
    ofNoFill();
    ofSetColor( 0 );
    ofRect( posDeck, myCard.wide, myCard.tall );
    ofSetColor( 0, 255, 0 );
    ofCircle( posDeck, myCard.wide / 3 );
    
    ofNoFill();
    ofSetColor( 0 );
    ofRect( posDiamond, myCard.wide, myCard.tall );
    ofSetColor( 0, 255, 0 );
    ofCircle( posDiamond, myCard.wide / 3 );
    
    ofNoFill();
    ofSetColor( 0 );
    ofRect( posHeart, myCard.wide, myCard.tall );
    ofSetColor( 0, 255, 0 );
    ofCircle( posHeart, myCard.wide / 3 );
    
    ofNoFill();
    ofSetColor( 0 );
    ofRect( posSpade, myCard.wide, myCard.tall );
    ofSetColor( 0, 255, 0 );
    ofCircle( posSpade, myCard.wide / 3 );
    
    ofNoFill();
    ofSetColor( 0 );
    ofRect( posClub, myCard.wide, myCard.tall );
    ofSetColor( 0, 255, 0 );
    ofCircle( posClub, myCard.wide / 3 );
    
}

//--------------------------------------------------------------
void testApp::update(){

    myCard.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    drawCardPos();
    myCard.draw();
    
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
