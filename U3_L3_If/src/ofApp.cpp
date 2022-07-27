#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
		
	x = 100;
	y = 100;
	w = 250;
	h = 230;
	state = false;

}

//--------------------------------------------------------------
void ofApp::update(){

	//if the mouse position in x is greater than the x position of the button
	//and the mouse position in x is lesser than the x position of the button plus its width
	//and if the mouse position in y is greater than the y position of the button
	//and the mouse position in y is lesser than the y position of the button plus its height
	//then the button is on

	if (ofGetMouseX() > x && ofGetMouseX() < x + w && ofGetMouseY() > y && ofGetMouseY() < y + h) {
	
		state = true;
	
	}
	else {
	
		state = false;

	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	if (state == true) {
		ofSetColor(0, 255, 0);
	}
	else {
		ofSetColor(255, 0, 0);
	}

	ofDrawRectangle(x, y, w, h);

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
