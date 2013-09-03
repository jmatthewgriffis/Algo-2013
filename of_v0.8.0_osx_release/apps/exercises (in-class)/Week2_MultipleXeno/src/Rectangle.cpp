//
//  Rectangle.cpp
//  Week2_MultipleXeno
//
//  Created by J. Matthew Griffis on 9/3/13.
//
//

#include "Rectangle.h"

Rectangle::Rectangle(){
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    catchUpSpeed = 0.03;
    
}

void Rectangle::xenoToPoint(float catchX, float catchY){
    
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    
}

void Rectangle::draw(){
    
    ofSetColor(255,0,0);
    ofRect(pos.x, pos.y, 20, 20);
    
}