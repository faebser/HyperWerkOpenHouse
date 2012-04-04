/*
 * pillar.cpp
 *
 *  Created on: Jan 12, 2012
 *      Author: faebser
 */

#include "pillar.h"

pillar::pillar(float scale, float height, ofPoint *pos, ofPoint *viewPoint, ofColor* colors[3]) {
	this->scale = scale;
	this->height = height;
	this->pos = pos;
	this->viewPoint = viewPoint;
	for(int i = 0; i < 4; i++)
		this->colors[i] = colors[i];
}

void pillar::setPos(float y) {
	pos->y += y;
}

void pillar::setViewPoint(float y) {
	viewPoint->y += y;
}

float pillar::getYPos() {
	return pos->y;
}
void pillar::reset() {
	this->pos->y = -10;
	this->colorChooser(ofColor(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255)));
}

void pillar::draw() {
	ofPoint tempPoint = ofPoint(0, 0);
	ofPoint endPoint = ofPoint(scale, 0);
	ofPoint middlePoint = ofPoint(scale/2, 0);
	ofPoint middlePoint2 = ofPoint(scale/2, 0);
	ofVec2f testVec = ofVec2f(viewPoint->x - (pos->x + scale/2), viewPoint->y - pos->y);
	testVec.normalize();
	middlePoint += testVec.getScaled(scale);
	middlePoint2 -= testVec.getScaled(scale);
	ofPushMatrix();
		ofTranslate(pos->x, pos->y-height);
		ofSetColor(colors[2]->r, colors[2]->g, colors[2]->b);
		ofTriangle(tempPoint.x, tempPoint.y, middlePoint.x, middlePoint.y, endPoint.x, endPoint.y);
		ofSetColor(colors[1]->r, colors[1]->g, colors[1]->b);
		ofRect(tempPoint.x, tempPoint.y, scale, height);
		ofPushMatrix();
			ofTranslate(middlePoint.x, middlePoint.y);
			ofSetColor(colors[2]->r, colors[2]->g, colors[2]->b);
			ofTriangle(tempPoint.x, tempPoint.y, middlePoint.x, middlePoint.y, endPoint.x, endPoint.y);
			ofTriangle(tempPoint.x, tempPoint.y, middlePoint2.x, middlePoint2.y, endPoint.x, endPoint.y);
			ofSetColor(colors[0]->r, colors[0]->g, colors[0]->b);
			ofBeginShape();
				ofVertex(middlePoint2);
				ofVertex(endPoint);
				ofVertex(endPoint.x, endPoint.y + height);
				ofVertex(middlePoint2.x, middlePoint2.y + height);
			ofEndShape();
			ofTranslate(-scale, 0);
			ofSetColor(colors[2]->r, colors[2]->g, colors[2]->b);
			ofTriangle(tempPoint.x, tempPoint.y, middlePoint.x, middlePoint.y, endPoint.x, endPoint.y);
			ofTriangle(tempPoint.x, tempPoint.y, middlePoint2.x, middlePoint2.y, endPoint.x, endPoint.y);
			ofSetColor(colors[0]->r, colors[0]->g, colors[0]->b);
			ofBeginShape();
				ofVertex(middlePoint2);
				ofVertex(tempPoint);
				ofVertex(tempPoint.x, tempPoint.y + height);
				ofVertex(middlePoint2.x, middlePoint2.y + height);
			ofEndShape();
			ofTranslate(middlePoint.x, middlePoint.y);
			ofSetColor(colors[2]->r, colors[2]->g, colors[2]->b);
			ofTriangle( tempPoint.x, tempPoint.y,middlePoint2.x, middlePoint2.y ,endPoint.x, endPoint.y);
		ofPopMatrix();
	ofPopMatrix();
}

void pillar::colorChooser(ofColor inputColor) {
	float range = ofRandom(0,100);
	range = range / 3;

	for(int i = 0; i < 4; i++) {
		colors[i] = new ofColor(inputColor.r, inputColor.g, inputColor.b);
		colors[i]->setBrightness(inputColor.getBrightness()+((2-i)*-1)*range);
	}
}

pillar::~pillar() {
	// TODO Auto-generated destructor stub
}

