#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

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
    
    // CHALLENGE: 1. In class we bounced a particle between two side by side screens.  Bounce a particle between 4 screens arranged like so:
   
    /*
    
    -----------------
    |       |       |
    |   1   |   2   |
    |-------|-------|
    |       |       |
    |   3   |   4   |
    -----------------
    
Hint: It's possible to set a default position for the actual oF window by calling ofSetWindowPosition().
     
     */
    
    ofxOscSender mSender;
    
    ofVec2f mousePos;
    ofVec2f pos, vel;
};
