//
//  enemy.h
//  Week3_atan2_creatures
//
//  Created by J. Matthew Griffis on 9/17/13.
//
//

#pragma once

#include "ofMain.h"

class Enemy {
public:
    Enemy();
    
    void update();
    void draw(ofPoint mousePos);

ofPoint pos;
float rad, angle, dist;

};