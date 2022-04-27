#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"
#include "particle.h"
#include "vectorField.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofVideoGrabber cam;
		int camW;
		int camH;

		ofxCvColorImage colorImg;

		ofxCvGrayscaleImage	grayImage;
		ofxCvGrayscaleImage	grayBg;
		ofxCvGrayscaleImage	grayDiff;

		ofxCvContourFinder contourFinder;

		int threshold;
		bool bLearnBackground;

		void resetParticles();
		vector<particle>p;

		ofColor col[5];

		vectorField vf;
		
};
