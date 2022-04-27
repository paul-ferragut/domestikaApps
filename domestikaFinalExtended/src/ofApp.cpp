#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	camW = 320;
	camH = 240;

	cam.setup(camW, camH);

	colorImg.allocate(camW, camH);
	grayImage.allocate(camW, camH);
	grayBg.allocate(camW, camH);
	grayDiff.allocate(camW, camH);

	bLearnBackground = true;
	threshold = 80;

	ofSetVerticalSync(true);

	int num = 5000;
	p.assign(num, particle());
	
	resetParticles();

	vf.setup(ofGetWidth()/50, ofGetHeight()/50, ofGetWidth(), ofGetHeight());

	ofSetBackgroundAuto(false);
	ofSetFrameRate(160);

	col[0]=ofColor(247, 37, 133);
	col[1]=ofColor(114, 9, 183);
	col[2]=ofColor(58, 12, 163);
	col[3]=ofColor(67, 97, 238);
	col[4]=ofColor(76, 201, 240);

}

//--------------------------------------------------------------
void ofApp::resetParticles() {

	//these are the attraction points used in the forth demo 
	

	for (int i = 0; i < p.size(); i++) {
		p[i].setup();
	}
}

//--------------------------------------------------------------
void ofApp::update(){

	ofSetWindowTitle("FPS:" + ofToString(ofGetFrameRate()));
	bool bNewFrame = false;

	cam.update();

	bNewFrame = cam.isFrameNew();
	if (bNewFrame) {

		colorImg.setFromPixels(cam.getPixels());


		grayImage = colorImg;
		if (bLearnBackground == true) {
			grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
			bLearnBackground = false;
		}

		// take the abs value of the difference between background and incoming and then threshold:
		grayDiff.absDiff(grayBg, grayImage);
		grayDiff.threshold(threshold);

		// find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
		// also, find holes is set to true so we will get interior contours as well....
		contourFinder.findContours(grayDiff, 800, (340 * 240) / 3, 10, true);	// find holes
		
	}

	vector<ofVec2f>blobCentroids;
	for (int i = 0; i < contourFinder.nBlobs; i++) {
		blobCentroids.push_back(contourFinder.blobs[i].centroid*6);
	}

	vf.noiseUpdate();

	for ( int i = 0; i < p.size(); i++) {
		p[i].repel(blobCentroids);
		p[i].addForce(vf.getForceFromPos(p[i].pos));
		p[i].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofEnableAlphaBlending();
	ofSetColor(0,0,0,6);//ofMap(ofGetMouseX(), 0,ofGetWidth(), 0,255)
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());




	for (int i = 0; i < p.size(); i++) {
		ofSetColor(col[p[i].uniqueCol]);
		p[i].draw();
	}

	ofSetColor(255);
	//vf.draw();

	// draw the incoming, the grayscale, the bg and the thresholded difference
	ofSetHexColor(0xffffff);
	colorImg.draw(20, 20);
	grayImage.draw(360, 20);
	grayBg.draw(20, 280);
	grayDiff.draw(360, 280);

	// then draw the contours:

	ofFill();
	ofSetHexColor(0x333333);
	ofDrawRectangle(360, 540, 320, 240);
	ofSetHexColor(0xffffff);

	// we could draw the whole contour finder
	contourFinder.draw(360,540);

	// or, instead we can draw each blob individually from the blobs vector,
	// this is how to get access to them:
	/*
	for (int i = 0; i < contourFinder.nBlobs; i++) {
		contourFinder.blobs[i].draw(360, 540);

		// draw over the centroid if the blob is a hole
		ofSetColor(255);
		if (contourFinder.blobs[i].hole) {
			ofDrawBitmapString("hole",
				contourFinder.blobs[i].boundingRect.getCenter().x + 360,
				contourFinder.blobs[i].boundingRect.getCenter().y + 540);
		}


	}
	*/
	// finally, a report:
	ofSetHexColor(0xffffff);
	stringstream reportStr;
	reportStr << "bg subtraction and blob detection" << endl
		<< "press ' ' to capture bg" << endl
		<< "threshold " << threshold << " (press: +/-)" << endl
		<< "num blobs found " << contourFinder.nBlobs << ", fps: " << ofGetFrameRate();
	ofDrawBitmapString(reportStr.str(), 20, 600);




}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case ' ':
		bLearnBackground = true;
		break;
	case '+':
		threshold++;
		if (threshold > 255) threshold = 255;
		break;
	case '-':
		threshold--;
		if (threshold < 0) threshold = 0;
		break;
	}
	if (key == 'f') {
		ofToggleFullscreen();
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
