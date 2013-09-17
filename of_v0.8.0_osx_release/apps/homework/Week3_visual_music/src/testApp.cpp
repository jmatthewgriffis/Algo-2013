#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    background = 0;
    ofBackground(background);
    
    rectOffset = 10;
    
    for (int i = 0; i < numRects; i++) {
        Rectangle tmpRect; // Create a temp rect.
        tmpRect.wide = (ofGetWindowWidth()-(rectOffset * (numRects+1)))/numRects; // Size it so it will be centered along with the other rects.
        tmpRect.pos.x = rectOffset*(i+1) + tmpRect.wide*i; // Position it so it will be centered along with the other rects.
        tmpRect.pos.y = ofGetWindowHeight()/2 + tmpRect.tall/2; // Vertically centered.
        rectList.push_back(tmpRect); // Add it to the vector.
        
    }
    
    //    amplitudeX = ofGetWindowWidth()/2;
    amplitudeY = 100;
    period = 500.0;
    
    pos.x = 0;
    posVel = 7;
    rad = 0;
    
    heightVel = 10;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    pos.x += posVel; // Move the sin ball.
    if (pos.x >= ofGetWindowWidth() || pos.x <= 0) posVel *= -1; // Make it bounce off the walls.
    
    // CODE CHUNK: Use the sin ball to adjust the height of the rects.
    for (int i = 0; i < rectList.size(); i++) {
        
        float goalY = pos.y + rad + ofGetWindowHeight()/2;
        
        // Check if sin ball is above or below specific rect.
        if (pos.x > rectList[i].pos.x - rectList[i].wide/2 && pos.x < rectList[i].pos.x + rectList[i].wide/2) {
            
            if (rectList[i].pos.y > goalY) {
                
                rectList[i].tall += heightVel; // If so, adjust the rect's height to touch the ball.
                rectList[i].pos.y -= heightVel; // Also shift the pos so it looks like the rect is holding position and just getting taller.
            }
            else if (rectList[i].pos.y < goalY) {
                
                rectList[i].tall -= heightVel; // Ditto.
                rectList[i].pos.y += heightVel;
            }
        }
    } // END CHUNK
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i = 0; i < rectList.size(); i++) {
        rectList[i].draw(); // Draw the vector.
    }
    
    ofPushMatrix();{
        
        ofSetColor(255);
        ofTranslate(0, ofGetWindowHeight()/2);
        pos.y = amplitudeY * sin((ofGetElapsedTimeMillis() / period) * TWO_PI);
        ofCircle(pos, rad);
        
    }ofPopMatrix();
    
    ofDrawBitmapString("Daft Punk--Steam Machine  |  r to restart the machine", ofPoint(0, ofGetWindowHeight()));
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == 'r') {
        rectList.clear();
        setup();
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
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
