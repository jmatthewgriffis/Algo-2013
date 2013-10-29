//
//  Box.h
//  Week9_the_principles_12
//
//  Created by J. Matthew Griffis on 10/28/13.
//
//

#pragma once

#include "ofMain.h"

class Box {
public:
    Box();
    void setup();
    void update();
    void draw();
    
    void applyForce( ofVec2f _force );
    void anticipation( ofVec2f _force );
    
    ofVec2f pos, vel, acc, force;
    
    float friction, wide, tall;
    
    bool allowScooch;
};