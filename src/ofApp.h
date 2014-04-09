#pragma once

#include "ofMain.h"
#include "ofxGrabCam.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofxGrabCam camera;

    
    vector<ofPolyline>          lines;
    vector<ofPlanePrimitive>    imgPlanes;
    vector<ofImage>             imgTextures;
    bool imgon;
    
    float rotationX;
    float rotationY;
    float depth;

};
