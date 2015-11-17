#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(150,150,150);
    
    for( int i=0; i<5; i++ ){
        Rectangle myRect;
        rectList.push_back( myRect );
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for( int i=0; i<rectList.size(); i++ ){
        if( i==0 ){
            rectList[i].xenoToPoint(mouseX, mouseY);
        }else{
            rectList[i].xenoToPoint(rectList[i-1].pos.x, rectList[i-1].pos.y);
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for( int i=0; i<rectList.size(); i++ ){
        rectList[i].draw();
    }
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
