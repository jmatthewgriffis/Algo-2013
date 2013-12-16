#pragma once

#include "ofMain.h"

#include "rectangle.h"

#define numRects 50

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
    
    // CHALLENGE: Since we talked a little bit about sound, make a compositon based on a piece of music. It doesn't have to be long, but there should be something dynamic to it. You don't have to have the sound included in the application, but your code should be the visual equivalent to the music. Think about what the artist was trying to say with the music, and try to bring that out in your visuals.
    vector<Rectangle> rectList;
    float rectOffset; // Space between rects.
    //    float amplitudeX;
    float amplitudeY;
    float period;
    ofPoint pos;
    int posVel;
    ofColor background;
    float rad;
    float heightVel;
    
};
