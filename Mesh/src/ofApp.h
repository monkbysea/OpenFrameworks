#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofEasyCam cam;
    
    ofMesh mesh;
    ofFbo fbo;
    int gridWidth,gridHeight;
    int gridStep;
    int size;
    
    float theta;
    float phi;
    
    int radius;
    
    int i1,i2,i3,i4;
    
    ofxPanel gui;
    ofxGuiGroup mixerGroup;
    
    bool showGui;
    
    ofShader shader;
    ofxToggle kenabled;
    ofxIntSlider ksectors;
    ofxFloatSlider kangle, kx, ky;

    
};
