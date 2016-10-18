#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    windowWidth = 500;
    windowHeight = 500;
    grid = new particleGrid(3, 3, windowWidth, windowHeight);
    
    blur.setup(windowWidth, windowHeight, 16, .1);
    ofBackground(0,0,0);
    ofEnableSmoothing();
    ofBlendMode(OF_BLENDMODE_MULTIPLY);
    srand(time(NULL));
}

//--------------------------------------------------------------
void ofApp::update(){
    blur.setBrightness(.2);
    blur.setScale(.15);
    
    grid->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    blur.begin();
    grid->draw();
    blur.end();
    blur.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
