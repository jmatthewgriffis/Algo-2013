//
//  Mover.cpp
//  Week2_AccelerationExample
//
//  Created by J. Matthew Griffis on 9/3/13.
//
//

#include "Mover.h"

Mover::Mover() {
    
    pos = ofGetWindowSize()/2;
    
    velocity.x = ofRandom(-5.0, 5.0);
    velocity.y = ofRandom(-5.0, 5.0);
    
}

void Mover::update() {
    
    // Use vector subtraction to accelerate in the direction of the mouse.
    accel = (mousePos - pos) * 0.01;
    
    // Now, use the acceleration to give an impulse to the velocity.
    velocity += accel;
    
    // Finally, add the velocity to the position.
    pos += velocity;
    
    // We need to use friction to ensure the velocity doesn't get too big.
    velocity *= 0.97;
    
}

void Mover::draw() {
    
    ofCircle(pos, 20);
    
}