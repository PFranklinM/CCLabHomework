#pragma once

#include "ofMain.h"
#include "ofxMotionDetector.h"
#include "ofxOpenCv.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    int camW;
    int camH;
  

    
    int w, h;
    
    ofVideoGrabber vidGrabber;
    
    ofxCvColorImage colorImg;
    ofxCvGrayscaleImage grayImg;
    ofxCvGrayscaleImage grayPrevImg;
    ofxCvGrayscaleImage diffImg;
    ofxCvGrayscaleImage binaryImg;
    
    ofxCvContourFinder contourFinder;
    
    bool isMotionDetected;
    
    bool drawGui;
    
    ofxGuiGroup gui;
    ofxLabel guiHelp;
    
    ofxIntSlider imgThreshold;
    ofxIntSlider minArea;
    ofxIntSlider maxArea;
    
    ofxToggle vMirror;
    ofxToggle hMirror;
    ofxToggle debugView;
    
    ofxLabel motionStatus;
    
    int xMin;
    int xMax;
    int yMin;
    int yMax;
    
    int xVel;
    int yVel;
    
    int goalieVelP1A;
    int goalieVelP1B;
    
    int goalieVelP2A;
    int goalieVelP2B;
    
    int player1Score;
    int player2Score;
    
    int counter;
    
//    bool isHit;
    
    ofVec2f motion;
    
    ofVec2f pos;
    
    ofVec2f P1;
    ofVec2f P2;
    
    ofVec2f goalieP1A;
    ofVec2f goalieP1B;
    
    ofVec2f goalieP2A;
    ofVec2f goalieP2B;
    
    
    bool movingRight;
    bool movingLeft;
    
    int rightSide = ofGetWidth()*0.66;
    int leftSide = ofGetWidth()*0.33;
    

		
};
