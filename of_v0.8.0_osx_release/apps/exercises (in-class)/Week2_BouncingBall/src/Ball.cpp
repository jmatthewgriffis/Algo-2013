//
//  Ball.cpp
//  Week2_BouncingBall
//
//  Created by J. Matthew Griffis on 9/3/13.
//
//

#include "Ball.h"

Ball::Ball(){
    
    // Provide a randomized, normalized velocity.
    // Note that although it says "random," the velocity turns out to be the same each time. That's because the computer has already generated all the "random" numbers and uses a "seed" as a starting point to read off the random numbers. We have to change the seed to get a different result each time. We use a special function for this.
    ofSeedRandom(); // DOUBLE-CHECK THIS.
    xVelocity = ofRandom(0.0, 1.0);
    yVelocity = ofRandom(0.0, 1.0);
    
    pos.x = ofGetWindowWidth() * 0.5;
    pos.y = ofGetWindowHeight() * 0.5;
    
    // We set the rect mode even though we're drawing a circle, because...why? DOUBLE-CHECK THIS.
    ofSetRectMode(OF_RECTMODE_CENTER);
    
}

void Ball::update() {
    
    pos.x += xVelocity * 10.0;
    pos.y += yVelocity * 10.0;
    
    if (pos.x < 0 || pos.x > ofGetWindowWidth()) {
        xVelocity *= -1;
    }
    
    if (pos.y < 0 || pos.y > ofGetWindowHeight()) {
        yVelocity *= -1;
    }
    
}

void Ball::draw() {
    
    ofSetColor(0, 0, 255);
    ofCircle(pos.x, pos.y, 20);
    
}