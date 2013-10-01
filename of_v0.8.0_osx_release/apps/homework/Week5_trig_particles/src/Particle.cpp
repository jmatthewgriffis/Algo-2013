//
//  Particle.cpp
//  Week5_trig_particles
//
//  Created by J. Matthew Griffis on 9/30/13.
//
//

#include "Particle.h"

Particle::Particle() {
    
}

void Particle::setup() {
    
    pos = ofGetWindowSize()/2;
    c = ofColor(255);
    wide = 20;
    tall = wide*1.5;
    
    // Motion
    minAngle = 90;
    maxAngle = 180;
    angle = 90;
    rotateRad = 50;
    rotateVel = 3;
    incRad = 5;
    
}

void Particle::update(float _angle) {

    angle += rotateVel;
    if (angle > maxAngle) angle = maxAngle;
    else rotateRad += incRad;
    
    pos.x = sin(ofDegToRad(angle)) * rotateRad;
    pos.y = cos(ofDegToRad(angle)) * rotateRad;
    
}

void Particle::draw() {
    
    ofPushMatrix();{
        ofSetColor( c );
        ofTranslate( ofGetWindowSize()/2 );
        ofBeginShape();{ // Draw a diamond.
            ofVertex( pos.x, pos.y-tall/2 ); // Top
            ofVertex( pos.x-wide/2, pos.y ); // Left
            ofVertex( pos.x, pos.y+tall/2 ); // Bottom
            ofVertex( pos.x+wide/2, pos.y ); // Right
        }ofEndShape();
    }ofPopMatrix();
}
