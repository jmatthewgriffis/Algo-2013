//
//  FlockController.cpp
//  Week9_Flocking
//
//  Created by J. Matthew Griffis on 10/22/13.
//
//

#include "FlockController.h"

FlockController::FlockController() {
    
}

void FlockController::addBoid( int numParticles ) {
    
    for ( int i = 0; i < numParticles; i++ ) {
        Boid tmp;
        
        
        
        boidList.push_back( tmp );
    }
}

void FlockController::update() {
    
}

void FlockController::draw() {
    
}