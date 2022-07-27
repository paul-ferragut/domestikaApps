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


	void resetForce();
	void addForce(ofVec2f newFrc);

	ofVec2f pos;
	ofVec2f vel;
	ofVec2f frc;
	ofVec2f repelFrc;
	float drag;

	ofVec2f uniqueVal;
	float size;

	

};

