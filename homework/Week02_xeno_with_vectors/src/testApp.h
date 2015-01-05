#pragma once

#include "ofMain.h"

#include "rectangle.h"

#define numRects 8

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
    
    //    CHALLENGE: Take your xeno code from your homework last week and convert it to run with vectors instead of points.
    
    // NOTE: I already used an array in last week's homework so it's a simple matter to convert it to a vector.
    
    Rectangle tempRct;
    vector<Rectangle> myRects;
    int offset; // How far away from the mouse are the rects?
    bool surrounded;
    
};
