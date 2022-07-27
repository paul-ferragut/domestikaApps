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
	

	//From Bridget Riley Movement in Squares 1961 https://www.maxhetzler.com/artists/bridget-riley/selected-works#img11494

	float spacing = 40;
	int numSquare = 60;
	float lastXpos = 0;

	for (int i = 0; i < numSquare/2; i++) {//this loop is for rows
		for (int j = 0; j < numSquare; j++) {//this loop is for columns

			//to create checkerboard black and white I used the modulo % 
			if (j % 2) { 
				ofSetColor(0, 0, 0);
				if (i % 2) {
					ofSetColor(255, 255, 255);
				}
			}
			else {
				ofSetColor(255, 255, 255);
				if (i % 2) {
					ofSetColor(0, 0, 0);
				}
			}

	
			//j which represent our current column number is used with cos
			//+ofGetElapsedTimef() adds animation
			float value = cos(j*0.1+ofGetElapsedTimef());

			//we map cos value between -1 and 1 to our square width
			float newWidth=ofMap(value,-1,1,0,spacing);

			ofDrawRectangle(lastXpos, i* spacing, newWidth, spacing);

			//the next position x must be the previous square position x + the newWidth
			lastXpos +=  newWidth;

			//For every new row we must reset the value
			if (j == numSquare-1 ) {
				lastXpos = 0;
			}
		}
	}

	
	//From Bridget Riley Blaze IV 1963 https://artcollection.culture.gov.uk/artwork/10957/

	
	//This is how to draw a circle points after points, this will be helpful to test before checking the example
	/*
	float radius=300;
	int circleResolution = 30;
	int centerPositionX = 1500;
	int centerPositionY = 600;
	ofBeginShape();
	for (int i = 0; i < circleResolution; i ++) {
		ofVertex(centerPositionX +cos(ofMap(i, 0, circleResolution, 0, TWO_PI))*radius, centerPositionY +sin(ofMap(i, 0, circleResolution, 0, TWO_PI))*radius);
	}
	ofEndShape();
	*/
	

	int stripes = 120;
	int centerX = 1920;
	int centerY = 600;

	float lastRadius = 20;
	float nextRadius = 60;

	float tilt = 0.2;

	float t = ofGetElapsedTimef()*0.1;

	for (int j = 0; j < 8; j++) {//For the group of concentric stripes

		for (int i = 0; i < stripes; i += 2) {//we draw stripes here


			ofBeginShape();

			//for each concentric stripe group we switch the tilt orientation
			if (j % 2) {
				tilt = -0.2;
			}
			else {
				tilt = 0.2;
			}

			//Each stripe is made of 4 points
			ofVertex(
				centerX + (cos(t*j + ofMap(i, 0, stripes, 0, TWO_PI)+((j-1) * tilt))*lastRadius),
				centerY + (sin(t*j + ofMap(i, 0, stripes, 0, TWO_PI)+ ((j - 1) * tilt))*lastRadius));

			ofVertex(
				centerX + (cos(t*j + ofMap(i + 1, 0, stripes, 0, TWO_PI)+ ((j - 1) * tilt))*lastRadius),
				centerY + (sin(t*j + ofMap(i + 1, 0, stripes, 0, TWO_PI)+ ((j - 1) * tilt))*lastRadius));

			ofVertex(
				centerX + (cos(t*j + ofMap(i + 1, 0, stripes, 0, TWO_PI)+ j * tilt)*(lastRadius + nextRadius)),
				centerY + (sin(t*j + ofMap(i + 1, 0, stripes, 0, TWO_PI) + j * tilt)*(lastRadius + nextRadius)));

			ofVertex(
				centerX + (cos(t*j + ofMap(i, 0, stripes, 0, TWO_PI) + j * tilt)*(lastRadius + nextRadius)),
				centerY + (sin(t*j + ofMap(i, 0, stripes, 0, TWO_PI) + j * tilt)*(lastRadius + nextRadius)));

			ofEndShape();
		}
		lastRadius += nextRadius;

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
