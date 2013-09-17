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
    angle = angle2 = 0;
    dist = 200;
}

//--------------------------------------------------------------
void Enemy::update(){
    
    angle++;
    angle2++;
    dist = 200 + 100 * sin(ofDegToRad(angle2));
    //    dist = 200 * sin(angle); // Trigger this line and comment out the above for an amazing, mesmerizing effect! I took a video and put it in the project folder.
    pos.x = dist * sin(ofDegToRad(angle));
    pos.y = dist * cos(ofDegToRad(angle));
}

//--------------------------------------------------------------
void Enemy::draw(ofPoint mousePos){
    
    ofPushMatrix();{
        
        ofTranslate(mousePos.x, mousePos.y);
        ofRotate(angle2/2);
        ofLine(pos.x-rad*2, pos.y, pos.x+rad*2, pos.y);
        ofLine(pos.x, pos.y-rad*2, pos.x, pos.y+rad*2);
        ofCircle(pos, rad);
        
    }ofPopMatrix();
}