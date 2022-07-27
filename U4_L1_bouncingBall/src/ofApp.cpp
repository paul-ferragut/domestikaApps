#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//Random initial position
	pos.x = ofRandom(0, ofGetWidth());
	pos.y = ofRandom(0, ofGetHeight());

	//Random initial velocity
	vel.x = ofRandom(-30, 30);
	vel.y = ofRandom(-30, 30);

}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetFrameRate(60);
	
	//we add velocity to the position for everyframe
	pos += vel;

	//we invert the velocity (direction) when the dot hit a wall
	if ((pos.x > ofGetWidth()) || (pos.x < 0)) {
	
		vel.x *= -1;

	}

	if ((pos.y > ofGetHeight()) || (pos.y < 0)) {
	
		vel.y *= -1;

	}


}

//--------------------------------------------------------------
void ofApp::draw(){

	ofDrawCircle(pos.x, pos.y, 40);

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
