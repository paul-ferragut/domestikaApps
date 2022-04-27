#include "vectorField.h"

//------------------------------------------------------------------
vectorField::vectorField() {

}

//------------------------------------------------------------------
void vectorField::setup(int innerWidth, int innerHeight, int outerWidth, int outerHeight) {

	fieldWidth = innerWidth;
	fieldHeight = innerHeight;
	externalWidth = outerWidth;
	externalHeight = outerHeight;
	fieldSize = fieldWidth * fieldHeight;

	for (int i = 0; i < fieldSize; i++) {
		ofVec2f pt;
		pt.set(0, 0);
		field.push_back(pt);
	}

}

//------------------------------------------------------------------
void vectorField::noiseUpdate() {

	for (int i = 0; i < fieldWidth; i++) {
		for (int j = 0; j < fieldHeight; j++) {

			int pos = j * fieldWidth + i;
			float scaleNoise = 0.1;
			float scaleTime = 0.1;
			field[pos].x = ofSignedNoise(i* scaleNoise, j * scaleNoise, ofGetElapsedTimef()* scaleTime);
			field[pos].y = ofSignedNoise(i * scaleNoise, j * scaleNoise, ofGetElapsedTimef() * scaleTime +1000);

		}
	}


}

//------------------------------------------------------------------------------------
void vectorField::draw() {

	float scaleX = (float)externalWidth / (float)fieldWidth;
	float scaleY = (float)externalHeight / (float)fieldHeight;

	for (int i = 0; i < fieldWidth; i++) {
		for (int j = 0; j < fieldHeight; j++) {

			// pos in array
			int pos = j * fieldWidth + i;
			// pos externally
			float px = i * scaleX;
			float py = j * scaleY;
			float px2 = px + field[pos].x * 50;
			float py2 = py + field[pos].y * 50;

			//ofDrawLine(px, py, px2, py2);
			ofDrawArrow(ofVec3f(px, py,0), ofVec3f(px2, py2,0), 2);
			/*
			// draw an baseline to show direction
			// get the line as vector, calculate length, then normalize. 
			// rotate and draw based on length
			
			ofVec2f line;
			line.set(px2-px, py2-py);
			float length = line.length();
			line.normalize();
			line.rotate(90);  // these are angles in degrees
			ofLine(px - line.x*length*0.2, py - line.y*length*0.2, px + line.x*length*0.2, py + line.y*length*0.2);
			*/
		}
	}
}

//------------------------------------------------------------------------------------
ofVec2f vectorField::getForceFromPos(ofVec2f pos)
{
	ofVec2f forceFromPos;

	//convert pos to percent
	ofVec2f posPct;
	posPct.x = pos.x / (float)externalWidth;
	posPct.y = pos.y / (float)externalHeight;

	//position in the field
	int fieldPosX = (int)(posPct.x * fieldWidth);
	int fieldPosY = (int)(posPct.y * fieldHeight);

	//position in array
	int posArray = fieldPosY * fieldWidth + fieldPosX;

	forceFromPos = field[posArray]*0.1;

	return forceFromPos;
}