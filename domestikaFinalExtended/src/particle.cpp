#include "particle.h"

//------------------------------------------------------------------
particle::particle() {
	
}

//------------------------------------------------------------------
void particle::setup() {
	//the unique val allows us to set properties slightly differently for each particle
	uniqueVal.x = ofRandom(-10000, 10000);
	uniqueVal.y = ofRandom(-10000, 10000);

	uniqueCol = ofRandom(0, 5);

	pos.x = ofRandomWidth();
	pos.y = ofRandomHeight();


	vel.x = ofRandom(-4, 4);
	vel.y = ofRandom(-4, 4);

	frc = ofVec2f(0, 0);
	repelFrc = ofVec2f(0, 0);
	additionalFrc = ofVec2f(0, 0);

	scale = ofRandom(3, 5);

	//if (mode == PARTICLE_MODE_NOISE) {
		drag = ofRandom(0.97, 0.99);
		//vel.y = fabs(vel.y) * 3.0; //make the particles all be going down
	//}
	//else {
	//	drag = ofRandom(0.95, 0.998);
	//}
}

//------------------------------------------------------------------
void particle::update() {

	//1 - APPLY THE FORCES BASED ON WHICH MODE WE ARE IN 
	/*
	if (mode == PARTICLE_MODE_ATTRACT) {
		glm::vec3 attractPt(ofGetMouseX(), ofGetMouseY(), 0);
		frc = attractPt - pos; // we get the attraction force/vector by looking at the mouse pos relative to our pos
		frc = glm::normalize(frc); //by normalizing we disregard how close the particle is to the attraction point

		vel *= drag; //apply drag
		vel += frc * 0.6; //apply force
	}
	else if (mode == PARTICLE_MODE_REPEL) {
		glm::vec3 attractPt(ofGetMouseX(), ofGetMouseY(), 0);
		frc = attractPt - pos;

		//let get the distance and only repel points close to the mouse
		float dist = glm::length(frc);
		frc = glm::normalize(frc);

		vel *= drag;
		if (dist < 150) {
			vel += -frc * 0.6; //notice the frc is negative 
		}
		else {
			//if the particles are not close to us, lets add a little bit of random movement using noise. this is where uniqueVal comes in handy. 			
			frc.x = ofSignedNoise(uniqueVal, pos.y * 0.01, ofGetElapsedTimef() * 0.2);
			frc.y = ofSignedNoise(uniqueVal, pos.x * 0.01, ofGetElapsedTimef() * 0.2);
			vel += frc * 0.04;
		}
	}
	else if (mode == PARTICLE_MODE_NOISE) {*/
		//lets simulate falling snow 
		//the fake wind is meant to add a shift to the particles based on where in x they are
		//we add pos.y as an arg so to prevent obvious vertical banding around x values - try removing the pos.y * 0.006 to see the banding
	//	float fakeWindX = ofSignedNoise(pos.x * 0.003, pos.y * 0.006, ofGetElapsedTimef() * 0.6);

	//	frc.x = fakeWindX * 0.25 + ofSignedNoise(uniqueVal, pos.y * 0.04) * 0.6;
	//	frc.y = ofSignedNoise(uniqueVal, pos.x * 0.006, ofGetElapsedTimef() * 0.2) * 0.09 + 0.18;

		frc.x = ofSignedNoise(uniqueVal.x, ofGetElapsedTimeMillis());
		frc.y = ofSignedNoise(uniqueVal.y, ofGetElapsedTimeMillis());



		vel *= drag;

		vel -= repelFrc * 0.001;

		vel += additionalFrc*0.3;

		vel += frc * 0.2;

		//we do this so as to skip the bounds check for the bottom and make the particles go back to the top of the screen
		//if (pos.y + vel.y > ofGetHeight()) {
			//pos.y -= ofGetHeight();
		//}
	/*}
	else if (mode == PARTICLE_MODE_NEAREST_POINTS) {

		if (attractPoints) {

			//1 - find closest attractPoint 
			glm::vec3 closestPt;
			int closest = -1;
			float closestDist = 9999999;

			for (unsigned int i = 0; i < attractPoints->size(); i++) {
				float lenSq = glm::length2(attractPoints->at(i) - pos);
				if (lenSq < closestDist) {
					closestDist = lenSq;
					closest = i;
				}
			}

			//2 - if we have a closest point - lets calcuate the force towards it
			if (closest != -1) {
				closestPt = attractPoints->at(closest);
				float dist = sqrt(closestDist);

				//in this case we don't normalize as we want to have the force proportional to distance 
				frc = closestPt - pos;

				vel *= drag;

				//lets also limit our attraction to a certain distance and don't apply if 'f' key is pressed
				if (dist < 300 && dist > 40 && !ofGetKeyPressed('f')) {
					vel += frc * 0.003;
				}
				else {
					//if the particles are not close to us, lets add a little bit of random movement using noise. this is where uniqueVal comes in handy. 			
					frc.x = ofSignedNoise(uniqueVal, pos.y * 0.01, ofGetElapsedTimef() * 0.2);
					frc.y = ofSignedNoise(uniqueVal, pos.x * 0.01, ofGetElapsedTimef() * 0.2);
					vel += frc * 0.4;
				}

			}

		}

	}
	*/
	//RESET AT BORDER
	if (pos.x + vel.x > ofGetWidth()) {
		pos.x -= ofGetWidth();
	}
	else if (pos.x + vel.x <0) {
		pos.x += ofGetWidth();
	}

	if (pos.y + vel.y > ofGetHeight()) {
		pos.y -= ofGetHeight();
	}
	else if (pos.y + vel.y < 0) {
		pos.y += ofGetHeight();
	}



	//2 - UPDATE OUR POSITION

	pos += vel;


	//3 - (optional) LIMIT THE PARTICLES TO STAY ON SCREEN 
	//we could also pass in bounds to check - or alternatively do this at the ofApp level
	if (pos.x > ofGetWidth()) {
		pos.x = ofGetWidth();
		vel.x *= -1.0;
	}
	else if (pos.x < 0) {
		pos.x = 0;
		vel.x *= -1.0;
	}
	if (pos.y > ofGetHeight()) {
		pos.y = ofGetHeight();
		vel.y *= -1.0;
	}
	else if (pos.y < 0) {
		pos.y = 0;
		vel.y *= -1.0;
	}

}


//------------------------------------------------------------------
void particle::repel(vector<ofVec2f>repelPt){

	repelFrc.set(0,0);

	for (int i = 0; i < repelPt.size(); i++) {
		//glm::vec3 attractPt(ofGetMouseX(), ofGetMouseY(), 0);
		float dist = pos.distance(repelPt[i]);
		
	
		
		if (dist < 150) {

			ofVec2f newRepelPt;
			newRepelPt = repelPt[i] - pos; // we get the attraction force/vector by looking at the mouse pos relative to our pos
			repelFrc += newRepelPt;// .normalized(); //by normalizing we disregard how close the particle is to the attraction point

		}
		//vel *= drag; //apply drag
		//vel += frc * 0.1; //apply force
	}

}

//------------------------------------------------------------------
void particle::addForce(ofVec2f addFrc) {

	additionalFrc.set(0, 0);
	additionalFrc += addFrc;
}


//------------------------------------------------------------------
void particle::draw() {

	//ofSetColor(255,255,255);
	/*
	if (mode == PARTICLE_MODE_ATTRACT) {
		ofSetColor(255, 63, 180);
	}
	else if (mode == PARTICLE_MODE_REPEL) {
		ofSetColor(208, 255, 63);
	}
	else if (mode == PARTICLE_MODE_NOISE) {
		ofSetColor(99, 63, 255);
	}
	else if (mode == PARTICLE_MODE_NEAREST_POINTS) {
		ofSetColor(103, 160, 237);
	}*/

	ofDrawCircle(pos.x, pos.y, scale);
}
