//
//  rectangle.cpp
//  Week1_RectangleTest
//
//  Created by J. Matthew Griffis on 8/27/13.
//
//

#include "rectangle.h"

Rectangle::Rectangle(){
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
}

void Rectangle::update() {
    
//    pos.x = pos.x + ofRandom(-10,10); // Jitter motion.
    
}

void Rectangle::draw() {
    
    ofEnableAlphaBlending();
    ofSetColor(50, 50, 255, 255*0.5);
//    ofSetHexColor(0xFFFFFF); // Also an option for color.
    
    ofRect(pos.x,pos.y,40,40);
    
}

void Rectangle::xenoToPoint(float catchX, float catchY) {
    
    float catchUpSpeed = 0.03f;
    
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    
}

void Rectangle::interpolateByPct(float myPct) {
    
    pct = myPct;
    
//    powf(2, 3) = 8 // This is 2 to the 3rd power.
    
    // This is a "shaping" function. Shapes input to give different output.
    pct = powf(myPct, 3); // Exponential increase gives accelerating movement.
    
    pos.x = (1-pct) * posA.x + pct * posB.x;
    pos.y = (1-pct) * posA.y + pct * posB.y;
    
}