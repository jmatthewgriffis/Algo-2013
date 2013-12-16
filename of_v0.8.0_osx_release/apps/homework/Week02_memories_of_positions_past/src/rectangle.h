//
//  rectangle.h
//  Week2_memories_of_positions_past
//
//  Created by J. Matthew Griffis on 9/10/13.
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