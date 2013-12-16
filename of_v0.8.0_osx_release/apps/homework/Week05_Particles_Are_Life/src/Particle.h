//
//  Particle.h
//  Week5_Particles_Are_Life
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
    void update();
    void draw();
    
    ofVec2f pos;
    ofVec2f vel;
    int speed;
    //    int angle;
    int wide, tall;
    float soClose;
    
    bool randomMove;
    int behavior; // 0 = neutral; 1 = attracted; 2 = repelled.
    
    ofColor c;
};