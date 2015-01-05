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
    
    // CHALLENGE: A constant acceleration we have pulling on us as humans is gravity! Make an application that launches a ball at a random velocity on every click, and then pull it back to earth with gravity. Gravity here is 9.8 meters per second, try making a variation with the moon's gravity, and another with Jupiters gravity.
    
    ofVec2f pos;
    int rad, groundOffset;
    float vel, gravity, friction;
    bool onGround;
		
};
