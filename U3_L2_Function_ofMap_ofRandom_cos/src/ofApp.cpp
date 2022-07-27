#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetFrameRate(60);

	//Background color change according to the mouse position
	ofBackground(ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 255), ofMap(ofGetMouseX(),0,ofGetWidth(),0,255), 100);

	//Random position for every frame
	ofDrawCircle(400, ofRandom(ofGetHeight()), 200);
	
	//smooth cyclic motion using sin
	//sin is smoothly oscillating between -1 and 1, we map it to our screen height
	
	ofSetColor(0, 0, 0);
	ofDrawCircle(ofGetWidth() / 2, ofMap(sin(ofGetElapsedTimeMillis()*0.005), -1, 1, 0, ofGetHeight()), 200);
	//cout << sin(ofGetElapsedTimeMillis()) << endl;
	
	//smooth random motion using noise
	ofDrawCircle(ofGetWidth() - 400, ofMap(ofNoise(ofGetElapsedTimef()), 0, 1, 0, ofGetHeight()), 200);

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
