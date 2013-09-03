//
//  Ball.h
//  Week2_BouncingBall
//
//  Created by J. Matthew Griffis on 9/3/13.
//
//

#pragma once

#include "ofMain.h"

class Ball {
public:
    Ball();
    
    void update();
    void draw();
    
    ofVec2f pos;
    float xVelocity;
    float yVelocity;
    
};