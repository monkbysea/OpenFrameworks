#pragma once

#include "ofMain.h"
#include "ofxInstagram.h"
#include "ofxThreadedImageLoader.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void draw2();
        
    
        void exit();
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
        void mouseScrolled(int x, int y, float scrollX,float scrollY);
		
        ofxInstagram instagram;
        ofxThreadedImageLoader  getImages;
        deque<ofImage> images;
        
    
   
    
//------Gui------------
//    ofxPanel gui;
//    ofxGuiGroup mixerGroup;
//    bool showGui;
//    
//    bool processing;
//    bool showShader;
    

    
    //Chapter 4
    
//    ofTexture image;
//    ofVideoPlayer video;
//    ofVideoGrabber camera;
//    ofxGuiGroup mixerGroup;
//    float imageAlpha;
    ofFbo fbo;
    void draw2d();
    
    ofShader shader;
    ofxToggle kenabled;
    ofxIntSlider ksectors;
    ofxFloatSlider kangle, kx, ky;

};
