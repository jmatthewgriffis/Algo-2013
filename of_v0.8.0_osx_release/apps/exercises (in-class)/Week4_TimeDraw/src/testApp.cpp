#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    ofSetColor(255);
    ofNoFill();
    ofBeginShape();{
        
        // The following is an alternative to a for loop.
        for (vector<TimePoint>::iterator it = points.begin(); it != points.end(); it++) {
            // An iterator is a pointer. A pointer points to somewhere in memory.
            ofVertex(it->x, it->y);
//            (*it>.x); // Alternative syntax, known as "de-referencing."
        }
        
    }ofEndShape();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

    // Continue to create points and "record" time.
    TimePoint tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.z = ofGetElapsedTimef() - startTime;
    
    points.push_back(tmp);
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    points.clear(); // Clear out the vector each time we click again to start over.
    
    // Create a point and start "recording" time.
    TimePoint tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.z = 0;
    
    points.push_back(tmp);
    startTime = ofGetElapsedTimef(); // 'f' means 'float'
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
