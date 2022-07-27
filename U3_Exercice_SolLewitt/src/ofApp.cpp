#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


}

//--------------------------------------------------------------
void ofApp::update(){



}

//--------------------------------------------------------------
void ofApp::draw(){


	ofSetFrameRate(1);

	ofSetLineWidth(2);

	ofBackground(100, 100, 100);

	//Red lines from the midpoints of four sides;
	ofSetColor(255, 0, 0);

	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, ofGetHeight() / 2);

	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth()/2, 0);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, 0);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, 0);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, 0);

	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() , ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth(), ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth(), ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth(), ofGetHeight() / 2);

	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight());
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight());
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight());
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight());



	//Blue lines from the four corners;
	ofSetColor(0, 0, 255);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, 0);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, 0);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, 0);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, 0);

	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth(), 0);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth(), 0);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth(), 0);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth(), 0);

	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, ofGetHeight());
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, ofGetHeight());
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, ofGetHeight());
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, ofGetHeight());

	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth(), ofGetHeight());
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth(), ofGetHeight());
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth(), ofGetHeight());
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth(), ofGetHeight());

	//Yellow lines from the center;
	ofSetColor(255, 255, 0);

	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight() / 2);
	ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight() / 2);


	//Advanced version using loops - learn about loops in Unit 4 - lesson 2
	/*
	ofBackground(0, 0, 0);
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	//Red lines from the midpoints of four sides;
	ofSetColor(255, 0, 0);


	for (int i = 0; i < 50; i++) {
		ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, ofGetHeight() / 2);
		ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, 0);
		ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth(), ofGetHeight() / 2);
		ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight());
	}

	//Blue lines from the four corners;
	ofSetColor(0, 0, 255);

	for (int i = 0; i < 50; i++) {
		ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, 0);
		ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth(), 0);
		ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), 0, ofGetHeight());
		ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth(), ofGetHeight());
	}

	//Yellow lines from the center;
	ofSetColor(255, 255, 0);

	for (int i = 0; i < 200; i++) {
		ofDrawLine(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofGetWidth() / 2, ofGetHeight() / 2);
	}
	*/
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

//--------------------------------------------------------------
void ofApp::drawCross(int x, int y, int size) {



}