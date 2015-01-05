//
//  Ball.cpp
//  Week2_sphere_in_a_box_BONUS
//
//  Created by J. Matthew Griffis on 9/10/13.
//
//

#include "Ball.h"

Ball::Ball(){
    
    // Provide a randomized, normalized velocity.
    // Note that although it says "random," the velocity turns out to be the same each time. That's because the computer has already generated all the "random" numbers and uses a "seed" as a starting point to read off the random numbers. We have to change the seed to get a different result each time. We use a special function for this.
    ofSeedRandom(); // DOUBLE-CHECK THIS.
    vel.x = ofRandom(0.0, 1.0);
    vel.y = ofRandom(0.0, 1.0);
    vel.z = ofRandom(0.0, 1.0);
    
    pos.x = ofGetWindowWidth() * 0.5;
    pos.y = ofGetWindowHeight() * 0.5;
    pos.z = 0;
    
    boxRadius = 200;
    
    // We set the rect mode even though we're drawing a circle, because...why? DOUBLE-CHECK THIS.
    ofSetRectMode(OF_RECTMODE_CENTER);
    
}

void Ball::update() {
    
    pos.x += vel.x * 10.0;
    pos.y += vel.y * 10.0;
    pos.z += vel.z * 10.0;
    
    if (pos.x < ofGetWindowWidth()/2-boxRadius || pos.x > ofGetWindowWidth()/2+boxRadius) {
        vel.x *= -1;
    }
    
    if (pos.y < ofGetWindowHeight()/2-boxRadius || pos.y > ofGetWindowHeight()/2+boxRadius) {
        vel.y *= -1;
    }
    
    if (pos.z < -boxRadius || pos.z > boxRadius) {
        vel.z *= -1;
    }
    
}

void Ball::draw() {
    // Draw the cube the ball is trapped in.
    ofNoFill();
    // Draw the back of the box:
    ofRect(ofGetWindowWidth()/2, ofGetWindowHeight()/2, -boxRadius, boxRadius*2, boxRadius*2);
    ofFill();
    ofLine(ofGetWindowWidth()/2-boxRadius, ofGetWindowHeight()/2-boxRadius, -boxRadius, ofGetWindowWidth()/2-boxRadius, ofGetWindowHeight()/2-boxRadius, boxRadius);
    ofLine(ofGetWindowWidth()/2+boxRadius, ofGetWindowHeight()/2-boxRadius, -boxRadius, ofGetWindowWidth()/2+boxRadius, ofGetWindowHeight()/2-boxRadius, boxRadius);
    ofLine(ofGetWindowWidth()/2-boxRadius, ofGetWindowHeight()/2+boxRadius, -boxRadius, ofGetWindowWidth()/2-boxRadius, ofGetWindowHeight()/2+boxRadius, boxRadius);
    ofLine(ofGetWindowWidth()/2+boxRadius, ofGetWindowHeight()/2+boxRadius, -boxRadius, ofGetWindowWidth()/2+boxRadius, ofGetWindowHeight()/2+boxRadius, boxRadius);
    ofSetColor(0, 0, 255);
//    ofCircle(pos.x, pos.y, 20);
    ofSphere(pos.x, pos.y, pos.z, 20);
    ofNoFill();
    // Draw the front of the box:
    ofRect(ofGetWindowWidth()/2, ofGetWindowHeight()/2, boxRadius, boxRadius*2, boxRadius*2);
    ofFill();
    
}
