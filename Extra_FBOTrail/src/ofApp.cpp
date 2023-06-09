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

	int num = 5000;
	p.assign(num, particle());
	
	resetParticles();

	//Extra vector field for organic movement
	vf.setup(ofGetWidth()/50, ofGetHeight()/50, ofGetWidth(), ofGetHeight());

	//ofSetBackgroundAuto(false);
	//ofSetFrameRate(160);



	gui.setup();
	gui.add(fullScreen.setup("toggle fullScreen", false));
	gui.add(showCV.setup("showCV",true));
	gui.add(thresholdCV.setup("thresholdCV",150,0,255));

	gui.add(captureBackground.setup("captureBackground", true));
	gui.add(showVectorField.setup("showVectorField", false));

	gui.add(vectorFieldStrenght.setup("vectorFieldStrenght", 0.3, 0.0, 1.0));
	gui.add(noiseStrenght.setup("noiseStrenght", 0.2, 0.0, 0.6));
	gui.add(overallSpeed.setup("overallSpeed", 1.0, 0.01, 4.0));

	gui.add(lenghtTrail.setup("lenghtTrail", 6.0, 0.0, 200));
	gui.add(sizeDots.setup("sizeDots", 0.4, 0.01,5));
	gui.add(color[0].setup("color1",ofColor(247, 37, 133), ofColor(0, 0, 0), ofColor(255, 255, 255)));
	gui.add(color[1].setup("color2",ofColor(114, 9, 183), ofColor(0, 0, 0), ofColor(255, 255, 255)));
	gui.add(color[2].setup("color3",ofColor(58, 12, 163), ofColor(0, 0, 0), ofColor(255, 255, 255)));
	gui.add(color[3].setup("color4",ofColor(67, 97, 238), ofColor(0, 0, 0), ofColor(255, 255, 255)));

	//NICER TRAILS
	Fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB); // with alpha, 32 bits red, 32 bits green, 32 bits blue, 32 bits alpha, from 0 to 1 in 'infinite' steps
	
	//FASTER
	//Fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA); // with alpha, 8 bits red, 8 bits green, 8 bits blue, 8 bits alpha, from 0 to 255 in 256 steps

	Fbo.begin();
	ofClear(255, 255, 255, 0);
	Fbo.end();
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
			grayBg = grayImage;		// the = sign copys the pixels from grayImage into grayBg 
			captureBackground = false;
		}

		// take the abs value of the difference between background and incoming and then threshold:
		grayDiff.absDiff(grayBg, grayImage);
		grayDiff.threshold(thresholdCV);

		// find contours 
		// also, find holes is set to true so we will get interior contours as well....
		contourFinder.findContours(grayDiff, 200, (camW * camH) *0.9, 10, true);	// find holes
		
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
		//Extra vector field for organic movement
		p[i].addForce(vf.getForceFromPos(p[i].pos)*vectorFieldStrenght);
		p[i].update(overallSpeed, noiseStrenght);
	}


	ofEnableAlphaBlending();

	//lets draw some graphics into our fbo
	Fbo.begin();


	ofSetColor(0, 0, 0, lenghtTrail);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	for (int i = 0; i < p.size(); i++) {
		ofSetColor(color[p[i].uniqueCol]);
		p[i].draw(sizeDots);
	}


	Fbo.end();


	if (fullScreen) {
		ofToggleFullscreen();
		fullScreen = false;
	}


}

//--------------------------------------------------------------
void ofApp::draw(){

	
	
	ofSetColor(0, 0, 0, 255);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	ofSetColor(255, 255, 255,255);
	Fbo.draw(0, 0);


	ofSetColor(255);
	if (showVectorField) {
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
