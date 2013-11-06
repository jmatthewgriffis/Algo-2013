#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    
    mSender.setup("192.168.1.117", 7000);
    mReceiver.setup(8000);
    
    score = 0;
    
    goalLocal.set( ofGetWindowSize() / 2.0 );
    
    mouseLocal.set(ofGetWindowSize()/2);
    
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
    
    if (goalLocal.distance(mouseLocal) < 20){
        goalLocal.set(ofRandom(ofGetWindowWidth()),ofRandom(ofGetWindowHeight()));
        score++;
        
        ofxOscMessage m;
        m.setAddress("/score");
        mSender.sendMessage(m);
    }
    
    cout << score << endl;

}

//--------------------------------------------------------------
void testApp::checkOsc(){
    while(mReceiver.hasWaitingMessages()){
        
        cout << "message received" << endl;
        
        ofxOscMessage m;
        mReceiver.getNextMessage(&m);
        
        string addr = m.getAddress();
        
        if(addr == "/mouse/pos"){
            int xPos = m.getArgAsInt32(0);
            int yPos = m.getArgAsInt32(1);
            
            mouseLocal.set(xPos, yPos);
            
        }
        
        if(addr == "/score"){
            score++;
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255, 0, 255);
    ofDrawBitmapStringHighlight(ofToString(score), 5, 10);
    
    ofSetColor( 255 );
    ofCircle(mouseLocal, 20);
    
    ofSetColor( 255, 0, 0 );
    ofCircle(goalLocal, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    mouse.set(x, y);
    
    ofxOscMessage m;
    m.setAddress("/mouse/pos");
    m.addFloatArg(mouse.x);
    m.addFloatArg(mouse.y);
    mSender.sendMessage(m);
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
