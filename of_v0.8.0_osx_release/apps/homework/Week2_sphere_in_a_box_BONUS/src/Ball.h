//
//  Ball.h
//  Week2_sphere_in_a_box_BONUS
//
//  Created by J. Matthew Griffis on 9/10/13.
//
//

#pragma once

#include "ofMain.h"

class Ball {
public:
    Ball();
    
    void update();
    void draw();
    
    ofVec3f pos, vel;
    int boxRadius;
    
};