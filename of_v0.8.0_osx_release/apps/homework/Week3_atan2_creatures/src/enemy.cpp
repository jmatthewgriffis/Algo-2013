//
//  enemy.cpp
//  Week3_atan2_creatures
//
//  Created by J. Matthew Griffis on 9/17/13.
//
//

#include "enemy.h"

//--------------------------------------------------------------
Enemy::Enemy(){
    
    rad = 20;
    angle = 0;
    dist = 200;
}

//--------------------------------------------------------------
void Enemy::update(){
    
    angle++;
    pos.x = dist * sin(ofDegToRad(angle));
    pos.y = dist * cos(ofDegToRad(angle));
}

//--------------------------------------------------------------
void Enemy::draw(ofPoint mousePos){
    
    ofPushMatrix();{
        
        ofTranslate(mousePos.x, mousePos.y);
        ofCircle(pos, rad);
        
    }ofPopMatrix();
}