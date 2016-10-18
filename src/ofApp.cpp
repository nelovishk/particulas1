#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    windowWidth = 1280;
    windowHeight = 800;
    grid = new particleGrid(250, 80, windowWidth, windowHeight);
    
    blur.setup(windowWidth, windowHeight, 16, .1);
    ofBackground(0,0,0);
    ofEnableSmoothing();
    ofBlendMode(OF_BLENDMODE_MULTIPLY);
    srand(time(NULL));
}

//--------------------------------------------------------------
void ofApp::update(){
    blur.setBrightness(.0001);
    blur.setScale(.05);
    
    grid->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(doBlur) {
        blur.begin();
    }
    
    grid->draw();
    
    if(doBlur) {
        blur.end();
        blur.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    doBlur = !doBlur;
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
