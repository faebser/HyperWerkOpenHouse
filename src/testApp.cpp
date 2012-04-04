#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	this->colorChooser(ofColor(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255)));
	float scale = 40;
	int i = 0;
	float amount = AMOUNT / scale*2+5;
	float lines = AMOUNT / ofGetWidth();
	pillar* tempPillar;

	for(int y = -10; y < amount; y++) {
		cout << "bala" << endl;
		for(int x = 0; x*(scale*2+5) < ofGetWidth(); x++) {
			cout << "--bala" << endl;
			if(y % 2 == 0) {
				tempPillar = new pillar(scale, ofRandom(scale,200-(amount*0.5-x*10)), new ofPoint(x*(scale*2+5), y*(scale*2)), new ofPoint(600,-100), colors);
			}
			else {
				tempPillar = new pillar(scale, ofRandom(scale,200-(amount*0.5-x*10)), new ofPoint(x*(scale*2+5)-scale, y*(scale*2)), new ofPoint(600,-100), colors);
			}
			if(i < AMOUNT) {
				cout << "pillar gemacht @ " << i << endl;
				pillars[i] = tempPillar;
				i++;
			}
			else {
				break;
			}
		}
	}
}

//--------------------------------------------------------------
void testApp::update(){
	float speed = 1;
	//sort(pillars, pillars+AMOUNT);
	for(unsigned int i = 0; i < AMOUNT; i++) {
		//cout << "i => " << i << endl;
			pillars[i]->setPos(speed);
			if(pillars[i]->getYPos() > ofGetHeight()+200) {
				pillars[i]->reset();
			}
		}
}

//--------------------------------------------------------------
void testApp::draw(){
	for(unsigned int i = 0; i < AMOUNT; i++) {
		pillars[i]->draw();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	cout << key << endl;
	this->colorChooser(ofColor(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255)));
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::colorChooser(ofColor inputColor) {
	float range = ofRandom(0,100);
	range = range / 3;

	for(int i = 0; i < 4; i++) {
		colors[i] = new ofColor(inputColor.r, inputColor.g, inputColor.b);
		colors[i]->setBrightness(inputColor.getBrightness()+((2-i)*-1)*range);
	}
}
