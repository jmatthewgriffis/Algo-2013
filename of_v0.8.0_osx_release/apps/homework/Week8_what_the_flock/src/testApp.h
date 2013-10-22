#pragma once

#include "ofMain.h"
#include "Particle.h"

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
		
    // CHALLENGE: 2. We looked at a demo of a car steering to a destination.  Could you make a demo with two cars, that avoid each other if they get too close to one another?
    
    // NOTE: springboarding off Charlie's repo example for time efficiency's sake.
    
    ofVec2f pos, vel;
    ofVec2f dest;
    Particle car;
};
