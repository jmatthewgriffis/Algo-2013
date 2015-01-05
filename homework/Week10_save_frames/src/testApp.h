#pragma once

#include "ofMain.h"
#include "Particle.h"

class testApp : public ofBaseApp {

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
		
    vector<Particle>    particleList;
    double  lastTime;
    float   timeScale;
    
    // CHALLENGE: 2. Use our delta time function to step through an application and save out individual frames of your application.  Take a look at ofSaveFrame() and ofSaveScreen().
    
    // I am modifying Charlie's repo example.
};
