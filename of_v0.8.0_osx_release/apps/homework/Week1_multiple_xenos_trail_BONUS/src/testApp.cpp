#include "testApp.h"

//--------------------------------------------------------------
void testApp::makeNewRect(){
    
    // Create and set up a new rect.
    Rectangle myRect;
    myRect.setup(rect_c);
    myRect.pos.x = ofRandom(0, ofGetWidth());
    myRect.pos.y = ofRandom(0, ofGetHeight());
    myRects.push_back(myRect); // Add the rect to the vector.
    rectTimer = 0; // Reset the rect generation timer.
    
}
//--------------------------------------------------------------
void testApp::makeNewMouseRect(){
    
    // Create and set up a new rect.
    Rectangle myRect;
    myRect.setup(mouseRect_c);
    myRect.pos.x = ofRandom(0, ofGetWidth());
    myRect.pos.y = ofRandom(0, ofGetHeight());
    myMouseRects.push_back(myRect); // Add the rect to the vector.
    
}

//--------------------------------------------------------------
void testApp::setup(){
    
    // This prevents screen tearing, which is when things are on-screen and there's an update in the middle of the drawing frame. That could mean that the top of an object were in one place and the bottom in another.
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    // Cool math note about Xeno's paradox: math proves that 0.99 repeating is equal to 1. Why? 1/3 is 0.33 repeating. Multiply that by 3 and you get 0.99 repeating. But 1/3 * 3 = 1. Therefore 0.99 repeating = 1.
    
    numInitRects = 1;
    numMouseRects = 5;
    rect_c = ofColor(50,50,255,255*0.5);
    mouseRect_c = ofColor(100,100,100,255*0.5);
    collided_c = 0;
    angle = 0;
    rad = 100;
    rectTimer = 0;
    rectRate = 120;
    radRate = 0.01;
    
    // Setup the initial rect(s).
    for (int i = 0; i < numInitRects; i++) {
        makeNewRect();
    }
    // Setup the mouse rect(s).
    for (int i = 0; i < numMouseRects; i++) {
        makeNewMouseRect();
    }
    
}

//--------------------------------------------------------------
bool bShouldIErase(Rectangle & a){
    
    // Zach Lieberman showed me how to use this method to remove an element from a vector. We create a boolean function, i.e. one that will return a boolean (so we don't use 'void'). We feed it a class and pass a reference label that we make up (in this case 'a') so we can refer to the applicable object. Then we check for a certain condition and, if we find it, return a boolean value of 'true.' Otherwise it's 'false.'
    
    if (a.offscreen) return true;
    else return false;
    
}

//--------------------------------------------------------------
void testApp::moveRects(){
    
    // First rect traces a circle using trig and an increasing angle.
    myRects[0].pos.x = ofGetWidth()/2 + sin(ofDegToRad(angle))*rad;
    myRects[0].pos.y = ofGetHeight()/2 + cos(ofDegToRad(angle))*rad;
    
    // Each successive rect follows the one before.
    for (int i = 1; i < myRects.size(); i++) {
        
        myRects[i].xenoToPoint(myRects[i-1].pos.x,myRects[i-1].pos.y);
        
        //        myRects[i].xenoToPoint(mouseX+i*10, mouseY-i*10); // Comment out the above and uncomment this for a cool 3D effect.
        
        // Also, calculate the distance from the center of the screen.
        float dist = ofDist(ofGetWidth()/2, ofGetHeight()/2, myRects[i].pos.x, myRects[i].pos.y);
        
        // If the distance is too great, mark the rect for removal.
        if (dist > ofGetWidth()/2) {
            myRects[i].offscreen = true;
        }
    }
    
}

//--------------------------------------------------------------
void testApp::moveMouseRects(){
    
    // Mouse rects work similarly but without trig and incl. the mouse.
    myMouseRects[0].xenoToPoint(mouseX, mouseY);
    
    // Each successive rect follows the one before.
    for (int i = 1; i < myMouseRects.size(); i++) {
        myMouseRects[i].xenoToPoint(myMouseRects[i-1].pos.x,myMouseRects[i-1].pos.y);
    }
    
}

//--------------------------------------------------------------
void testApp::whenRectsCollide(){
    
    // Reset the color (if I place this later the change during collision becomes permanent).
    for (int i = 0; i < myRects.size(); i++) {
        //        myRects[i]._c = rect_c;
        myRects[i].colliding = false;
    }
    for (int j = 0; j < myMouseRects.size(); j++) {
        myMouseRects[j]._c = mouseRect_c;
    }
    
    // Collision detection! This compares each rect to all the rects in the other group, and if there's a collision, it changes the colliding rects' colors. The mouse rects revert after collision, while the orbiting rects switch color each collision.
    for (int i = 0; i < myRects.size(); i++) {
        for (int j = 0; j < myMouseRects.size(); j++) {
            // Calculate the distance between the rects.
            float dist = ofDist(myRects[i].pos.x, myRects[i].pos.y, myMouseRects[j].pos.x, myMouseRects[j].pos.y);
            // If the distance is smaller than the combined radii, it's a collision, so change the color.
            if (dist < myRects[0].wide) {
                if (!myRects[i].colliding) {
                    if (myRects[i]._c == rect_c) myRects[i]._c = collided_c;
                    else myRects[i]._c = rect_c;
                    myRects[i].colliding = true;
                }
                myMouseRects[j]._c = collided_c;
            }
        }
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    angle++;
    rectTimer++;
    rad += radRate;
    
    // When the timer reaches the limit, make a new rect and reset the timer.
    if (rectTimer > rectRate) {
        makeNewRect();
    }
    
    if (angle > 360) angle = 0;
    
    moveRects();
    moveMouseRects();
    whenRectsCollide();
    
    // Following up the boolean function we created above, this oF function sorts the vector according to the values of the booleans and then removes any with a 'true' value:
    ofRemove(myRects,bShouldIErase);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //    cout<<myRects.size()<<endl; // Debug vector size.
    
    ofBackground(50);
    
    for (int i = 0; i < myRects.size(); i++) {
        myRects[i].draw();
    }
    
    for (int i = 0; i < myMouseRects.size(); i++) {
        myMouseRects[i].draw();
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == 'r') {
        
        // Clear out the vectors on reset:
        for (int i = 0; i < myRects.size(); i++) myRects.erase(myRects.begin(), myRects.end());
        for (int i = 0; i < myMouseRects.size(); i++) myMouseRects.erase(myMouseRects.begin(), myMouseRects.end());
        
        setup(); // Reset
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
