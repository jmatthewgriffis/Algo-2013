//
//  Box.cpp
//  Week9_the_principles_12
//
//  Created by J. Matthew Griffis on 10/28/13.
//
//

#include "Box.h"

Box::Box() {
    
    friction = 0.8;
}

void Box::setup() {
    
    pos.set( ofGetWindowSize() / 2 );
    vel.set( 0, 0 );
    acc.set( 0 );
    force.set( 0 );
    allowScooch = true;
}

void Box::update() {
    
    vel += acc;
    pos += vel;
    
    vel *= friction;
    float minSpeed = 0.2;
    if ( vel.lengthSquared() < minSpeed * minSpeed ) {
        vel.set( 0 );
        allowScooch = true;
    }
    
    acc.set( 0 );
    
    if ( vel.lengthSquared() == 0 && force.lengthSquared() != 0 ) {
        applyForce( force );
    }
}

void Box::draw() {
    
    ofSetColor( 120, 120, 120 );
    ofSetRectMode( OF_RECTMODE_CENTER );
    ofRect( pos, 100, 100 );
}

void Box::applyForce( ofVec2f _force ) {
    
    acc += _force;
    force.set( 0 );
}

void Box::anticipation( ofVec2f _force ) {
    
    acc -= _force * 0.25;
    force.set( _force );
}