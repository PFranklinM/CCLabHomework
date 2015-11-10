#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(100);
    
    xPos = 0;
    xVel = 5;
    
    border = false;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(border == false){
        xPos += xVel;
    } else{
        xPos -= xVel;
    }
    
    if(xPos >= ofGetWidth()){
        border = true;
    }
    
    if(xPos <= 0){
        border = false;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEllipse(xPos, ofGetHeight()/2, 50, 50);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}