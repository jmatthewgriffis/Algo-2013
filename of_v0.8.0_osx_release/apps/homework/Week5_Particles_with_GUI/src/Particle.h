//
//  Particle.h
//  Week5_Particles_with_GUI
//
//  Created by J. Matthew Griffis on 9/29/13.
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
    bool attract;
    bool claustrophobe;
    
    ofColor c;
};