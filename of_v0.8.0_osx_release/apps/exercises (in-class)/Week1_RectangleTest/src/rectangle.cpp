//
//  rectangle.cpp
//  Week1_RectangleTest
//
//  Created by J. Matthew Griffis on 8/27/13.
//
//

#include "rectangle.h"

//--------------------------------------------------------------
Rectangle::Rectangle(){
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
}

//--------------------------------------------------------------
void Rectangle::update() {
    
    // Movement technique: jitter
    pos.x = pos.x + ofRandom(-10,10);
    
}

//--------------------------------------------------------------
void Rectangle::draw() {
    
    ofEnableAlphaBlending();
    
    ofSetColor(50, 50, 255, 255*0.5);
//    ofSetHexColor(0xFFFFFF); // EXAMPLE: Also an option for color.
    
    ofRect(pos.x,pos.y,40,40);
    
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
    
    /*
     Here's why the total percentage in the equation must add up to 1(00), i.e. why we must multiply by catchUpSpeed in one case and by 1-catchUpSpeed in the other:
     
     The percentage times the mousePos is a constant increment (assuming no mouse movement).
     
     As the current position changes, and thus the result of multiplying it by a percentage grows or shrinks, the significance of the constant increment decreases or increases. For example, if the constant increment is 50, that will completely counter the effect of reducing the current position by 10, but be almost irrelevant to the effect of reducing the current position by 1000.
     
     If we multiplied the current position by a percentage equal to (or greater than) 1 (resulting in total percentage greater than 1), the current position would increase on its own and then further increase by the constant increment--this is just regular positive velocity.
     
     If we multiplied the current position by a percentage less than 1-catchUpSpeed, you might think that it would keep jumping to the left in an amount greater than the rightward increase of the constant increment. That would be negative velocity. However, as the current position gets smaller, because it's being reduced by a percentage it approaches zero as an asymptote. Eventually the current position functionally becomes zero and then is increased by the constant increment. The result is that the position comes to rest relative to the mouse but under-shoots it.
     
     On the flip side, if we multiplied the current position by a percentage less than 1 but greater than 1-catchUpSpeed, the position initially would increase, because although it's being decreased by the percentage, the constant increase is bigger, resulting in a total increase. However, eventually the position gets to a point where the constant increase is equal to the percent-based decrease. So the current position comes to rest relative to the mouse, but this time it over-shoots it.
     
     Really we're exploiting the same principle when we use the actual solution. We need the percent-based decrease to equal the constant increase (causing the current position to come to rest) only when the current position is the "same" as the mouse position. So catchX should be equal to pos.x, which means we can substitute pos.x for catchX in the equation below. We need to get to "pos.x = pos.x," i.e. "pos.x = 1.0 * pos.x," and the only way to do that is by ensuring the total percentage adds up to 1.
     
     *Drops the mic.*
     
     *Picks up the mic again.*
     
     Note that this is an ideal situation. If you plug in the same values for catchX and pos.x, the equation works. However if you start with different values, they will never actually equal one another. Hence the asymtotic nature of this technique.
     */
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    
}

//--------------------------------------------------------------