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
    
//    CHALLENGE: Find the fastest speed for the square to move across the screen and have the motion be imperceptible. Time how long it takes for the square to move across the screen and measure the physical (not pixel) distance. What is this speed in inches/second ? for kicks, What is it in in mph?
    
    int wide;
    double xPos;
    int yPos;
    double xVel;
    double inc;
    int multi; // multiplier
    float red; // multiplier
    bool more;
    bool less;
    int hours, minutes, seconds, frames;
    int reachMe;
		
};
