#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255, 255, 255);
    
    myPicture.loadImage("Me.jpg");
    
    myPicture.setImageType(OF_IMAGE_GRAYSCALE);
    
    myPictureAsCvImage.allocate(myPicture.width, myPicture.height);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    myPictureAsCvImage.setFromPixels(myPicture.getPixels(), myPicture.width,
                                     myPicture.height);
    
    myPictureAsCvImage.blur(MAX(mouseX, 1));

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    myPicture.draw(0, 0);
    
    myPictureAsCvImage.draw(0, 0);

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
