#pragma once
#define AMOUNT 200

#include "ofMain.h"
#include "pillar.h"
#include <algorithm>

class testApp : public ofBaseApp{

	public:

		ofColor* colors[4];
		pillar* pillars[AMOUNT];

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		void colorChooser(ofColor inputColor);
};
