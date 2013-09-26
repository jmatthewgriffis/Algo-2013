//
//  Particle.cpp
//  Week5_SingleParticle
//
//  Created by J. Matthew Griffis on 9/24/13.
//
//

#include "Particle.h"

Particle::Particle() {
    
    setParams(0, 0, 0, 0);
    damping.set(0.01,0.01);
//    damping = ofVec2f(0,0); // This is the same as the above line, except this version creates a new instance of an ofVec2f. It's not an issue because at the end of the function the new instance falls out of scope and is deleted, but we can also just avoid the phenomenon entirely by using the other version.
}

void Particle::setParams(float px, float py, float vx, float vy) {
    
    pos.set(px, py);
    vel.set(vx, vy);
}

void Particle::addForce(ofVec2f force) {
    frc += force;
}

void Particle::resetForces() {
    frc.set(0,0);
}

void Particle::addDampingForce() {
    frc = frc - vel * damping;
}

void Particle::update() {
    vel += frc;
    pos += vel;
}

void Particle::draw() {
    ofSetColor(255, 0, 255);
    ofCircle( pos.x, pos.y, 3 );
}