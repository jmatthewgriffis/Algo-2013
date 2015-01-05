//
//  Particle.h
//  Week5_GridParticles
//
//  Created by J. Matthew Griffis on 9/24/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    
    Particle( ofVec2f position );
    
//    void update( const ofImage &img );
    void draw();
    
    ofVec2f pos;
    
    float radius;
    float grayValue;
};