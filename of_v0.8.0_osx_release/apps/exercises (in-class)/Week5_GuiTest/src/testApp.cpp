#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    radius = 50;

    gui = new ofxUICanvas(); // Here we use the pointer to actually create an instance of the class. This does fill ("allocate") the reserved memory, and unless we free it later, it will remain filled until we reboot the computer. It doesn't happen automatically when we close the app. This is called a "memory leak."
    gui->addLabel("My Controls");
    gui->addSpacer();
    gui->addButton("myButton", false, 40, 40);
    gui->addSlider("radius", 0, 100, 50);
    
    gui->loadSettings("myGuiSettings.xml");
    
    ofAddListener( gui->newGUIEvent, this, &testApp::onGuiEvent);
    
}

void testApp::exit() {
    
    gui->saveSettings("myGuiSettings.xml");
    delete gui; // Here we make sure to delete the gui, which frees up the allocated memory. Memory leak: avoided.
}

void testApp::onGuiEvent( ofxUIEventArgs &e ) {
    
    cout << "I got a message" << e.getName() << endl;
    
    if ( e.getName() == "radius" ) {
        ofxUISlider *radiusSlider = (ofxUISlider*)e.widget;
        
        radius = radiusSlider->getScaledValue();
    }else if (e.getName() == "myButton" ) {
        ofxUIButton *b = (ofxUIButton*)e.widget;
        b->getValue();
    }
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255, 0, 255);
    ofCircle(ofGetWindowSize()/2, radius);

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
