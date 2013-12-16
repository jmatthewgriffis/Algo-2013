//
//  Card.h
//  Week6_Solitaire
//
//  Created by J. Matthew Griffis on 10/7/13.
//
//

#pragma once
#include "ofMain.h"

class Card {
public:
    Card();
    
    void setup();
    void update();
    void draw();
    
    void applyForce( ofVec2f force );
    void gravity();
    
    ofVec2f pos, vel, accel;
    
    float wide, tall;
    
    ofColor c;
    
};