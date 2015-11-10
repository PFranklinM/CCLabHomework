#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetCircleResolution(100);
    
    xMin = -350;
    xMax = 350;
    
    yMin = -350;
    yMax = 350;
    
    speed = 1;
    
    ofBackground(0, 0, 0);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    speed ++;
    
    xPos = mouseX;
    yPos = mouseY;
    
    if(speed >= xMax){
        speed = xMin;
    }
    
    if(speed >= yMax){
        speed = yMin;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, 0, 0);
    ofEllipse(375 + speed, 375 + speed, 50, 50);
    ofEllipse(375 + speed, 375 - speed, 50, 50);
    
    ofSetColor(0, 255, 0);
    ofEllipse(375 - speed, 375 - speed, 50, 50);
    ofEllipse(375 - speed, 375 + speed, 50, 50);
    
    ofSetColor(0, 0, 255);
    ofRect(xPos, yPos, 100, 100);
    

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
    
    ofBackground(255, 255, 255);

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    ofBackground(0, 0, 0);

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