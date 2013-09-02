#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // This prevents screen tearing, which is when things are on-screen and there's an update in the middle of the drawing frame. That could mean that the top of an object were in one place and the bottom in another.
    ofSetVerticalSync(true);
    
    // Cool math note about Xeno's paradox: math proves that 0.99 repeating is equal to 1. Why? 1/3 is 0.33 repeating. Multiply that by 3 and you get 0.99 repeating. But 1/3 * 3 = 1. Therefore 0.99 repeating = 1.
    
    /*
    myRect.setup(ofColor(50,50,255,255*0.5));
    myRect2.setup(ofColor(50,255,255,255*0.5));
    myRect3.setup(ofColor(255,50,255,255*0.5));
    myRect4.setup(ofColor(255,255,255,255*0.5));
    
    myRect.pos.x = ofGetWindowWidth()/2;
    myRect.pos.y = ofGetWindowHeight()/2;
    myRect2.pos.x = ofGetWindowWidth()/2;
    myRect2.pos.y = ofGetWindowHeight()/2;
    myRect3.pos.x = ofGetWindowWidth()/2;
    myRect3.pos.y = ofGetWindowHeight()/2;
    myRect4.pos.x = ofGetWindowWidth()/2;
    myRect4.pos.y = ofGetWindowHeight()/2;
     */
    
    for (int i = 0; i < numRects; i++) {
        Rectangle myRect;
        myRect.setup(ofColor(50,50,255,255*0.5));
        myRects.push_back(myRect);
    }
//    myEnemy.setup();
//    enemies.push_back(myEnemy);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    /*
    myRect.xenoToPoint(mouseX, mouseY);
    myRect2.xenoToPoint(mouseX-10, mouseY+20);
    myRect3.xenoToPoint(mouseX+25, mouseY-65);
    myRect4.xenoToPoint(mouseX-40, mouseY+50);
     */
    
    myRects[0].xenoToPoint(mouseX, mouseY);
    for (int i = 0; i < myRects.size(); i++) {
//        myRects[i].xenoToPoint(mouseX+i*10, mouseY-i*10); // Cool 3D effect
        if (i > 0) myRects[i].xenoToPoint( myRects[i-1].pos.x , myRects[i-1].pos.y );
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    cout<<myRects.size()<<endl;
    
    ofBackground(50);
    /*
    myRect.draw();
    myRect2.draw();
    myRect3.draw();
    myRect4.draw();
     */
    
    for (int i = 0; i < myRects.size(); i++) {
        myRects[i].draw();
    }
    
    ofSetColor(255); // This is for the benefit of the text.
    
    /*
    
    // Does this Xeno thing really work (i.e. never reach the goal)?
    if (myRect.pos.x == mouseX && myRect.pos.y == mouseY) {
        ofDrawBitmapString("Take that, Xeno!", ofPoint(myRect.pos.x-50, myRect.pos.y-50));
    }
    // Apparently it does.
    else if (myRect.pos.x >= mouseX-0.01 && myRect.pos.x <= mouseX+0.01 && myRect.pos.y >= mouseY-0.01 && myRect.pos.y <= mouseY+0.01) {
        ofDrawBitmapString("You win, Xeno.", ofPoint(myRect.pos.x-50, myRect.pos.y-50));
    }
     */
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
