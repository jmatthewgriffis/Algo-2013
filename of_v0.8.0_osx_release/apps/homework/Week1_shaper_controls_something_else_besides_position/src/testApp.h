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
    
    //    CHALLENGE: Make the shape code control another property of the object, such as its size or color. Make the nicest composition that you can. Try to make it elegant and organic.
    
    // This will be a "shaper" function, modifying the input to produce different output.
    void interpolateByPct(float myPct);
    
    // ofPoints have an x and y pos.
    ofPoint pos;
    float pct; // percentage
    float wide;
    int wideA, wideB;
//    int hours, minutes, seconds, frames;
    float pctVel; // Speed at which percentage changes.
    int lineOffset;
    int top, bottom, left, right, lineVel; // These locate the finish lines.
    
};
