//
//  FlockController.h
//  Week9_Flocking
//
//  Created by J. Matthew Griffis on 10/22/13.
//
//

#pragma once

#include "ofMain.h"
#include "Boid.h"

class FlockController {
public:
    FlockController();
    
    // We can set a default value for the passed-in value, overwritten if we actually pass something in.
    void addBoid( int numParticles = 1 );
    void update();
    void draw();
    
    vector< Boid > boidList;
};