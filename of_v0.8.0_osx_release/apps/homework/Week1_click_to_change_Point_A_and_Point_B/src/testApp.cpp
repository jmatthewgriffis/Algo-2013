#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetFrameRate(60);
    
    wide = 50;
    pos.x = ofGetWidth()-wide;
    pos.y = ofGetHeight()/2;
    /*
     xVel = 0.0037; // Fastest speed. Don't mess with this.
     inc = 0.001;
     multi = 10;
     red = 0.1;
     more = false;
     less = false;
     */
    frames = 0;
    hours = 0;
    minutes = 0;
    seconds = 0;
    reachMe = 25;
    
    // Interpolate origin
    posA.x = pos.x;
    posA.y = pos.y;
    // Interpolate destination
    posB.x = pos.x-200;
    posB.y = pos.y;
    
    pct = 0;
    setA = true;
    pctVel = 0.01f;
    conformed = false;
}

//--------------------------------------------------------------
void testApp::update(){
    
    // Only update the timer and xPos if the rect hasn't reached the goal.
    if (pos.x - wide/2 > reachMe) {
        frames++;
        //        xPos -= xVel;
    } else conformed = true;
    
    // Turn this on for interpolation-based movement:
    //    pct += 0.001f; // Slower movement.
    pct += pctVel; // Faster movement.
    if (pct > 1 || pct < 0) pctVel *= -1; // Prevent the percentage from going out of bounds.
    if (!conformed) interpolateByPct(pct);
    
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
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(50);
    
    // Tell the player what's up.
    ofSetColor(255);
    ofDrawBitmapString("r to reset  |  click to set new position", ofGetWidth()/2-170, 20);
    
    /*
     ofDrawBitmapString("LEFT/RIGHT to change xVel  |  hold UP/DOWN for greater/lesser change  |  current = " + ofToString(xVel), ofGetWidth()/2-350, ofGetHeight()-10);
     
     //Indicate modified controls.
     if (more && !less) ofDrawBitmapString("(more)", 658, ofGetHeight()-25);
     else if (!more && less) ofDrawBitmapString("(less)", 658, ofGetHeight()-25);
     */
    
    // Comment.
    if (!conformed) ofDrawBitmapString("Gets the idea, isn't feeling it\n    Decides to do own thing", ofGetWidth()/2-110, ofGetHeight()/2);
    else ofDrawBitmapString("    Great\nWay to conform", ofGetWidth()/2-75, ofGetHeight()/2);
    
    // Display elapsed time.
    ofDrawBitmapString("Time: " + ofToString(hours) + ":" + ofToString(minutes) + ":" + ofToString(seconds) + ":" + ofToString(frames), ofGetWidth()/2-70, 50);
    
    //    ofDrawBitmapString("Fastest speed: 0.0037.\nTime: 1:9:22.17\n(0.17 = 10 frames).\nDistance: 7.125 in.\nSpeed: 0.0017 in/s,\ni.e. approx. 9.66 x 10^-5 mph.", 40, 20);
    
    // Draw the finish line.
    ofSetLineWidth(8);
    ofLine(reachMe, 0, reachMe, ofGetHeight());
    ofPushMatrix();
    ofTranslate(-10, 17);
    ofDrawBitmapString("F", ofPoint(50, ofGetHeight()/2-50));
    ofDrawBitmapString("I", ofPoint(50, ofGetHeight()/2-35));
    ofDrawBitmapString("N", ofPoint(50, ofGetHeight()/2-20));
    ofDrawBitmapString("I", ofPoint(50, ofGetHeight()/2-5));
    ofDrawBitmapString("S", ofPoint(50, ofGetHeight()/2+10));
    ofDrawBitmapString("H", ofPoint(50, ofGetHeight()/2+25));
    ofPopMatrix();
    
    //    ofDrawBitmapString(ofToString(pct),pos.x-50,pos.y-50); // Debug
    
    if (!conformed) {
        
        // Draw the point names at the end of the line.
        ofDrawBitmapString("A",posA.x, posA.y);
        ofDrawBitmapString("B",posB.x, posB.y);
        
        // Draw the line itself.
        ofSetLineWidth(1);
        ofLine(posA.x, posA.y, posB.x, posB.y);
        
    }
    
    // Draw our heroic rectangle.
    ofSetColor(120,75,240);
    ofRect(pos.x, pos.y, wide, wide);
    
    if (!conformed) {
        // Tell the player what clicking will do.
        ofSetColor(255);
        if (setA) ofDrawBitmapString("Hmm...to change A?",mouseX+10,mouseY+30);
        else ofDrawBitmapString("I'mma change B!",mouseX+10,mouseY+30);
    }
    
    //    cout<<pct<<endl; // Debug
    
}

//--------------------------------------------------------------
void testApp::interpolateByPct(float myPct) {
    
    // This interpoloation function considers two points--the origin and the destination--and interpolates (i.e. inserts) a new current location between them. In this case we use a percentage of the destination, starting at zero. That means that the current location begins at 100% of the origin and 0% of the destination, then (as the percentage increases) moves away from the origin and toward the destination.
    
    // Note that this is analogous to "tweening"--a Flash term referring to giving two different values for something (such as position) and having the software calculate the values in-be"tween."
    
    pct = myPct;
    
    //    powf(2, 3) = 8 // EXAMPLE: This is 2 to the 3rd power.
    
    // Exponential increase gives accelerating movement. The resultant percentage of the destination starts out extremely tiny (making for slow movement) but becomes closer and closer to the input percentage (movement speeds up).
//        pct = powf(myPct, 3);
    
    // As described above, the actual manipulation of the position involves transforming it by a percentage of the destination and the opposite percentage of the origin.
    pos.x = (1-pct) * posA.x + pct * posB.x;
    pos.y = (1-pct) * posA.y + pct * posB.y;
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    // Reset on "r."
    if (key=='r') setup();
    
    // Change the xVel; use UP/DOWN for greater/lesser change.
    /*if (key==OF_KEY_LEFT) {
     if (more) xVel -= inc*multi;
     else if (less) xVel -= inc*red;
     else xVel -= inc;
     }
     if (key==OF_KEY_RIGHT) {
     if (more) xVel += inc*multi;
     else if (less) xVel += inc*red;
     else xVel += inc;
     }
     
     if (key==OF_KEY_UP) more = true;
     if (key==OF_KEY_DOWN) less = true;*/
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
//    if (key==OF_KEY_UP) more = false;
//    if (key==OF_KEY_DOWN) less = false;
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    //    xPos = mouseX;
    //    yPos = mouseY;
    
    // Reset the A and B pos using mouse pos.
    if (setA) {
        posA.x = mouseX;
        posA.y = mouseY;
    }
    else {
        posB.x = mouseX;
        posB.y = mouseY;
    }
    
    setA = !setA;
    
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
