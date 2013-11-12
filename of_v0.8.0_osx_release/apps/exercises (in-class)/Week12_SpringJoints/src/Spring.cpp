//
//  Spring.cpp
//  Week12_SpringJoints
//
//  Created by J. Matthew Griffis on 11/12/13.
//
//

#include "Spring.h"

void Spring::set( SpringJoint *_s1, SpringJoint *_s2, float _k, float _restLength ) {
    
    s1 = _s1;
    s2 = _s2;
    k = _k;
    restLength = _restLength;
}

void Spring::update() {
    
    ofVec2f force = s1->pos - s2->pos; // direction
    float len = force.length();
    float stretchLen = len - restLength;
    
    force.normalize();
    force *= -1 * k * stretchLen; // Hooke's law, baby.
    
    s1->applyForce( force );
    s2->applyForce( -force );
}

void Spring::draw() {
    
    ofLine( s1->pos, s2->pos );
}