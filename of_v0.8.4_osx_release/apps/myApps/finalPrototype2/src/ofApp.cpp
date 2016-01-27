#include "ofApp.h"

#define PREVIEW_W	1280
#define PREVIEW_H	720

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    
    camW = 1280;
    camH = 720;
    
    w = camW;
    h = camH;
    
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(w,h);
    
    colorImg.allocate(w,h);
    grayImg.allocate(w,h);
    diffImg.allocate(w,h);
    binaryImg.allocate(w,h);
    
    drawGui = false;

    gui.setup("LaserMouse");
    gui.add(guiHelp.setup("[H] Key ", "Hide Menu"));
    gui.add(imgThreshold.setup("Threshold", 30, 0, 255));
    gui.add(minArea.setup("Min Area", 20, 0, 300*200));
    gui.add(maxArea.setup("Max Area", 900, 0, 600*400));
    gui.add(hMirror.setup("H Mirror", true));
    gui.add(vMirror.setup("V Mirror", false));
    gui.add(debugView.setup("Debug View", true));
    gui.add(motionStatus.setup("Motion ", ""));

    gui.loadFromFile("settings.xml");
//    gui.setPosition( 0, 0 );
    
    ofSetCircleResolution(100);
    
    pos.set(5, ofGetHeight()/2);
    
    xVel = 5;
    yVel = -5;
    
    counter = 0;
    
    xMin = 0;
    xMax = ofGetWidth();
    
    yMin = 0;
    yMax = ofGetHeight();
    
    player1Score = 0;
    player2Score = 0;
    
    isHit = false;



}

//--------------------------------------------------------------
void ofApp::update(){
    
    vidGrabber.update();
    
    if (vidGrabber.isFrameNew()){
        colorImg.setFromPixels(vidGrabber.getPixels(), w, h);
        colorImg.mirror( vMirror, hMirror );
        
        grayImg = colorImg;
        
        diffImg.absDiff(grayImg, grayPrevImg);
        
        grayPrevImg = colorImg;
        
        binaryImg = diffImg;
        binaryImg.threshold(imgThreshold);
        
        contourFinder.findContours(binaryImg, minArea, maxArea, 10, false);
    
        if (contourFinder.nBlobs > 0){
            isMotionDetected = true;
            motionStatus = "detected";
        }else{
            isMotionDetected = false;
            motionStatus = "none";
        }
    }
    
    
    ofTranslate( 0, PREVIEW_H );
    ofScale((float)PREVIEW_W / w,(float)PREVIEW_H / h);
    
    
    int x, y;
    
    for (int i = 0; i < contourFinder.nBlobs; i++){
        stringstream str;
        
        contourFinder.blobs[i].draw(0, 0);
        
        x = (contourFinder.blobs[i].centroid.x);
        y = (contourFinder.blobs[i].centroid.y);
        
        motion.set(x, y);
        
        ofVec3f diff = motion - pos;
        
        if(diff.length() < 75){
            
            if(ofGetElapsedTimeMillis() >= 250){
                float percent = 1 - (diff.length() / 75);
                
                xVel += diff.x * percent;
                xVel = -xVel;
                
                yVel += diff.y * percent;
                yVel = -yVel;
                
                isHit = true;
            }
            
            if(isHit == true){
                isHit = false;
                ofResetElapsedTimeCounter();
            }
        }
    }

    pos.x += xVel;
    pos.y -= yVel;
    
//    if(pos.x < xMin || pos.x > xMax){
//        xVel = -xVel;
//    }
    
    if(pos.x >= xMax){
        player1Score += 1;
        pos.set(5, ofGetHeight()/2);
        xVel = 5;
        yVel = -5;
    }
    
    if(pos.x <= xMin){
        player2Score += 1;
        pos.set(ofGetWidth()-5, ofGetHeight()/2);
        xVel = -5;
        yVel = -5;
    }
    
    if(pos.y < yMin || pos.y > yMax){
        yVel = -yVel;
    }
    
    ofSetColor(255, 255, 255);



}

//--------------------------------------------------------------
void ofApp::draw(){
        
//        colorImg.draw(0, 0, ofGetWidth(), ofGetHeight());
//        grayImg.draw(0, 0, ofGetWidth(), ofGetHeight());
        diffImg.draw( 0, 0, ofGetWidth(), ofGetHeight());
//        binaryImg.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    if (drawGui){
        ofEnableAlphaBlending();
        gui.draw();
        ofDisableAlphaBlending();
    }
    
    ofSetColor(255);
    ofFill();
    ofEllipse(pos.x, pos.y, 75, 75);
    
    ofSetColor(255, 0, 0);
    ofNoFill();
    
    ofRect(ofGetWidth()*0.25, 0, 20, ofGetHeight());
    ofRect(ofGetWidth()*0.75, 0, 20, ofGetHeight());
    
    ofSetColor(255);
//    ofScale(500, 500);
    ofDrawBitmapString("Player 1: " + ofToString(player1Score), ofGetWidth()*0.05, ofGetHeight()*0.05);
    ofDrawBitmapString("Player 2: " + ofToString(player2Score), ofGetWidth()*0.9, ofGetHeight()*0.05);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key){
        case 'f':
        case 'F':
            ofToggleFullscreen();
            break;
    }


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
