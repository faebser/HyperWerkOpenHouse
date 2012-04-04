/*
 * pillar.h
 *
 *  Created on: Jan 12, 2012
 *      Author: faebser
 */
#include "ofMain.h"

#ifndef PILLAR_H_
#define PILLAR_H_

class pillar {
public:
	pillar(float scale, float height, ofPoint *pos, ofPoint *viewPoint, ofColor* colors[3]);
	void draw();
	virtual ~pillar();

	void setPos(float y);
	void setViewPoint(float y);
	float getYPos();
	void reset();
	bool checkPos();

	float scale, height;
	ofPoint *pos, *viewPoint;
	ofColor* colors[4];

	void colorChooser(ofColor inputColor);
};

#endif /* PILLAR_H_ */
