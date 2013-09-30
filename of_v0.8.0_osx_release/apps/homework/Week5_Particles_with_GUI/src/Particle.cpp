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
    //    angle = 0;
    wide = 40;
    tall = wide;
    randomMove = true;
    c = ofColor(255);
    
}

void Particle::setup() {
    
    //    pos = ofGetWindowSize()/2;
    
    pos.x = ofRandom(wide*2, ofGetScreenWidth()-wide*2);
    pos.y = ofRandom(tall*2, ofGetScreenHeight()-tall*2);
    
    vel.x = ofRandom(-1, 1) * speed;
    vel.y = ofRandom(-1, 1) * speed;
    
    if (ofRandom(1) > 0.5f) {
        attract = true;
    }else {
        attract = false;
    }
    
}

void Particle::update() {
    
    pos += vel; // Move the particle.
    
    // If the particle goes offscreen, Pac-Man it to the other side:
    if (pos.x < -wide/2) {
        pos.x = ofGetScreenWidth()+wide/2;
    }
    else if (pos.x > ofGetScreenWidth()+wide/2) {
        pos.x = -wide/2;
    }
    if (pos.y < -tall/2) {
        pos.y = ofGetScreenHeight()+tall/2;
    }
    else if (pos.y > ofGetScreenHeight()+tall/2) {
        pos.y = -tall/2;
    }
    
    if (randomMove) {
        
        // Change the velocity every once in a while:
        if (ofRandom(1) < 0.01) {
            vel.x = ofRandom(-1, 1) * speed;
        }
        if (ofRandom(1) < 0.01) {
            vel.y = ofRandom(-1, 1) * speed;
        }
        
    }
    
    /*
     angle++;
     
     if (angle > 360) {
     angle = 0;
     }
     */
}

void Particle::draw() {
    
    ofPushMatrix();{
        ofSetColor(c);
        ofTranslate(pos);
        //        ofRotate(angle);
        ofRotate(atan2(vel.y, vel.x)); // Rotate in the direction of movement.
        ofRect(0, 0, wide, tall);
    }ofPopMatrix();
}