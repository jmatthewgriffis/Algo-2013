#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    for (int i = 0; i < 5; i++) {
        // Could also use ++i notation; this is different in that it increments i after the for loop has been evaluated, not before. DOUBLE-CHECK THIS.
        Rectangle tmpRect;
        // It's necessary to store the temp rect in a vector because otherwise it will be discarded at the end of the function (C++'s "garbage collection").
        rectList.push_back( tmpRect ); // As "push_back" indicates, this adds the element to the end of the vector. However, there are other options.
        
    }
    
}

//--------------------------------------------------------------
void testApp::update(){

//    myRect.xenoToPoint(mousePos.x, mousePos.y);
    
    // Make the first rect follow the mouse and the remaining rects follow the preceding rect.
    for (int i = 0; i < rectList.size(); i++) {
        if (i == 0) {
            rectList[i].xenoToPoint(mousePos.x, mousePos.y);
        } else {
            rectList[i].xenoToPoint(rectList[i-1].pos.x, rectList[i-1].pos.y);
        }
        
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){

//    myRect.draw();
    
    for (int i = 0; i < rectList.size(); i++) {
        rectList[i].draw();
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

    // Alternate way to pass the mousePos into something else: store it in an ofPoint using this default function.
    mousePos.x = x;
    mousePos.y = y;
    
    // Note that the order matters because the equation changes whatever is on the left. We can't change the values fed into the function, so x and y can't be on the left. But the point is to change mousePos.x and mousePos.y so they do go on the left.
    
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
