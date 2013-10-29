//
//  Box.cpp
//  Week9_the_principles_12
//
//  Created by J. Matthew Griffis on 10/28/13.
//
//

#include "Box.h"

Box::Box() {
    
    friction = 0.97;
}

void Box::setup() {
    
    pos.set( ofGetWindowSize() / 2 );
    vel.set( 0, 0 );
    acc.set( 0 );
}

void Box::update() {
    
    vel += acc;
    pos += vel;
    
    vel *= friction;
    float minSpeed = 0.02;
    if ( vel.lengthSquared() < minSpeed * minSpeed ) {
        vel.set( 0 );
    }
    
    acc.set( 0 );
}

void Box::draw() {
    
    ofSetColor( 120, 120, 120 );
    ofSetRectMode( OF_RECTMODE_CENTER );
    ofRect( pos, 100, 100 );
}

void Box::applyForce( ofVec2f force ) {
    
    anticipation( force );
    
    if ( vel == ofVec2f( 0, 0 ) ) {
        acc += force;
    }
}

void Box::anticipation( ofVec2f force ) {
    
    acc -= force / 5;
}