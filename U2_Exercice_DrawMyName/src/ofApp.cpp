#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	//Set the background color
	ofBackground(15, 30, 40);

	//The default line thickness is 1, here I set the line thickness to 3
	ofSetLineWidth(4);

	//P
	ofSetColor(138, 170, 183);
	ofDrawCircle(250, 250, 150);
	ofDrawRectangle(100, 100, 150, 300);
	ofLine(100, 100, 100, 500);

	//A
	ofSetColor(42, 157, 143);
	ofDrawTriangle(550, 400, 700, 100, 850, 400);
	ofLine(700, 100, 500, 500);
	ofLine(700, 100, 900, 500);

	//U
	ofSetColor(233, 196, 106);
	ofLine(1000, 100, 1000, 450);
	ofLine(1400, 100, 1400, 450);
	ofDrawCircle(1050, 450, 50);
	ofDrawCircle(1350, 450, 50);
	ofDrawRectangle(1000, 400, 400, 50);
	ofDrawRectangle(1050, 450, 300, 50);

	//L 
	ofSetColor(244, 162, 97);
	ofLine(1500, 100, 1500, 500);
	ofLine(1500, 500, 1900, 500);

	//!! extra - advanced !! - we use ofBeginShape() to create custom shapes
	//A star
	ofSetColor(231, 111, 81);
	ofBeginShape();
	ofVertex(1700, 135);
	ofVertex(1515, 135);
	ofVertex(1665, 25);
	ofVertex(1605, 200);
	ofVertex(1550, 25);
	ofEndShape();

	//!! extra - very advanced !! - we use cos and sin to create a symetrical star
	ofSetColor(244, 162, 97);
	ofBeginShape();
	ofVertex(1800 + (cos(ofDegToRad(0)) * 10), 200 + (sin(ofDegToRad(0)) * 10));
	ofVertex(1800 + (cos(ofDegToRad(30)) * 100), 200 + (sin(ofDegToRad(30)) * 100));
	ofVertex(1800 + (cos(ofDegToRad(60)) * 10), 200 + (sin(ofDegToRad(60)) * 10));
	ofVertex(1800 + (cos(ofDegToRad(90)) * 100), 200 + (sin(ofDegToRad(90)) * 100));
	ofVertex(1800 + (cos(ofDegToRad(120)) * 10), 200 + (sin(ofDegToRad(120)) * 10));
	ofVertex(1800 + (cos(ofDegToRad(150)) * 100), 200 + (sin(ofDegToRad(150)) * 100));
	ofVertex(1800 + (cos(ofDegToRad(180)) * 10), 200 + (sin(ofDegToRad(180)) * 10));
	ofVertex(1800 + (cos(ofDegToRad(210)) * 100), 200 + (sin(ofDegToRad(210)) * 100));
	ofVertex(1800 + (cos(ofDegToRad(240)) * 10), 200 + (sin(ofDegToRad(240)) * 10));
	ofVertex(1800 + (cos(ofDegToRad(270)) * 100), 200 + (sin(ofDegToRad(270)) * 100));
	ofVertex(1800 + (cos(ofDegToRad(300)) * 10), 200 + (sin(ofDegToRad(300)) * 10));
	ofVertex(1800 + (cos(ofDegToRad(330)) * 100), 200 + (sin(ofDegToRad(330)) * 100));
	ofEndShape();


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
