//
//  Particle.cpp
//  Week6_Forces
//
//  Created by J. Matthew Griffis on 10/1/13.
//
//

#include "Particle.h"

Particle::Particle() {
    
    mass = 1.0f;
    pos = ofGetWindowSize() / 2;
}

Particle::Particle( ofVec2f position ) {
    
    mass = 1.0f;
    pos = position;
}

void Particle::applyForce( ofVec2f force ) {
    
    acc += ( force / mass );
}

void Particle::update() {
    
    vel += acc;
    pos += vel;
    
    // Bounce off the walls.
    if ( pos.x < 0 || pos.x < ofGetScreenWidth() ) {
        
        vel.x *= -1;
    }
    if ( pos.y < 0 || pos.y < ofGetScreenHeight() ) {
        
        vel.y *= -1;
    }
    
    acc.set( 0 );
}

void Particle::draw() {
    
    ofCircle( pos, mass * 10.0f );
}