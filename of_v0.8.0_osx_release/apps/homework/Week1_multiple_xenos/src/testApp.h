#pragma once

#include "ofMain.h"

#include "rectangle.h"

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
    
//    CHALLENGE: make a series of xeno objects which follow the mouse, each at different rates. give them slightly different colors so that you can perceive them as independent objects. you will have to modify the rectangle object so that they can have unique colors.
    
    Rectangle myRect, myRect2, myRect3, myRect4;
		
};
