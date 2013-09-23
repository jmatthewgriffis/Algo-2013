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
		
    // CHALLENGE: create a looping fireworks animation (non interactive). You will need to reset or restart particles every so often. Take a look at the last code example from class today (NoiceParticles) to see how to delete from a vector safely!
    
    // NOTE: starting from Charlie's noiseParticles example.
    void addParticle(ofPoint pos);
    
    vector<Particle> pList;
};
