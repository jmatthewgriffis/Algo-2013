#pragma once

#include "ofMain.h"

#include "Rectangle.h"

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
    
    // CHALLENGE: Create a square canvas, and play with leaving trails for objects in motion by not clearing the screen. Play with shapes and colors and see what the most interesting composition you can make is. Take screenshots of the top 3 you come up with.
    
    //    Rectangle myRect;
    ofPoint mousePos;
    
    // Vectors (i.e. ArrayLists) in oF are better than normal arrays because (regardless of the dynamic size aspect) vectors are "typed" arrays, so they only accept one type of object.
    vector<Rectangle> rectList;
    
};
