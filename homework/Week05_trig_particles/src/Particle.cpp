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

void Particle::setup( float _angle, ofVec2f _vec, int _i ) {
    
    vec = _vec;
    
    pos = ofGetWindowSize()/2;
    c = ofColor(255);
    wide = 20;
    tall = wide*1.5;
    
    // MOTION
    minAngle = _angle;
    angle = minAngle;
    angleDiff = int(ofRandom( 45, 135 ));
    rotateRad = 50;
    rotateVel = 3;
    incRad = ofRandom( 1, 20 );
    
    // Even-numbered elements go one way, odd, the other.
    if ( ( _i + 2 ) % 2 == 0 ) {
        rotateVel *= -1;
        maxAngle = angle - angleDiff;
    }else {
        maxAngle = angle + angleDiff;
    }
    
}

void Particle::update() {

    if ( ( rotateVel > 0 && angle + rotateVel <= maxAngle ) || ( rotateVel < 0 && angle + rotateVel >= maxAngle ) ) {
        angle += rotateVel;
        float diff = abs(angle - maxAngle);
        if (diff >= angleDiff/2) rotateRad += incRad;
        else rotateRad -= incRad;
    }
    
    pos.x = sin(ofDegToRad(angle)) * rotateRad;
    pos.y = cos(ofDegToRad(angle)) * rotateRad;
    
}

void Particle::draw() {
    
//    ofCircle( ofGetWindowSize()/2 - vec.normalize() * 100 , 10); // Debug.
    
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
