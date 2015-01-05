//
//  Mover.h
//  Week2_AccelerationExample
//
//  Created by J. Matthew Griffis on 9/3/13.
//
//

#pragma once

#include "ofMain.h"

class Mover {
public:
    Mover();
    
    void update();
    void draw();
    
    ofVec2f pos, mousePos;
    ofVec2f accel, velocity;
    
};