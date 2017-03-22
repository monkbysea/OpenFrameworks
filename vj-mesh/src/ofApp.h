#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#define N 256
//#define n 200
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
    ofSoundPlayer sound;
    
    ofMesh mesh;
    ofFbo fbo;
    int gridWidth,gridHeight;
    int gridStep;
    int size;
    
    float theta;
    float phi;
    
    int radius;
    
    int i1,i2,i3,i4;
    
    
    float spectrum[N];
//    float tx[n], ty[n],tz[n];
    float move;
    float vel;
    int specMove = 2;
    int specVel = 100;
    
    
    float time0 = 0;
    
   

    
    

    
};
