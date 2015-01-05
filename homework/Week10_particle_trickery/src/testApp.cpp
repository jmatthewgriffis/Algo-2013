#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    pos = ofGetWindowSize() / 2;
    pos_2 = ofGetWindowSize() / 2;
//    vel.set( 20, 10, 0 );
    vel.set( 5, 7, 0 );
    vel_2.set( -3, 10, 0 );
    
    mFbo.allocate( ofGetWindowWidth(), ofGetWindowHeight() );
    mFbo2.allocate( ofGetWindowWidth(), ofGetWindowHeight() );
    
    ofBackground(0);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
    pos += vel;
    pos_2 -= vel_2;
    
    if ( ofRandom( 1 ) < 0.01 ) {
        vel.x *= -1;
    }
    if ( ofRandom( 1 ) < 0.01 ) {
        vel.y *= -1;
    }
    if ( ofRandom( 1 ) < 0.01 ) {
        vel_2.x *= -1;
    }
    if ( ofRandom( 1 ) < 0.01 ) {
        vel_2.y *= -1;
    }
    
    if( pos.x < 0 || pos.x > ofGetWindowWidth() ){
        vel.x *= -1;
    }
    
    if( pos.y < 0 || pos.y > ofGetWindowHeight() ){
        vel.y *= -1;
    }
    if( pos_2.x < 0 || pos_2.x > ofGetWindowWidth() ){
        vel_2.x *= -1;
    }
    
    if( pos_2.y < 0 || pos_2.y > ofGetWindowHeight() ){
        vel_2.y *= -1;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    mFbo.begin();
    
    // to prevent uncleared video memory!
    ofSetColor(255, 255, 255, 0);
    ofClear(255, 255, 255, 0);
    
    ofSetColor(255, 255, 255, 255);
    ofPushMatrix();{
        
        ofTranslate( pos );
         ofSetRectMode( OF_RECTMODE_CENTER );
        
//        for ( int i = 0; i < 4; i++ ) {
//            if ( i == 0 || i == 2 ) ofRotate( ofGetElapsedTimef() * 90 );
//            else ofRotate( ofGetElapsedTimef() * 180 );
//            ofRect( -50 * i, 50 * i, 50, 50 );
//        }
        
        for ( int i = 0; i < 50; i++ ) {
            if ( i % 2 == 0 ) ofRotate( ofGetElapsedTimef() * 90 );
            else ofRotate( ofGetElapsedTimef() * 180 );
            ofRect( -10 * i, 40 * i, 50, 50 );
        }
        
         ofSetRectMode( OF_RECTMODE_CORNER );
    }ofPopMatrix();
    mFbo.end();
    
    mFbo2.begin();
    
    // to prevent uncleared video memory!
    ofSetColor(255, 255, 255, 0);
    ofClear(255, 255, 255, 0);
    
    ofSetColor(255, 255, 255, 255);
    ofPushMatrix();{
        
        ofTranslate( pos_2 );
        ofSetRectMode( OF_RECTMODE_CENTER );
        
        for ( int i = 0; i < 50; i++ ) {
            if ( i % 2 == 0 ) ofRotate( -ofGetElapsedTimef() * 45 );
            else ofRotate( -ofGetElapsedTimef() * 135 );
            ofRect( -20 * i, 30 * i, 50, 50 );
        }
        
        ofSetRectMode( OF_RECTMODE_CORNER );
    }ofPopMatrix();
    mFbo2.end();
    
    mFbo.draw(0,0);
    mFbo.draw(0,200);
    mFbo.draw(200,200);
    mFbo.draw(200,0);
    
    mFbo2.draw(0,0);
    mFbo2.draw(0,200);
    mFbo2.draw(200,200);
    mFbo2.draw(200,0);
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
