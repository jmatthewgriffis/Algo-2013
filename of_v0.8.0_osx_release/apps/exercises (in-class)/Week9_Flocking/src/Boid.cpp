//
//  Boid.cpp
//  Week9_Flocking
//
//  Created by J. Matthew Griffis on 10/22/13.
//
//

#include "Boid.h"

Boid::Boid() {
    
    damping = ofRandom( 0.95, 0.99 );
}

void Boid::applyForce( ofVec3f force ) {
    
    acc += force;
}

void Boid::pullToCenter( ofVec3f center ) {
    
}

void Boid::update() {
    
    vel += acc;
    pos += vel;
    
    acc.set( 0 );
}

void Boid::draw() {
    
}