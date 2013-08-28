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
    
    void xenoToPoint(float catchX, float catchY);
    
    void interpolateByPct(float myPct);
    
    ofPoint pos;
    ofPoint posA;
    ofPoint posB;
    float   pct;
};