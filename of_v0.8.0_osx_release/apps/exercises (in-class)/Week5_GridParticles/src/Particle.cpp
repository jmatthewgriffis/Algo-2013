//
//  Particle.cpp
//  Week5_GridParticles
//
//  Created by J. Matthew Griffis on 9/24/13.
//
//

#include "Particle.h"

Particle::Particle( ofVec2f position ) {
    
    pos = position;
    
//    radius = 4;
    grayValue = 255;
    
//    radius = ofRandom(1.0, 5.0);
    radius = cos( pos.y * 0.1 ) + sin ( pos.x * 0.1 ) + 2;
}

void Particle::draw() {
    
    ofSetColor( grayValue );
    ofCircle(pos, radius);
}