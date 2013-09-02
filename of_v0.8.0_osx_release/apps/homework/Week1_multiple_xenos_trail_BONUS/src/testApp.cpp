#include "testApp.h"

//--------------------------------------------------------------
void testApp::makeNewRect(){
    
    // Create and set up a new rect.
    Rectangle myRect;
    myRect.setup(ofColor(50,50,255,255*0.5));
    myRect.pos.x = ofRandom(0, ofGetWidth());
    myRect.pos.y = ofRandom(0, ofGetHeight());
    myRects.push_back(myRect); // Add the rect to the vector.
    rectTimer = 0; // Reset the rect generation timer.
    
}

//--------------------------------------------------------------
void testApp::setup(){
    
    // This prevents screen tearing, which is when things are on-screen and there's an update in the middle of the drawing frame. That could mean that the top of an object were in one place and the bottom in another.
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    // Cool math note about Xeno's paradox: math proves that 0.99 repeating is equal to 1. Why? 1/3 is 0.33 repeating. Multiply that by 3 and you get 0.99 repeating. But 1/3 * 3 = 1. Therefore 0.99 repeating = 1.
    
    numInitRects = 1;
    angle = 0;
    rad = 100;
    rectTimer = 0;
    rectRate = 120;
    radRate = 0.01;
    
    // Setup the initial rect(s).
    for (int i = 0; i < numInitRects; i++) {
        makeNewRect();
    }
    
}

//--------------------------------------------------------------
bool bShouldIErase(Rectangle & a){
    
    // Zach Lieberman showed me how to use this method to remove an element from a vector. We create a boolean function, i.e. one that will return a boolean (so we don't use 'void'). We feed it a class and pass a reference label that we make up (in this case 'a') so we can refer to the applicable object. Then we check for a certain condition and, if we find it, return a boolean value of 'true.' Otherwise it's 'false.'
    
    if (a.offscreen) return true;
    else return false;
    
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
    
    // First rect traces a circle.
    myRects[0].pos.x = ofGetWidth()/2 + sin(ofDegToRad(angle))*rad;
    myRects[0].pos.y = ofGetHeight()/2 + cos(ofDegToRad(angle))*rad;
    // Each successive rect follows the one before.
    for (int i = 1; i < myRects.size(); i++) {
//        myRects[i].xenoToPoint(mouseX+i*10, mouseY-i*10); // Cool 3D effect
        myRects[i].xenoToPoint(myRects[i-1].pos.x,myRects[i-1].pos.y);
        
        // Also, calculate the distance from the center of the screen.
        float dist = ofDist(ofGetWidth()/2, ofGetHeight()/2, myRects[i].pos.x, myRects[i].pos.y);
        // If the distance is too great, mark the rect for removal.
        if (dist > ofGetWidth()/2) {
            myRects[i].offscreen = true;
        }
    }
    
    // Following up the boolean function we created above, this oF function sorts the vector according to the values of the booleans and then removes any with a 'true' value:
    ofRemove(myRects,bShouldIErase);
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    cout<<myRects.size()<<endl; // Debug vector size.
    
    ofBackground(50);
    
    for (int i = 0; i < myRects.size(); i++) {
        myRects[i].draw();
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if (key == 'r') setup(); // Reset
    
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
