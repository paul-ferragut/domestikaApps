#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//Here change the number of particles
	p.assign(800, particle());


	for (int i = 0; i < p.size(); i++) {
	
		p[i].setup();

	}

}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetFrameRate(60);


	ofVec2f windForce;
	windForce.x = ofNoise(ofGetElapsedTimeMillis()*0.001);//Strong wind from left to right - using noise the wind intensity is looking organic
	windForce.y=((ofNoise(ofGetElapsedTimeMillis()*0.005)*2)-1)*0.5;//mild wind shaking particles up and down
	ofVec2f gravity;
	gravity.x = 0;
	gravity.y = 0.2;

	float overallSpeed=0.7;
	float noiseAmount=0.2;

	for (int i = 0; i < p.size(); i++) {

		p[i].resetForce();
		p[i].addForce(windForce);

		//p[i].addForce(gravity);
		//Gravity is stronger for larger size particles, as if large particles are heavier
		p[i].addForce(gravity*ofMap(p[i].size,2,5,0,3));

		p[i].update(overallSpeed,noiseAmount);

	}

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(0, 0, 10);
	ofSetColor(255, 255, 255, 255);
	for (int i = 0; i < p.size(); i++) {

		p[i].draw(1);

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
