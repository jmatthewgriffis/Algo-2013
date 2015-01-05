//
//  Particle.h
//  Week6_Forces
//
//  Created by J. Matthew Griffis on 10/1/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle();
    Particle( ofVec2f position );
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f acc;
    
    float mass;
    
    void applyForce( ofVec2f force );
    void update();
    void draw();
};