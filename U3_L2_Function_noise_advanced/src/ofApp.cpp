#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	//advanced demo to understand multiple dimensions of noise

	float noiseStep = 0.04;

	ofPushMatrix();
		ofTranslate(ofLerp(0, ofGetWidth(),(1.0/4)*1)-100, ofLerp(0, ofGetHeight(), (1.0 / 3) * 1) - 100);
		ofSetColor(255, 255);
		ofDrawBitmapStringHighlight("1D noise",0, -30);
		for (int i = 0; i < 200; i++) {
			ofSetColor(ofMap(ofNoise((i*noiseStep)+ofGetElapsedTimef()), 0, 1.0, 0, 255));
			ofDrawRectangle(0, i, 200, 1);
		}
	ofPopMatrix();
	

	ofPushMatrix();
	ofTranslate(ofLerp(0, ofGetWidth(), (1.0 / 4) * 2) - 100, ofLerp(0, ofGetHeight(), (1.0 / 3) * 1) - 100);
		ofSetColor(255, 255);
		ofDrawBitmapStringHighlight("2D noise", 0, -30);
		for (int i = 0; i < 200; i++) {
			for (int j = 0; j < 200; j++) {

				ofSetColor(ofMap(ofNoise(i*noiseStep, j*noiseStep), 0, 1.0, 0, 255));
				ofDrawRectangle(i, j, 1, 1);

			}
		}
	ofPopMatrix();



	ofPushMatrix();
	ofTranslate(ofLerp(0, ofGetWidth(), (1.0 / 4) * 3) - 100, ofLerp(0, ofGetHeight(), (1.0 / 3) * 1) - 100);
		ofSetColor(255, 255);
		ofDrawBitmapStringHighlight("2D noise with x and y increment", 0, -30);
		for (int i = 0; i < 200; i++) {
			for (int j = 0; j < 200; j++) {

				ofSetColor(ofMap(ofNoise(i*noiseStep+ofGetElapsedTimef(), j*noiseStep + ofGetElapsedTimef()), 0, 1.0, 0, 255));
				ofDrawRectangle(i, j, 1, 1);

			}
		}
	ofPopMatrix();


	ofPushMatrix();
		ofSetColor(255, 255);
		ofTranslate(ofLerp(0, ofGetWidth(), (1.0 / 4) * 1) - 100, ofLerp(0, ofGetHeight(), (1.0 / 3) * 2) - 100);
		ofDrawBitmapStringHighlight("3D noise used in 2D, 3rd value increment", 0, -30);
		for (int i = 0; i < 200; i++) {
			for (int j = 0; j < 200; j++) {

				ofSetColor(ofMap(ofNoise(i*noiseStep , j*noiseStep , ofGetElapsedTimef()), 0, 1.0, 0, 255));
				ofDrawRectangle(i, j, 1, 1);

			}
		}
	ofPopMatrix();

	ofEnableDepthTest();
	ofPushMatrix();
		ofTranslate(ofLerp(0, ofGetWidth(), (1.0 / 4) * 2) - 100, ofLerp(0, ofGetHeight(), (1.0 / 3) * 2) - 100);
		ofSetColor(255, 255);
		ofDrawBitmapStringHighlight("3D noise", 0, -30);
		ofTranslate(75, 75,75);
		ofRotate(ofGetElapsedTimeMillis()*0.01, 0.5, 0.5, 0.5);
		ofTranslate(-75, -75, -75);
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++) {
				for (int k = 0; k < 30; k++) {
					ofSetColor(ofMap(ofNoise(i*noiseStep,j*noiseStep,k*noiseStep), 0, 1.0, 0, 255),100);
					ofDrawBox(i*5, j * 5, k * 5, 5 ,5, 5);
				}
			}
		}
	ofPopMatrix();


	ofPushMatrix();
		ofTranslate(ofLerp(0, ofGetWidth(), (1.0 / 4) * 3) - 100, ofLerp(0, ofGetHeight(), (1.0 / 3) * 2) - 100);
		ofSetColor(255, 255);
		ofDrawBitmapStringHighlight("4D noise, 4th value increment", 0, -30);
		ofTranslate(75, 75, 75);
		ofRotate(ofGetElapsedTimeMillis()*0.01, 0.5, 0.5, 0.5);
		ofTranslate(-75, -75, -75);
		for (int i = 0; i < 30; i++) {
			for (int j = 0; j < 30; j++) {
				for (int k = 0; k < 30; k++) {
					ofSetColor(ofMap(ofNoise(i*noiseStep, j*noiseStep, k*noiseStep, ofGetElapsedTimef()), 0, 1.0, 0, 255), 100);
					ofDrawBox(i * 5, j * 5, k * 5, 5, 5, 5);
				}
			}
		}
	ofPopMatrix();

	
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
