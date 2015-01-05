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
    
    //    CHALLENGE: make an application where whenever you click, you change either the point A position or the point B position to the mouse position, alternating every time you click.
    
    // This will be a "shaper" function, modifying the input to produce different output.
    void interpolateByPct(float myPct);
    
    // ofPoints have an x and y pos.
    ofPoint pos;
    ofPoint posA;
    ofPoint posB;
    float pct; // percentage
    int wide;
    /*
     double xPos;
     int yPos;
     double xVel;
     double inc;
     int multi; // multiplier
     float red; // multiplier
     bool more;
     bool less;
     */
    int hours, minutes, seconds, frames;
    int reachMe;
    bool setA; // Control whether setting point A or point B.
    float pctVel; // Speed at which percentage changes.
    bool conformed;
    
};
