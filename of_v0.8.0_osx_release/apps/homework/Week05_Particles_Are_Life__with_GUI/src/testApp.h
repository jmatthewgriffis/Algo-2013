#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "ofxUI.h"

#define initParticles 50

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    void exit(); // We add this function in order to manage our memory since we're using the pointer.

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
    
    void onGuiEvent( ofxUIEventArgs &e );
    
    ofxUICanvas *gui; // Here we are creating a pointer to the class, WITHOUT actually creating an instance now, which would take up memory. The role of the pointer is to reserve a chunk of memory, but not actually fill it, sort of like a parking spot. This does require us to manage the memory manually though.
		
};
