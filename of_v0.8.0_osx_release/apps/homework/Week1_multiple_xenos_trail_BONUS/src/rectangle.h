//
//  rectangle.h
//  Week1_multiple_xenos_trail_BONUS
//
//  Created by J. Matthew Griffis on 9/2/13.
//
//

#pragma once

#include "ofMain.h"

class Rectangle {
public:
    Rectangle();
    
    void setup(ofColor c);
    void update();
    void draw();
    
    // Use Xeno's paradox to set a destination as asymptote.
    void xenoToPoint(float catchX, float catchY);
    
    // This will be a "shaper" function, modifying the input to produce different output.
    void interpolateByPct(float myPct);
    
    // ofPoints have an x and y pos.
    ofPoint pos;
    int wide;
    ofColor _c;
    bool offscreen, colliding;
    
};