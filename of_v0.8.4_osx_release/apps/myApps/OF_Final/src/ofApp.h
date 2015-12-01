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
    
    int camW= 1280;
    int camH= 720;
  

    
    int w, h;
    
    ofVideoGrabber vidGrabber;
    
    ofxCvColorImage colorImg;
    ofxCvGrayscaleImage grayImg;
    ofxCvGrayscaleImage grayPrevImg;
    ofxCvGrayscaleImage diffImg;
    ofxCvGrayscaleImage binaryImg;
    
    ofxCvContourFinder contourFinder;
    
    bool			isMotionDetected;
    
    bool			drawGui;
    
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
    
    int player1Score;
    int player2Score;
    
    int counter;
    
    bool isHit;
    
    ofVec2f motion;
    
    ofVec2f pos;

		
};
