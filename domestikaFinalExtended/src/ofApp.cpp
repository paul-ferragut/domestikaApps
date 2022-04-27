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

	//bLearnBackground = true;
	//threshold = 80;

	ofSetVerticalSync(true);

	int num = 10000;
	p.assign(num, particle());
	
	resetParticles();

	vf.setup(ofGetWidth()/50, ofGetHeight()/50, ofGetWidth(), ofGetHeight());

	ofSetBackgroundAuto(false);
	ofSetFrameRate(160);



	gui.setup();
	gui.add(fullScreen.setup("fullScreen", false));
	gui.add(showCV.setup("showCV",true));
	gui.add(thresholdCV.setup("thresholdCV",150,0,255));

	gui.add(captureBackground.setup("captureBackground", true));
	gui.add(showVectorField.setup("showVectorField", false));

	gui.add(vectorFieldStrenght.setup("vectorFieldStrenght", 0.3, 0.0, 1.0));
	gui.add(noiseStrenght.setup("noiseStrenght", 0.2, 0.0, 0.6));
	gui.add(overallSpeed.setup("overallSpeed", 1.0, 0.01, 4.0));

	gui.add(lenghtTrail.setup("lenghtTrail", 6.0, 0.0, 20));
	gui.add(sizeDots.setup("sizeDots", 0.4, 0.01,5));
	gui.add(color[0].setup("color1",ofColor(247, 37, 133), ofColor(0, 0, 0), ofColor(255, 255, 255)));
	gui.add(color[1].setup("color2",ofColor(114, 9, 183), ofColor(0, 0, 0), ofColor(255, 255, 255)));
	gui.add(color[2].setup("color3",ofColor(58, 12, 163), ofColor(0, 0, 0), ofColor(255, 255, 255)));
	gui.add(color[3].setup("color4",ofColor(67, 97, 238), ofColor(0, 0, 0), ofColor(255, 255, 255)));



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
		colorImg.mirror(false, true);


		grayImage = colorImg;
		if (captureBackground == true) {
			grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg (operator overloading)
			captureBackground = false;
		}

		// take the abs value of the difference between background and incoming and then threshold:
		grayDiff.absDiff(grayBg, grayImage);
		grayDiff.threshold(thresholdCV);

		// find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
		// also, find holes is set to true so we will get interior contours as well....
		contourFinder.findContours(grayDiff, 800, (340 * 240) / 3, 10, true);	// find holes
		
	}

	//vector<ofVec2f>blobCentroids;
	vector<ofVec2f>blobPts;
	for (int i = 0; i < contourFinder.nBlobs; i++) {
		for (int j = 0; j < contourFinder.blobs[i].pts.size(); j++) {
			blobPts.push_back(contourFinder.blobs[i].pts[j] * ofGetWidth()/camW);//*6
			//blobCentroids.push_back(contourFinder.blobs[i].centroid*6);
		}
	}

	vf.noiseUpdate();

	for ( int i = 0; i < p.size(); i++) {
		//p[i].repel(blobCentroids);
		p[i].repel(blobPts);
		p[i].addForce(vf.getForceFromPos(p[i].pos)*vectorFieldStrenght);
		p[i].update(overallSpeed, noiseStrenght);
	}


	if (fullScreen) {
		ofToggleFullscreen();
		fullScreen = false;
	}


}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofEnableAlphaBlending();
	ofSetColor(0,0,0,lenghtTrail);//ofMap(ofGetMouseX(), 0,ofGetWidth(), 0,255)
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());




	for (int i = 0; i < p.size(); i++) {
		ofSetColor(color[p[i].uniqueCol]);
		p[i].draw(sizeDots);
	}

	ofSetColor(255);
	if(showVectorField){
		vf.draw();
	}

	if (showCV) {
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
		contourFinder.draw(360, 540);
	}
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
	/*
	// finally, a report:
	ofSetHexColor(0xffffff);
	stringstream reportStr;
	reportStr << "bg subtraction and blob detection" << endl
		<< "press ' ' to capture bg" << endl
		<< "threshold " << threshold << " (press: +/-)" << endl
		<< "num blobs found " << contourFinder.nBlobs << ", fps: " << ofGetFrameRate();
	ofDrawBitmapString(reportStr.str(), 20, 600);
	*/

	gui.draw();


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
