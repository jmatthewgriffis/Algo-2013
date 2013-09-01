#pragma once

#include "ofMain.h"

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
    
    //    CHALLENGE: find the fastest speed for the square to move across the screen and have the motion be still perceived as continuous (not discrete jumps). Time how long it takes for the square to move across the screen and measure the physical (not pixel) distance. What is this speed in inches/second ? What is this rate in mph?
    
    int wide;
    double xPos;
    int yPos;
    double xVel = 50.7; // By setting this in the head (normally a no-no) I can run setup() again within the app without losing my changes to the speed. It's ideal for this one instance.
    double inc;
    int multi; // multiplier
    float red; // multiplier
    bool more;
    bool less;
    int hours, minutes, seconds, frames;
    int reachMe;
    
};
