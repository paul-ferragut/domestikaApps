#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	myGlobalVar = 2354;

}

//--------------------------------------------------------------
void ofApp::update(){

	//testing variable scope
	//cout << myGlobalVar << endl;

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	drawCross(ofGetMouseX(), ofGetMouseY(), 600);

	//uncomment below to test the values being returned
	//cout << drawCross(ofGetMouseX(), ofGetMouseY(), 600) << endl;

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
ofVec2f ofApp::drawCross(float x, float y,float size) {
	
	//This way we manipulate the rectangle from their center
	ofSetRectMode(OF_RECTMODE_CENTER);
	

	ofDrawRectangle(x, y, size / 10, size);
	ofDrawRectangle(x, y, size, size / 10);

	//return bottom right corner
	return ofVec2f(x + size, y + size);

}