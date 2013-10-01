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
    
    void setup();
    void update(float _angle);
    void draw();
    
    ofVec2f pos;
    ofVec2f vel;
    int wide, tall;
    float angle, minAngle, maxAngle;
    float rotateRad, rotateVel, incRad;
    
    ofColor c;
};