//
//  rectangle.h
//  Week2_xeno_with_vectors
//
//  Created by J. Matthew Griffis on 9/9/13.
//
//

#pragma once

#include "ofMain.h"

class Rectangle {
public:
    Rectangle();
    
    void setup(ofColor c, float vel);
    void update();
    void draw();
    
    // Use Xeno's paradox to set a destination as asymptote.
    void xenoToPoint(float catchX, float catchY);
    
    // This will be a "shaper" function, modifying the input to produce different output.
    void interpolateByPct(float myPct);
    
    // ofPoints have an x and y pos.
    ofPoint pos;
    ofColor _c;
    float catchUpSpeed;
    
};