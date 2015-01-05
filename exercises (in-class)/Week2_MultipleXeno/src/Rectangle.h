//
//  Rectangle.h
//  Week2_MultipleXeno
//
//  Created by J. Matthew Griffis on 9/3/13.
//
//

#pragma once

#include "ofMain.h"

class Rectangle {
public:
    Rectangle();
    
    void xenoToPoint( float catchX, float catchY);
    void draw();
    
    ofPoint pos;
    ofPoint targetPos;
    
    float catchUpSpeed;
    
};