#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    int tmp = 5;
    
    int *myPtr = &tmp; // A pointer is a location in memory (designated by the reference asterisk. The ampersand denotes the address
    
    int val = *myPtr; // Store the dereferenced value in a separate variable.
    
    cout << myPtr << " / " << *myPtr << endl; // Printing the pointer without the punctuation (i.e. printing the address) yields the address in memory (rendered as a hex code as though it were an image), rather than the value. However, using the asterisk again in front of the pointer name temporarily "deferences" the pointer, yielding the stored value.
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

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
