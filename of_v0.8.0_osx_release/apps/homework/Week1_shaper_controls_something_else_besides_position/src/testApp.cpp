#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetFrameRate(60);
    
    wide = 50;
    pos.x = ofGetWidth()/2;
    pos.y = ofGetHeight()/2;
    /*
     frames = 0;
     hours = 0;
     minutes = 0;
     seconds = 0;
     reachMe = 25;
     */
    
    pct = 0;
    pctVel = 0.001f;
    wideA = wide/2;
    wideB = ofGetHeight();
    lineOffset = 35;
    top = lineOffset;
    bottom = ofGetHeight()-lineOffset;
    left = lineOffset;
    right = ofGetWidth()-lineOffset;
    lineVel = 5;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    // Turn this on for interpolation-based movement:
    //    pct += 0.001f; // Slower movement.
    pct += pctVel; // Faster movement.
    //    pct += 0.01;
    if (pct > 1 || pct < 0) pctVel *= -1; // Prevent the percentage from going out of bounds.
    //    if (pct > 1) pct = 0;
    interpolateByPct(pct);

    /*
     // Update the clock:
     if (frames >= 60) {
     seconds++;
     frames = 0;
     }
     if (seconds >= 60) {
     minutes++;
     seconds = 0;
     }
     if (minutes >= 60) {
     hours++;
     minutes = 0;
     }
     */
    
    wideB = (ofGetHeight()/2-top) * 2;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(50);
    
    // Tell the player what's up.
    ofSetColor(255);
    ofDrawBitmapString("r to reset  |  click to set new position", ofGetWidth()/2-170, 20);
    
    //    ofDrawBitmapString(ofToString(pct), 50, 20); // Debug
    //    ofDrawBitmapString(ofToString(pctVel), 50, 50); // Debug
    
    /*
     ofDrawBitmapString("LEFT/RIGHT to change xVel  |  hold UP/DOWN for greater/lesser change  |  current = " + ofToString(xVel), ofGetWidth()/2-350, ofGetHeight()-10);
     
     //Indicate modified controls.
     if (more && !less) ofDrawBitmapString("(more)", 658, ofGetHeight()-25);
     else if (!more && less) ofDrawBitmapString("(less)", 658, ofGetHeight()-25);
     */
    
    // Comment.
    ofDrawBitmapString(" Really wants it  |  Can't quite get it", ofGetWidth()/2-150, ofGetHeight()-10);
    
    // Display elapsed time.
    //    ofDrawBitmapString("Time: " + ofToString(hours) + ":" + ofToString(minutes) + ":" + ofToString(seconds) + ":" + ofToString(frames), ofGetWidth()/2-70, 50);
    
    // Draw our heroic rectangle.
    ofSetColor(120,75,240);
    ofRect(pos.x, pos.y, wide, wide);
    
    //---------------------
    // Finally, draw the finish lines (def. cleaner to do this with a class but don't want to take the time right now).
    ofSetColor(255);
    ofSetLineWidth(8);
    
    // LEFT
    ofLine(lineOffset, 0, lineOffset, ofGetHeight());
    ofPushMatrix();
    ofTranslate(0, 17);
    ofDrawBitmapString("F", ofPoint(50, ofGetHeight()/2-50));
    ofDrawBitmapString("I", ofPoint(50, ofGetHeight()/2-35));
    ofDrawBitmapString("N", ofPoint(50, ofGetHeight()/2-20));
    ofDrawBitmapString("I", ofPoint(50, ofGetHeight()/2-5));
    ofDrawBitmapString("S", ofPoint(50, ofGetHeight()/2+10));
    ofDrawBitmapString("H", ofPoint(50, ofGetHeight()/2+25));
    ofPopMatrix();
    
    // RIGHT
    ofLine(ofGetWidth()-lineOffset, 0, ofGetWidth()-lineOffset, ofGetHeight());
    ofPushMatrix();
    ofTranslate(ofGetWidth()-110, 17);
    ofDrawBitmapString("F", ofPoint(50, ofGetHeight()/2-50));
    ofDrawBitmapString("I", ofPoint(50, ofGetHeight()/2-35));
    ofDrawBitmapString("N", ofPoint(50, ofGetHeight()/2-20));
    ofDrawBitmapString("I", ofPoint(50, ofGetHeight()/2-5));
    ofDrawBitmapString("S", ofPoint(50, ofGetHeight()/2+10));
    ofDrawBitmapString("H", ofPoint(50, ofGetHeight()/2+25));
    ofPopMatrix();
    
    // TOP
    ofLine(0, top, ofGetWidth(), top);
    ofPushMatrix();
    ofTranslate(0, top-lineOffset+10);
    ofDrawBitmapString("F", ofPoint(ofGetWidth()/2-50, 50));
    ofDrawBitmapString("I", ofPoint(ofGetWidth()/2-35, 50));
    ofDrawBitmapString("N", ofPoint(ofGetWidth()/2-20, 50));
    ofDrawBitmapString("I", ofPoint(ofGetWidth()/2-5, 50));
    ofDrawBitmapString("S", ofPoint(ofGetWidth()/2+10, 50));
    ofDrawBitmapString("H", ofPoint(ofGetWidth()/2+25, 50));
    ofPopMatrix();
    
    // BOTTOM
    ofLine(0, ofGetHeight()-lineOffset, ofGetWidth(), ofGetHeight()-lineOffset);
    ofPushMatrix();
    ofTranslate(0, ofGetHeight()-100);
    ofDrawBitmapString("F", ofPoint(ofGetWidth()/2-50, 50));
    ofDrawBitmapString("I", ofPoint(ofGetWidth()/2-35, 50));
    ofDrawBitmapString("N", ofPoint(ofGetWidth()/2-20, 50));
    ofDrawBitmapString("I", ofPoint(ofGetWidth()/2-5, 50));
    ofDrawBitmapString("S", ofPoint(ofGetWidth()/2+10, 50));
    ofDrawBitmapString("H", ofPoint(ofGetWidth()/2+25, 50));
    ofPopMatrix();
    //---------------------
    
    //    cout<<pct<<endl; // Debug
    
}

//--------------------------------------------------------------
void testApp::interpolateByPct(float myPct) {
    
    // This interpoloation function considers two points--the origin and the destination--and interpolates (i.e. inserts) a new current location between them. In this case we use a percentage of the destination, starting at zero. That means that the current location begins at 100% of the origin and 0% of the destination, then (as the percentage increases) moves away from the origin and toward the destination.
    
    // Note that this is analogous to "tweening"--a Flash term referring to giving two different values for something (such as position) and having the software calculate the values in-be"tween."
    
    pct = myPct;
    
    // Exponential increase gives accelerating movement. The resultant percentage of the destination starts out extremely tiny (making for slow movement) but becomes closer and closer to the input percentage (movement speeds up).
    //    pct = powf(myPct, 3); // FIND ME--for some reason this is broken. Can't figure out why.
    
    // As described above, the actual manipulation of the position involves transforming it by a percentage of the destination and the opposite percentage of the origin. Furthermore we use an if statement to let the percentage reduce for a moment without changing the size of the rect, to make a pause before it grows again.
    if ((1-pct) * wideA + pct * wideB >= wideA*2 && (1-pct) * wideA + pct * wideB <= wideB*0.9) {
        wide = (1-pct) * wideA + pct * wideB;
    }
    //    pos.y = (1-pct) * posA.y + pct * posB.y;
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    switch (key) {
        case 'r':
        case 'R':
            setup(); // Reset
            break;
            
        case 'w':
        case 'W':
            if (top > 0) top -= lineVel;
            break;
        case 's':
        case 'S':
            if (top < ofGetHeight()/2 - wideA*4) top += lineVel;
            break;
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
