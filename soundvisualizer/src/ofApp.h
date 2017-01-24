#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void mousePressed(int x, int y, int button);
        ofSoundPlayer sound;	//Sound sample

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    vector<float> spectrum;
    vector<ofPoint> p;
    vector<float> tx;
    vector<float> ty;
    
    int N = 256;		//Number of bands in spectrum
    float Rad = 500;		//Cloud raduis parameter
    float Vel = 0.1;		//Cloud points velocity parameter
    int bandRad = 2;		//Band index in spectrum, affecting Rad value
    int bandVel = 100;		//Band index in spectrum, affecting Vel value
    
    int n = 300;		//Number of cloud points
    
       
    float time0 = 0;		//Time value, used for dt computing
};
