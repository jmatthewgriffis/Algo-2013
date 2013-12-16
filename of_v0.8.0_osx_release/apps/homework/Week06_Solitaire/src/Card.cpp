//
//  Card.cpp
//  Week6_Solitaire
//
//  Created by J. Matthew Griffis on 10/7/13.
//
//

#include "Card.h"

//------------------
Card::Card() {
    
}

//------------------
void Card::setup() {
    
    pos.x = 400;
    pos.y = 100;
    vel.x = ofRandom( -4, -1 );
    vel.y = ofRandom( 0, -5 );
    accel.x = accel.y = 0;
    
    c = ofColor( 255 );
    
    wide = 75.0;
    tall = wide * 1.25f;
    
}

//------------------
void Card::applyForce( ofVec2f force ) {
    
    accel += force;
    
}

//------------------
void Card::gravity() {
    
    applyForce( ofVec2f( 0.0, 0.1 ));
    
}

//------------------
void Card::update() {
    
    gravity();
    
    vel += accel;
    pos += vel;
    
    if( pos.y > ofGetWindowHeight() - ( tall / 2 ) ){
        vel.y *= -0.8;
    }
    
    accel.set(0);
    
}

//------------------
void Card::draw() {
    
    ofSetRectMode( OF_RECTMODE_CENTER );
    ofFill();
    ofSetColor( c );
    ofRect( pos, wide, tall );
    ofNoFill();
    ofSetColor( 0 );
    ofRect( pos, wide, tall );
    
}

//------------------