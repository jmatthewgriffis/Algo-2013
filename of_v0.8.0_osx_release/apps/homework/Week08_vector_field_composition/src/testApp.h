#pragma once

#include "ofMain.h"
#include "FlowField.h"
#include "Particle.h"

class testApp : public ofBaseApp{
  public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    // CHALLENGE: 1. Make two compositions using particles and vector fields, with an emphasis on the paths traveled by particles inside of the field.  In class, we saw particles moving through the vector fields, but didn't pay much attention to where they had come from and gone to.  Think about displaying the particles in a way besides just circles.  The vector field can be static or change over time.
    
    // NOTE: springboarding off Charlie's repo example for time efficiency's sake.
    
    // ORDER FROM CHAOS
    // Watch to see it emerge. Click to dam the river of time.
    
    void addParticle();
    
    float vectorAlpha, vectorAlphaVel;
    
    FlowField           myField;
    vector<Particle>    particleList;
};
