#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    camWidth = ofGetWidth();
    camHeight = ofGetHeight();
    
    
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth,camHeight);
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    vidGrabber.update();
    
    if(points.size() < 500000) {
        for (int i=0; i<30; i++) {
            addPoint(ofGetWidth()/2, ofGetHeight()/2);
        }
    }
    
    for (unsigned int i=0; i<points.size(); i++) {
        
        speeds[i].y += 0.04; // some grav
        points[i]   += speeds[i];
        speeds[i]   *= 0.98;
        
        ofVec2f mouseVec = ofVec2f(ofGetMouseX(), ofGetMouseY()) - points[i];
        if(mouseVec.length() < 100) {
            mouseVec.normalize();
            speeds[i] -= mouseVec;
        }

        
        if(points[i].x > ofGetWidth())    points[i].x = 1;
        if(points[i].x < 0)               points[i].x = ofGetWidth()-1;
        if(points[i].y > ofGetHeight())   points[i].y = 1;
        if(points[i].y < 0)               points[i].y = ofGetHeight()-1;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    vidGrabber.draw(0, 0);
    
        ofSetColor(255);
        glBegin(GL_POINTS);
        for (unsigned int i=0; i<points.size(); i++) {
            glVertex2f(points[i].x, points[i].y);
        }
        glEnd();

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