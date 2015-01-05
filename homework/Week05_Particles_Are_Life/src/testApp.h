#pragma once

#include "ofMain.h"
#include "Particle.h"

#define initParticles 50

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
    
    // CHALLENGE: 2. Particles don't have to just be circles though you wouldn't know it from the class examples.  Use images to come up with different effects.  Use what you've learned so far about rotation, opacity, trails etc to make something special.  Dont' feel liks you have to use all of these techniques, use your design sense and good taste to build something you'd want to show to a friend.
    
    void addParticle();
    
    vector<Particle> particleList;
    
};