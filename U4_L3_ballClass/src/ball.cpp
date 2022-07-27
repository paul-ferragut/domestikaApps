#include "ball.h"

ball::ball() {

}

void ball::setup(ofVec2f initialPos, ofVec2f initialVel, float rad) {

	pos = initialPos;
	vel = initialVel;
	radius = rad;

}

void ball::update()
{
	pos += vel;

	if ((pos.x > ofGetWidth()) || (pos.x < 0)) {

		vel.x *= -1;

	}

	if ((pos.y > ofGetHeight()) || (pos.y < 0)) {

		vel.y *= -1;

	}
}

void ball::draw()
{
	ofDrawCircle(pos.x, pos.y, radius);
}
