#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetFrameRate(60);
    
    wide = wide2 = wide3 = wide4 = tall = tall2 = tall3 = tall4 = 25;
    // Upper-left rect
    pos.x = ofGetWidth()/2-wide/4;
    pos.y = ofGetHeight()/2-tall/4;
    // Upper-right rect
    pos2.x = ofGetWidth()/2+wide2/4;
    pos2.y = ofGetHeight()/2-tall2/4;
    // Lower-left rect
    pos3.x = ofGetWidth()/2-wide3/4;
    pos3.y = ofGetHeight()/2+tall3/4;
    // Lower-right rect
    pos4.x = ofGetWidth()/2+wide4/4;
    pos4.y = ofGetHeight()/2+tall4/4;
    /*
     frames = 0;
     hours = 0;
     minutes = 0;
     seconds = 0;
     reachMe = 25;
     */
    
    pct = 0;
    pctVel = 0.001f;
    wideA = wideC = wideE = wideG = wide/2;
    tallA = tallC = tallE = tallG = tall/2;
    wideB = wideD = wideF = wideH = 200;
    tallB = tallD = tallF = tallH = 200;
    lineOffset = 35;
    top = lineOffset;
    bottom = ofGetHeight()-lineOffset;
    left = lineOffset;
    right = ofGetWidth()-lineOffset;
    lineVel = 3;
    top1 = top2 = bottom1 = bottom2 = left1 = left2 = right1 = right2 = false;
    
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
    
    // Upper-left rect
    wideB = ofGetWidth()/2-left;
    tallB = ofGetHeight()/2-top;
    // Upper-right rect
    wideD = right-ofGetWidth()/2;
    tallD = ofGetHeight()/2-top;
    // Lower-left rect
    wideF = ofGetWidth()/2-left;
    tallF = bottom-ofGetHeight()/2;
    // Lower-right rect
    wideH = right-ofGetWidth()/2;
    tallH = bottom-ofGetHeight()/2;
    
    // Move finish lines under certain conditions:
    if (top1) if (top > 0) top -= lineVel;
    if (top2) if (top < ofGetHeight()/2 - wideA*4) top += lineVel;
    if (bottom1) if (bottom > ofGetHeight()/2 + wideA*4) bottom -= lineVel;
    if (bottom2) if (bottom < ofGetHeight()) bottom += lineVel;
    if (left1) if (left > 0) left -= lineVel;
    if (left2) if (left < ofGetWidth()/2 - wideA*4) left += lineVel;
    if (right1) if (right > ofGetWidth()/2 + wideA*4) right -= lineVel;
    if (right2) if (right < ofGetWidth()) right += lineVel;
    
    // Update position based on changing dimensions:
    // Upper-left rect
    pos.x = ofGetWidth()/2-wide/2;
    pos.y = ofGetHeight()/2-tall/2;
    // Upper-right rect
    pos2.x = ofGetWidth()/2+wide2/2;
    pos2.y = ofGetHeight()/2-tall2/2;
    // Lower-left rect
    pos3.x = ofGetWidth()/2-wide3/2;
    pos3.y = ofGetHeight()/2+tall3/2;
    // Lower-right rect
    pos4.x = ofGetWidth()/2+wide4/2;
    pos4.y = ofGetHeight()/2+tall4/2;
    
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
    
    // Draw our heroic rectangle. It is composed of four rectangles so we can adjust the growth in all directions. Would be cleaner to use a class but don't want to take the time right now.
    ofSetColor(120,75,240);
    // Upper-left
    ofRect(pos.x, pos.y, wide, tall);
    // Upper-right
    ofRect(pos2.x, pos2.y, wide2, tall2);
    // Lower-left
    ofRect(pos3.x, pos3.y, wide3, tall3);
    //Lower-right
    ofRect(pos4.x, pos4.y, wide4, tall4);
    
    //---------------------
    // Finally, draw the finish lines (def. cleaner to do this with a class but don't want to take the time right now).
    ofSetColor(255);
    ofSetLineWidth(8);
    
    // LEFT
    ofLine(left, 0, left, ofGetHeight());
    ofPushMatrix();
    ofTranslate(left-lineOffset, 17);
    ofDrawBitmapString("F", ofPoint(50, ofGetHeight()/2-50));
    ofDrawBitmapString("I", ofPoint(50, ofGetHeight()/2-35));
    ofDrawBitmapString("N", ofPoint(50, ofGetHeight()/2-20));
    ofDrawBitmapString("I", ofPoint(50, ofGetHeight()/2-5));
    ofDrawBitmapString("S", ofPoint(50, ofGetHeight()/2+10));
    ofDrawBitmapString("H", ofPoint(50, ofGetHeight()/2+25));
    ofPopMatrix();
    
    // RIGHT
    ofLine(right, 0, right, ofGetHeight());
    ofPushMatrix();
    ofTranslate(right+lineOffset-110, 17);
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
    ofLine(0, bottom, ofGetWidth(), bottom);
    ofPushMatrix();
    ofTranslate(0, bottom+lineOffset-100);
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
    // Upper-left rect
    if ((1-pct) * wideA + pct * wideB >= wideA*2 && (1-pct) * wideA + pct * wideB <= wideB * 0.98) {
        wide = (1-pct) * wideA + pct * wideB;
    }
    if ((1-pct) * tallA + pct * tallB >= tallA*2 && (1-pct) * tallA + pct * tallB <= tallB * 0.98) {
        tall = (1-pct) * tallA + pct * tallB;
    }
    // Upper-right rect
    if ((1-pct) * wideC + pct * wideD >= wideC*2 && (1-pct) * wideC + pct * wideD <= wideD * 0.98) {
        wide2 = (1-pct) * wideC + pct * wideD;
    }
    if ((1-pct) * tallC + pct * tallD >= tallC*2 && (1-pct) * tallC + pct * tallD <= tallD * 0.98) {
        tall2 = (1-pct) * tallC + pct * tallD;
    }
    // Lower-left rect
    if ((1-pct) * wideE + pct * wideF >= wideE*2 && (1-pct) * wideE + pct * wideF <= wideF * 0.98) {
        wide3 = (1-pct) * wideE + pct * wideF;
    }
    if ((1-pct) * tallE + pct * tallF >= tallE*2 && (1-pct) * tallE + pct * tallF <= tallF * 0.98) {
        tall3 = (1-pct) * tallE + pct * tallF;
    }
    // Lower-right rect
    if ((1-pct) * wideG + pct * wideH >= wideG*2 && (1-pct) * wideG + pct * wideH <= wideH * 0.98) {
        wide4 = (1-pct) * wideG + pct * wideH;
    }
    if ((1-pct) * tallG + pct * tallH >= tallG*2 && (1-pct) * tallG + pct * tallH <= tallH * 0.98) {
        tall4 = (1-pct) * tallG + pct * tallH;
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    switch (key) {
        case 'r':
        case 'R':
            setup(); // Reset
            break;
            
            // Move the finish lines:
            
            // Top
        case 'w':
        case 'W':
            top1 = true;
            break;
        case 's':
        case 'S':
            top2 = true;
            break;
            
            // Bottom
        case OF_KEY_UP:
            bottom1 = true;
            break;
        case OF_KEY_DOWN:
            bottom2 = true;
            break;
            
            // Left
        case 'a':
        case 'A':
            left1 = true;
            break;
        case 'd':
        case 'D':
            left2 = true;
            break;
            
            // Right
        case OF_KEY_LEFT:
            right1 = true;
            break;
        case OF_KEY_RIGHT:
            right2 = true;
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    switch (key) {
            // Stop moving the finish lines:
            
            // Top
        case 'w':
        case 'W':
            top1 = false;
            break;
        case 's':
        case 'S':
            top2 = false;
            break;
            
            // Bottom
        case OF_KEY_UP:
            bottom1 = false;
            break;
        case OF_KEY_DOWN:
            bottom2 = false;
            break;
            
            // Left
        case 'a':
        case 'A':
            left1 = false;
            break;
        case 'd':
        case 'D':
            left2 = false;
            break;
            
            // Right
        case OF_KEY_LEFT:
            right1 = false;
            break;
        case OF_KEY_RIGHT:
            right2 = false;
            break;
    }
    
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
