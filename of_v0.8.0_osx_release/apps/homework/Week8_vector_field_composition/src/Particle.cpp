//
//  Particle.cpp
//  Forces
//
//  Created by Charlie Whitney on 9/30/13.
//
//

#include "Particle.h"

Particle::Particle() {
    mass = 1.0;
    
    c = ofColor( int( ofRandom( 0, 255 ) ),  int( ofRandom( 0, 255 ) ),  int( ofRandom( 0, 255 ) ));
}

void Particle::applyForce(ofVec2f force){
    accel += (force / mass);
}

void Particle::update(){
    vel += accel;
    pos += vel;
    
    vel*= 0.97;
    
    accel.set(0);
    
    // If particles go off-screen, "Pac-Man" warp to the other side.
    
    if ( pos.x < 0 ) pos.x = ofGetWidth();
    if ( pos.x > ofGetWidth() ) pos.x = 0;
    
    if ( pos.y < 0 ) pos.y = ofGetHeight();
    if ( pos.y > ofGetHeight() ) pos.y = 0;
}

void Particle::draw() {
    
    ofSetColor( c );
    ofCircle( pos, 4 );
}