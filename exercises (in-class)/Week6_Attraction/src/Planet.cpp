//
//  Planet.cpp
//  Week6_Attraction
//
//  Created by J. Matthew Griffis on 10/1/13.
//
//

#include "Planet.h"

Planet::Planet() {
    mass = 1.0f;
}

void Planet::applyForce( ofVec2f force ) {
    acc += ( force / mass );
}

void Planet::update() {
    vel += acc;
    pos += vel;
    
    acc.set( 0 );
}

ofVec2f Planet::attract( Planet p ) {
    ofVec2f forceDir = pos - p.pos;
    float dist = forceDir.length();
    forceDir.normalize();
    
    float pullStrength = ( G * mass * p.mass ) / ( dist * dist );
    
    return forceDir * pullStrength;
}

void Planet::draw() {
    ofCircle( pos, mass * 10.0 );
}