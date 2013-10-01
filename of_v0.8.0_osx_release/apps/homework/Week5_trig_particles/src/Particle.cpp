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

void Particle::setup( float _angle, ofVec2f _vec ) {
    
    vec = _vec;
    
    pos = ofGetWindowSize()/2;
    c = ofColor(255);
    wide = 20;
    tall = wide*1.5;
    
    // Motion
    minAngle = _angle;
    maxAngle = minAngle + 90;
    angle = minAngle;
    rotateRad = 50;
    rotateVel = 3;
    incRad = 5;
    
}

void Particle::update() {

    if (angle != maxAngle) {
        angle += rotateVel;
        rotateRad += incRad;
    }
    
    pos.x = sin(ofDegToRad(angle)) * rotateRad;
    pos.y = cos(ofDegToRad(angle)) * rotateRad;
    
}

void Particle::draw() {
    
    ofCircle( ofGetWindowSize()/2 - vec.normalize() * 100 , 10);
    
    ofPushMatrix();{
        ofSetColor( c );
        ofTranslate( ofGetWindowSize()/2 - vec.normalize() * 100 );
        ofBeginShape();{ // Draw a diamond.
            ofVertex( pos.x, pos.y-tall/2 ); // Top
            ofVertex( pos.x-wide/2, pos.y ); // Left
            ofVertex( pos.x, pos.y+tall/2 ); // Bottom
            ofVertex( pos.x+wide/2, pos.y ); // Right
        }ofEndShape();
    }ofPopMatrix();
}
