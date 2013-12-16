//
//  enemy.h
//  Week3_atan2_creatures
//
//  Created by J. Matthew Griffis on 9/17/13.
//
//

#pragma once

#include "ofMain.h"

// Copied this from Charlie's in-class example code.
class Eyeball {
public:
    ofPoint pos, mousePos;
    float angle;
    
    void draw() {
        ofPushMatrix();{
            ofTranslate( pos );
            
            float dx = mousePos.x - pos.x;
            float dy = mousePos.y - pos.y;
            
            angle = atan2( dy , dx );
            
            ofRotate( ofRadToDeg(angle) );
            
            ofSetColor( 0 );
            
            // outline
            ofNoFill();
            ofCircle(0, 0, 50);
            
            // pupil
            ofFill();
            ofCircle(25, 0, 25);
        }ofPopMatrix();
    }
};

class Enemy {
public:
    Enemy();
    
    void update();
    void draw(ofPoint mousePos);

ofPoint pos;
float rad, angle, angle2, dist;
    
    void drawEye();
    Eyeball leftEye, rightEye;

};