#include "ofApp.h"

#define PREVIEW_W	1280
#define PREVIEW_H	720

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    
    camW = ofGetWidth();
    camH = ofGetHeight();
    
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
    
    goalieVelP1A = 5;
    goalieVelP1B = 5;
    
    goalieVelP2A = 5;
    goalieVelP2B = 5;

    goalieP1A.set(ofGetWidth()*0.05, ofGetHeight()*0.25);
    goalieP1B.set(ofGetWidth()*0.05, ofGetHeight()*0.75);
    
    goalieP2A.set(ofGetWidth()*0.95, ofGetHeight()*0.25);
    goalieP2B.set(ofGetWidth()*0.95, ofGetHeight()*0.75);
    
    counter = 0;
    
    xMin = 0;
    xMax = ofGetWidth();
    
    yMin = 0;
    yMax = ofGetHeight();
    
    player1Score = 0;
    player2Score = 0;
    
    movingRight = true;
    
    movingLeft = false;



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
    
    if(xVel < 0){
        movingLeft = true;
        movingRight = false;
    }
    
    if(xVel > 0){
        movingLeft = false;
        movingRight = true;
    }
    
//    if(xVel == 0){
//        movingLeft = true;
//        movingRight = true;
//    }
    
    for (int i = 0; i < contourFinder.nBlobs; i++){
        
        contourFinder.blobs[i].draw(camW, camH);
        
        x = (contourFinder.blobs[i].centroid.x);
        y = (contourFinder.blobs[i].centroid.y);
        
        motion.set(x, y);
        
        int sumXP1 = 0;
        int sumYP1 = 0;
        int sumAreaP1 = 0;
        
        int sumXP2 = 0;
        int sumYP2 = 0;
        int sumAreaP2 = 0;
        
        
        for (int blob1 = 0; blob1 <= contourFinder.getWidth()*0.25; blob1++) {
                    
            float xposP1;
            float yposP1;
                
            xposP1 = contourFinder.blobs[i].centroid.x;
            yposP1 = contourFinder.blobs[i].centroid.y;

            float areaBlobP1 = contourFinder.blobs[i].area;
                
            sumXP1 += xposP1 * areaBlobP1;
            
            sumYP1 += yposP1 * areaBlobP1;
                    
            sumAreaP1 += areaBlobP1;
        
        }
        
            float averageXP1 = sumXP1/sumAreaP1;
            float averageYP1 = sumYP1/sumAreaP1;
        
            P1.set(averageXP1, averageYP1);
        
        
        for (int blob2 = ofGetWidth()*0.75; blob2 <= ofGetWidth(); blob2++) {
            
            float xposP2;
            float yposP2;
            
            xposP2 = contourFinder.blobs[i].centroid.x;
            yposP2 = contourFinder.blobs[i].centroid.y;
            
            float areaBlobP2 = contourFinder.blobs[i].area;
            
            sumXP2 += xposP2 * areaBlobP2;
            
            sumYP2 += yposP2 * areaBlobP2;
            
            sumAreaP2 += areaBlobP2;
            
    }

    
    float averageXP2 = sumXP2/sumAreaP2;
    float averageYP2 = sumYP2/sumAreaP2;
    
    P2.set(averageXP2, averageYP2);

    
    
        ofVec2f diffP1 = P1 - pos;
        ofVec2f diffP2 = P2 - pos;
    
        if(diffP1.length() < 50 || diffP2.length() < 50){

            if(movingRight == true && pos.x > rightSide){
                
                float percentP2 = 1 - (diffP2.length() / 65);
                
                xVel += diffP2.x * percentP2;
                xVel = -xVel;
                
                yVel += diffP2.y * percentP2;
                yVel = -yVel;
                
            }
            
            if(movingLeft == true && pos.x < leftSide){
            
                float percentP1 = 1 - (diffP1.length() / 65);
                
                xVel += diffP1.x * percentP1;
                xVel = -xVel;
                
                yVel += diffP1.y * percentP1;
                yVel = -yVel;
            }
            
        }
    
    ofVec2f goalieDiffP1A = goalieP1A - pos;
    ofVec2f goalieDiffP1B = goalieP1B - pos;
    
    ofVec2f goalieDiffP2A = goalieP2A - pos;
    ofVec2f goalieDiffP2B = goalieP2B - pos;
        
    if(goalieDiffP1A.length() < 50 || goalieDiffP2A.length() < 50 ||
       goalieDiffP1B.length() < 50 || goalieDiffP2B.length() < 50){
        
        if(movingLeft == true && pos.x < leftSide){

            xVel = -xVel;
        
            yVel = -yVel;
        }
        
        
        if(movingRight == true && pos.x > rightSide){
            
            xVel = -xVel;
            
            yVel = -yVel;
            
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
    
    goalieP1A.y -= goalieVelP1A;
    goalieP1B.y += goalieVelP1B;
    
    goalieP2A.y -= goalieVelP2A;
    goalieP2B.y += goalieVelP2B;
    
    
    if(goalieP1A.y >= ofGetHeight()*0.5 || goalieP1A.y <= yMin){
        goalieVelP1A = -goalieVelP1A;
    }
    
    if(goalieP1B.y <= ofGetHeight()*0.5 || goalieP1B.y >= yMax){
        goalieVelP1B = -goalieVelP1B;
    }
    
    if(goalieP2A.y >= ofGetHeight()*0.5 || goalieP2A.y <= yMin){
        goalieVelP2A = -goalieVelP2A;
    }
    
    if(goalieP2B.y <= ofGetHeight()*0.5 || goalieP2B.y >= yMax){
        goalieVelP2B = -goalieVelP2B;
    }
    
    if(player1Score == 21 || player2Score == 21){
        xVel = 0;
        yVel = 0;
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
    
    ofRect(ofGetWidth()*0.33, 0, 20, ofGetHeight());
    ofRect(ofGetWidth()*0.66, 0, 20, ofGetHeight());
    
    ofSetColor(255);
    ofDrawBitmapString("Player 1: " + ofToString(player1Score), ofGetWidth()*0.05, ofGetHeight()*0.05);
    ofDrawBitmapString("Player 2: " + ofToString(player2Score), ofGetWidth()*0.9, ofGetHeight()*0.05);
    
    if(player1Score == 21){
        ofDrawBitmapString("Player 1 Wins!", ofGetWidth()/2, ofGetHeight()/2);
    }
    
    if(player2Score == 21){
        ofDrawBitmapString("Player 2 Wins!", ofGetWidth()/2, ofGetHeight()/2);
    }
    
    if(player1Score >= 10){
        ofSetColor(255);
        ofFill();
        ofRect(goalieP2A.x, goalieP2A.y, 20, 150);
    }
    
    if(player1Score >= 20){
        ofSetColor(255);
        ofFill();
        ofRect(goalieP2B.x, goalieP2B.y, 20, 150);
    }
    
    if(player2Score >= 10){
        ofSetColor(255);
        ofFill();
        ofRect(goalieP1A.x, goalieP1A.y, 20, 150);
    }
    
    if(player2Score >= 20){
        ofSetColor(255);
        ofFill();
        ofRect(goalieP1B.x, goalieP1B.y, 20, 150);
    }

    if(motion.x <= ofGetWidth()*0.25 && movingLeft == true){
        ofSetColor(0, 0, 255);
        ofFill();
        ofRect(P1.x, P1.y, 50, 250);
    }
    
    if(motion.x >= ofGetWidth()*0.75 && movingRight == true){
        ofSetColor(0, 255, 0);
        ofFill();
        ofRect(P2.x, P2.y, 50, 250);
    }

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
