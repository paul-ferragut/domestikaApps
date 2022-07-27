#pragma once
#include "ofMain.h"

class particle
{
	public:
		particle();

		void setup();
		void update(float speed,float noise);
		void draw(float sizeDot);
		void repel(vector<ofVec2f>repelPt);
		void addForce(ofVec2f addFrc);
		
		ofVec2f pos;
		ofVec2f vel;
		ofVec2f frc;
		ofVec2f repelFrc;
		ofVec2f additionalFrc;

		float drag;
		ofVec2f uniqueVal;
		float scale;

		int uniqueCol;

};

