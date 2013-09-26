//
//  Particle.h
//  Week5_SingleParticle
//
//  Created by J. Matthew Griffis on 9/24/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle();
    //    ~Particle(); // This is a "destructor."
    
    void update();
    void draw();
    
    void setParams( float px, float py, float vx, float vy );
    void addForce( ofVec2f( force ));
    void addDampingForce();
    void resetForces();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    
    ofVec2f damping;
};