//
//  Particle.cpp
//  Week6_AttractionRepulsion
//
//  Created by J. Matthew Griffis on 10/1/13.
//
//

#include "Particle.h"

Particle::Particle() {
    
    damping = 0.95;
}

void Particle::addForce( ofVec2f force ) {
    
    acc += force;
}

void Particle::addRepulsionForce( float px, float py, float radius, float strength ) {
    
    ofVec2f posOfForce;
    posOfForce.set( px, py );
    
    ofVec2f diff = pos - posOfForce;
    
    if ( diff.length() < radius ) {
        
        float pct = 1 - ( diff.length() / radius );
        diff.normalize();
        
        acc.x += diff.x * pct * strength;
        acc.y += diff.y * pct * strength;
    }
}

void Particle::addAttractionForce( float px, float py, float radius, float strength ) {
    
    ofVec2f posOfForce;
    posOfForce.set( px, py );
    
    ofVec2f diff = pos - posOfForce;
    
    if ( diff.length() < radius ) {
        
        float pct = 1 - ( diff.length() / radius );
        diff.normalize();
        
        acc.x -= diff.x * pct * strength;
        acc.y -= diff.y * pct * strength;
    }
}

void Particle::update() {
    vel += acc;
    pos += vel;
    
    vel *= damping;
    
    acc.set( 0 );
}

void Particle::draw() {
    ofCircle( pos, 4 );
}