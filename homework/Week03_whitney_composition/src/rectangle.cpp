//
//  rectangle.cpp
//  Week3_whitney_composition
//
//  Created by J. Matthew Griffis on 9/16/13.
//
//

#include "rectangle.h"

//--------------------------------------------------------------
Rectangle::Rectangle(){
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    wide = ofGetWindowWidth();
    tall = wide * 0.75;
    pos.x = pos.y = 0;
    
    c = ofColor(50, 255, 50, 255*0.5);

}

//--------------------------------------------------------------
void Rectangle::update() {
    
    
    
}

//--------------------------------------------------------------
void Rectangle::draw() {
    
    ofEnableAlphaBlending();
    
    ofSetColor(c);
    
    ofRect(pos.x,pos.y,wide,tall);
    
}

//--------------------------------------------------------------
void Rectangle::interpolateByPct(float myPct) {
    
    // This interpoloation function considers two points--the origin and the destination--and interpolates (i.e. inserts) a new current location between them. In this case we use a percentage of the destination, starting at zero. That means that the current location begins at 100% of the origin and 0% of the destination, then (as the percentage increases) moves away from the origin and toward the destination.
    
    // Note that this is analogous to "tweening"--a Flash term referring to giving two different values for something (such as position) and having the software calculate the values in-be"tween."
    
    pct = myPct;
    
    //    powf(2, 3) = 8 // EXAMPLE: This is 2 to the 3rd power.
    
    // Exponential increase gives accelerating movement. The resultant percentage of the destination starts out extremely tiny (making for slow movement) but becomes closer and closer to the input percentage (movement speeds up).
    pct = powf(myPct, 3);
    
    // As described above, the actual manipulation of the position involves transforming it by a percentage of the destination and the opposite percentage of the origin.
    pos.x = (1-pct) * posA.x + pct * posB.x;
    pos.y = (1-pct) * posA.y + pct * posB.y;
    
}

//--------------------------------------------------------------
void Rectangle::xenoToPoint(float catchX, float catchY) {
    
    // This function, an example of Xeno's Paradox, moves the current location ever closer to the goal but never quite reaches it. It does this in a method similar to the interpolation function, using a percentage of the destination and the opposite percentage of the current location. However, where the interpolation function changed the percentage and kept the reference points consistent, this function keeps the percentage consistent and changes a reference point.
    
    float catchUpSpeed = 0.03f; // "f" specifies a float, instead of a double or other decimal number.
    
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    
}

//--------------------------------------------------------------