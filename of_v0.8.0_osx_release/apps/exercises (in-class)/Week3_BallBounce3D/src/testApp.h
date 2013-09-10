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
    
    ofPoint ballPos; // Points are the same as vectors in oF.
    ofVec3f ballVel;
    float boxRadius;
    
    ofBoxPrimitive mBox; // "m" in front of the variable means that it's a "member" variable, meaning it belongs to a class. Similarly "b" in front of the variable means "boolean."
		
};
