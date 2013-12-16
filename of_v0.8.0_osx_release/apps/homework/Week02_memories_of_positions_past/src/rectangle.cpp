//
//  rectangle.cpp
//  Week2_memories_of_positions_past
//
//  Created by J. Matthew Griffis on 9/10/13.
//
//

#include "Rectangle.h"

Rectangle::Rectangle(){
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    catchUpSpeed = 0.06;
    
}

void Rectangle::xenoToPoint(float catchX, float catchY){
    
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    
}

void Rectangle::draw(){
    
    // Use the changing position of the rect to shift its color. By dividing its y pos by the window height, it produces a normalized result, i.e. something between 0 and 1.
    ofSetColor(0, 255.0 * (pos.y / ofGetWindowHeight()), 0);
    ofCircle(pos.x, pos.y, 5);
    
}