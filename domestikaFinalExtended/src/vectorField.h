#pragma once
#include "ofMain.h"

class vectorField
{
	public:
		vectorField();
		void setup(int innerWidth, int innerHeight, int outerWidth, int outerHeight);
		void noiseUpdate();
		ofVec2f getForceFromPos(ofVec2f pos);
		void draw();

		int fieldWidth;
		int fieldHeight;
		int fieldSize;
		int externalWidth;
		int externalHeight;

		vector<ofVec2f>field;


};
