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
		
    ofVec3f pos, pos_2;
    ofVec3f vel, vel_2;
    ofFbo   mFbo, mFbo2;
    
    // CHALLENGE: 1. Make a particle application and use some of the techniques we talked about in class, or some of your own devising to make it look like there are many more particles than there actually are.  I'll run the app before looking at the source code, see if you can come up with a novel way!
    
    // I am modifying Charlie's Fbo repo example.
};