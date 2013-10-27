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
    
    // we'll come back to this, yo. i'm out.
}

void Boid::update() {
    
    float minSpeed = 1.0;
    
    vel += acc;
    
    // Max vel.
    vel.limit( 3.0 );
    
    // Min vel.
    // This first version uses a hidden and expensive square-root calculation.
    //if ( vel.length() < minSpeed ) {
    // This second version is optimized by removing the need for the square-root.
    if ( vel.lengthSquared() < minSpeed * minSpeed ) {
        vel = vel.normalized() * minSpeed;
    }
    
    pos += vel;
    vel *= damping;
    
    acc.set( 0 );
}

void Boid::draw() {
    
    ofSetColor( 255 );
    ofCircle( pos, 2 );
    
    ofSetColor( 0, 255, 0 );
    // When drawing a tail, use the velocity to determine which direction.
    ofLine( pos, pos - vel * 5.0 );
}