//
//  Particle.h
//  Week5_trig_particles
//
//  Created by J. Matthew Griffis on 9/30/13.
//
//

#pragma once
#include "ofMain.h"

class Particle {
public:
    
    Particle();
    
    void setup( float _anglee, ofVec2f _vec );
    void update();
    void draw();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f vec;
    int wide, tall;
    float angle, minAngle, maxAngle;
    float rotateRad, rotateVel, incRad;
    
    ofColor c;
};