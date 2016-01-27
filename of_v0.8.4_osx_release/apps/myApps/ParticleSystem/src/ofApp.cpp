#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(70, 160, 70);
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    
    for(int i=0; i<90000; i++){
        
        Particle myParticle;
        myParticle.setInitialCondition(ofRandom(0,1000), ofRandom(0,1000), 0, 0);
        
        particles.push_back(myParticle);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i=0; i<particles.size(); i++){
        particles[i].addAttraction(mouseX, mouseY, 1000, 0.05);
        particles[i].addRepulsion(mouseX, mouseY, 30, 35);
        particles[i].update();
        particles[i].resetForce();
        particles[i].addDampening();
        if(i == 0){
            particles[i].trail(mouseX, mouseY);
        }else{
            particles[i].trail(particles[i-1].pos.x, particles[i-1].pos.y);
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i=0; i<particles.size(); i++){
        particles[i].draw();
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
