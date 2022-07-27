#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//testing a simple loop

	cout << "before the loop" << endl;

	for (int i = 0; i < 10; i++) {
		cout << "i:" << i << endl;
	}

	cout << "after the loop" << endl;

}

//--------------------------------------------------------------
void ofApp::update(){






}

//--------------------------------------------------------------
void ofApp::draw(){

	//ofSetFrameRate
	//grid of dots
	for (int i = 0; i < 150; i++) {//for the columns
	
		for (int j = 0; j < 100; j++) {//for the rows
		
			ofDrawCircle(i * 15, j * 15, ofRandom(0,5));
		
		}

	}

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
