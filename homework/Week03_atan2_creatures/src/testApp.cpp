#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(255);
    
    for (int i = 0; i < numEnemies; i++) {
        Enemy tmpEnemy;
        tmpEnemy.angle = 360/numEnemies*i;
        enemyList.push_back(tmpEnemy);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < enemyList.size(); i++) {
        enemyList[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i = 0; i < enemyList.size(); i++) {
        enemyList[i].draw(ofPoint(mouseX, mouseY));
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
