#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofBackground(0);
    bIsRecording = false;
    playbackStartTime = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // Draw the line.
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
    
    // Draw the playback.
    ofPoint pos = getPositionForTime( ofGetElapsedTimef() - playbackStartTime );
    ofFill();
    ofSetColor(255,0,0);
    ofCircle(pos.x, pos.y, 10);
}

ofPoint testApp::getPositionForTime(float time) {
    
    // Return empty points if we're currently recording or there aren't enough points to make a line.
    if (bIsRecording) {
        return ofPoint(0,0,0);
    }else if ( points.size() < 2 ) {
        return ofPoint(0,0,0);
    }
    
    while ( time > points[ points.size() - 1 ].t ) {
        
        time -= points[ points.size() - 1 ].t;
    }
    
    ofPoint pos;
    
    for (int i = 0; i < points.size(); i++) {
        
        if (time >= points[i].t && time < points[i+1].t) {
            
            // Calc the percent
            float part = time - points[i].t;
            float whole = points[i+1].t - points[i].t;
            float pct = part/whole;
            
            pos.x = (1-pct) * points[i].x + pct * points[i+1].x;
            pos.y = (1-pct) * points[i].y + pct * points[i+1].y;
            
        }
        
    }
    
    return pos;
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
    tmp.t = ofGetElapsedTimef() - startTime;
    
    points.push_back(tmp);
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    points.clear(); // Clear out the vector each time we click again to start over.
    
    bIsRecording = true;
    
    // Create a point and start "recording" time.
    TimePoint tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.t = 0;
    
    points.push_back(tmp);
    startTime = ofGetElapsedTimef(); // 'f' means 'float'
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    bIsRecording = false;
    
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
