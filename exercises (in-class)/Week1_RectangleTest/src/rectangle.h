//
//  rectangle.h
//  Week1_RectangleTest
//
//  Created by J. Matthew Griffis on 8/27/13.
//
//

#pragma once

#include "ofMain.h"

class Rectangle {
public:
    Rectangle();
    
    void update();
    void draw();
    
    // Use Xeno's paradox to set a destination as asymptote.
    void xenoToPoint(float catchX, float catchY);
    
    // This will be a "shaper" function, modifying the input to produce different output.
    void interpolateByPct(float myPct);
    
    // ofPoints have an x and y pos.
    ofPoint pos;
    ofPoint posA;
    ofPoint posB;
    float pct; // percentage
};