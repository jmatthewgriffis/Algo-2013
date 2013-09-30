//
//  Particle.cpp
//  Week5_Particles_with_GUI
//
//  Created by J. Matthew Griffis on 9/29/13.
//
//

#include "Particle.h"

Particle::Particle() {
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    speed = 2;
    wide = 10;
    tall = wide;
    
}

void Particle::setup() {
    
    pos.x = ofRandom(0, ofGetScreenWidth());
    pos.y = ofRandom(0, ofGetScreenHeight());
    
    vel.x = ofRandom(-1, 1) * speed;
    vel.y = ofRandom(-1, 1) * speed;
    
}

void Particle::update() {
    
    pos += vel; // Move the particle.
    
    // If the particle goes offscreen, Pac-Man it to the other side:
    if (pos.x < 0) {
        pos.x = ofGetScreenWidth();
    }
    else if (pos.x > ofGetScreenWidth()) {
        pos.x = 0;
    }
    if (pos.y < 0) {
        pos.y = ofGetScreenHeight();
    }
    else if (pos.y > ofGetScreenHeight()) {
        pos.y = 0;
    }
    
    // Change the velocity every once in a while:
    if (ofRandom(1) < 0.01) {
        vel.x = ofRandom(-1, 1) * speed;
    }
    if (ofRandom(1) < 0.01) {
        vel.y = ofRandom(-1, 1) * speed;
    }
    
}

void Particle::draw() {
    
    ofPushMatrix();{
        ofSetColor(255);
        ofTranslate(pos);
        ofRect(0, 0, wide, tall);
    }ofPopMatrix();
}