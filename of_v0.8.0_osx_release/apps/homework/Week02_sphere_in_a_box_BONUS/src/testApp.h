#pragma once

#include "ofMain.h"

#include "Ball.h"

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
    
    // CHALLENGE: We bounced a circle around a box in 2 dimensions. Try to make a sphere that bounces around a 3D box using ofVec3f.
    
    Ball bouncingBall;
    
};
