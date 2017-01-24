#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#include "Dot.hpp"
#include "VectorField.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    void createParticle();

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
    //    int addMode;
    
    ofFbo fbo1,fbo2,fbo3,fbo4,fbo5;
    //---------twinkling-------
    ofImage img;
    int res;
    float zOff;
    float zOffSpeed;
    //-------------------------
    
    //----circular motion----
    vector<Particle> particles;
    //-------------------------
    
    //----mesh----
    ofEasyCam cam;
    ofMesh mesh;
    int gridWidth;
    int gridHeight;
    int i1,i2,i3,i4;
    //-------------------------
    
   //-----orbiting mesh------
    ofMesh meshCopy;
    ofMesh Mesh2;
    bool orbiting;
    float startOrbitTime;
    
    vector<float> distances;
    vector<float> angles;
    ofVec3f meshCentroid;
    float maxSpeed,minSpeed;
    
    //-----swirling dots
     vector<Dot> dots;
    vector<ofColor> colors;
    
    //-----vectorfield
    VectorField vf;
		
};
