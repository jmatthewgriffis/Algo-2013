#pragma once

#include "ofMain.h"
#include "enemy.h"

#define numEnemies 9

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
    
    // CHALLENGE: Use atan2 in conjunction with some mouse follow code (xeno) or the previous vector/acceleration work and create a creature that follows a point. Think os using sin/cos to give it living characteristics based on it's motion. (think of more subtle motions of creatures, breathing, blinking, leg motion, etc)
    
    vector<Enemy> enemyList;
    
};
