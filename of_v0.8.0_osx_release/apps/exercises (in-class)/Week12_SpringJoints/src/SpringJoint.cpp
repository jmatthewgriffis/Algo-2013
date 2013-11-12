//
//  SpringJoint.cpp
//  Week12_SpringJoints
//
//  Created by J. Matthew Griffis on 11/12/13.
//
//

#include "SpringJoint.h"

void SpringJoint::applyForce( ofVec2f force ) {
    
    acc += force;
}

void SpringJoint::update() {
    
    vel += acc;
    pos += vel;
    
    vel *= 0.95;
    
    acc.set( 0 );
}

void SpringJoint::draw() {
    
    ofCircle( pos, 10 );
}