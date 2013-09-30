#pragma once

#include "ofMain.h"
#include "Particle.h"

#define initParticles 50

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
    
    // CHALLENGE: 1. Use ofxGui and build a particle system that has at least 3 adjustable parameters.  Tweak them to find 3 different sets of parameters that you really like and make a note of the settings in the comments of your program, or save them out in separate xml files.
    
    void addParticle();
    
    vector<Particle> particleList;
		
};
