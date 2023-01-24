#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


	vidPlayer.load("finger.mov");
	vidPlayer.play();
	vidPlayer.setLoopState(OF_LOOP_NORMAL);

	

	//Important - reserve memory for the openCV images
	colorImg.allocate(320, 240);
	grayImg.allocate(320, 240);
	grayBg.allocate(320, 240);
	grayDiff.allocate(320, 240);


	gui.setup();
	gui.add(overallSpeed.setup("speed", 1, 0, 3));
	gui.add(noiseAmount.setup("noise", 1, 0, 3));
	gui.add(trail.setup("trail", 6.0, 0, 20));
	gui.add(threshold.setup("threshold", 80, 0, 255));
	gui.add(bLearnBackground.setup("capture bg", false));

	p.assign(600, particle());

	for (int i = 0; i < p.size(); i++) {
	
		p[i].setup();

	}

	ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetFrameRate(60);

	bool bNewFrame = false;


	
	vidPlayer.update();
	bNewFrame = vidPlayer.isFrameNew();

	

	if (bNewFrame == true) {
	
		//1 copy video pixels
		colorImg.setFromPixels(vidPlayer.getPixels());
		//2 convert to grayscale
		grayImg = colorImg;

		//capture background when clicking the capture background button
		if (bLearnBackground == true) {
			grayBg = grayImg;
			bLearnBackground = false;
		}

		//3 check the difference between captured background and current frame
		grayDiff.absDiff(grayBg, grayImg);
		//4 threshold in the grayscale image for better contours
		grayDiff.threshold(threshold);
		//5 find and create vectorial contours
		contourFinder.findContours(grayDiff, 20, (320 * 240)*0.9, 10, true);
	
	}


	//We copy points from the contours
	/*
	vector<ofVec2f>blobPts;
	for (int i = 0; i < contourFinder.nBlobs; i++) {
		for (int j = 0; j < contourFinder.blobs[i].pts.size(); j++) {
			blobPts.push_back(contourFinder.blobs[i].pts[j] * ofGetWidth() / 320);//*6
		}
	}
	*/

	for (int i = 0; i < p.size(); i++) {

		//the contour points are used to move the particles
		//p[i].repel(blobPts);

		p[i].update(overallSpeed,noiseAmount);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(0, 0, 0, trail);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	ofSetColor(255, 255, 255, 255);
	for (int i = 0; i < p.size(); i++) {

		p[i].draw(1);

	}


	// draw the incoming, the grayscale, the bg and the thresholded difference
	ofSetHexColor(0xffffff);
	colorImg.draw(20, 20);
	grayImg.draw(20+320, 20);
	grayBg.draw(20, 20+240);
	grayDiff.draw(20 + 320, 20 + 240);

	// then draw the contours:

	ofFill();
	ofSetHexColor(0x333333);
	//ofDrawRectangle(20, 540, camW, camH);
	ofSetHexColor(0xffffff);

	contourFinder.draw(20 + 320, 20 + 240);

	gui.draw();

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
