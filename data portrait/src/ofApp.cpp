#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::exit()
{
    getImages.stopThread();
}
//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetWindowShape(1280, 720);
    
//-----insta images
    instagram.setup("50945680.5c50e54.a02247d8b6b4428c9fe308c2b32e4a04","self");
    instagram.setCertFileLocation(ofToDataPath("ca-bundle.crt",false));
    images.clear();
    images.resize(12);
    instagram.getUserRecentMedia("self",12);
    if (!instagram.getImageURL().empty())
    {
        for ( int i = 0; i < instagram.getImageURL().size(); i++)
        {
            getImages.loadFromURL(images[i], instagram.getImageURL()[i]);
            
        }
        
    }

//    //set up gui
//        gui.setup( "", "settings.xml" );
//        mixerGroup.setup( "Mixer" );
//        mixerGroup.setHeaderBackgroundColor( ofColor::darkRed );
//        mixerGroup.setBorderColor( ofColor::darkRed );
//        shader.load( "kaleido" );
//        mixerGroup.add( kenabled.setup( "kenabled", true ) );
//        mixerGroup.add( ksectors.setup( "ksectors", 10, 1, 100 ) );
//        mixerGroup.add( kangle.setup( "kangle", -10, -180, 180 ) );
//        mixerGroup.add( kx.setup( "kx", 0.15, 0, 1 ) );
//        mixerGroup.add( ky.setup( "ky", 0.5, 0, 1 ) );
//    
//        gui.minimizeAll();
//        gui.add( &mixerGroup );
//        showGui = true;


    
    
    
   shader.load( "kaleido" );
    ksectors=10;
    kangle=-175;
    kx=0.5;
    ky=0.2;
    

    
    fbo.allocate( ofGetWidth(), ofGetHeight(), GL_RGB );
    
    
    

    
}
//--------------------------------------------------------------
void ofApp::update()
{
    
}

//---------------------------------------------------------------
void ofApp::draw2(){
    fbo.begin();
    ofSetColor(0);
    ofRectangle(0,0,ofGetWidth(),ofGetHeight());
    instagram.drawJSON(10);
    
    float time = ofGetElapsedTimef();
    
    
    if (!images.empty()) {
        for (int i = 0; i < images.size(); i++) {
            
            //            ofSetColor(255, 255, 255);
            ofSetColor( 255, 10 );
            
            if (images[i].isAllocated()) {
                if(i <= 3) {
                    ofPushMatrix();
                    ofTranslate(5*(i+1)+125+250*i, 5+125);
                    ofRotate(time*10);
                    images[i].draw(-125, -125,250,250);
                    ofPopMatrix();
                }
                else if(i >= 4 && i <= 7) {
                    ofPushMatrix();
                    ofTranslate(5*(i-4+1)+125+250*(i-4), 5+125+250+5);
                    ofRotate(time*10);
                    images[i].draw(-125, -125, 250,250);
                    ofPopMatrix();
                    
                }
                else if(i >= 8 && i <= 11) {
                    ofPushMatrix();
                    ofTranslate(5*(i-8+1)+125+250*(i-8), 5+125+250+250+5+5);
                    ofRotate(time*10);
                    images[i].draw(-125, -125, 250,250);
                    ofPopMatrix();
                    
                }
               
            }
        }
    }
    
   
    
    fbo.end();
    
    ofSetColor( 255 );
    
    
//        if(kenabled){
        shader.begin();
        shader.setUniform1i( "ksectors", ksectors );
        shader.setUniform1f( "kangleRad", ofDegToRad(kangle) );
        shader.setUniform2f( "kcenter", kx*ofGetWidth(),
                            ky*ofGetHeight() );
        shader.setUniform2f( "screenCenter", 0.5*ofGetWidth(),
                            0.5*ofGetHeight() );
//        }
    
    fbo.draw( 0, 0, ofGetWidth(), ofGetHeight() );
    
//        if ( kenabled ) shader.end();
//    
//        if ( showGui ) gui.draw();
   

}

//--------------------------------------------------------------
void ofApp::draw()
{
//    ofColor centerColor = ofColor(85, 78, 68);
//    ofColor edgeColor(0, 0, 0);
//    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
 
    draw2();
    
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    

    switch (key) {
        case 'l':
            images.clear();
            images.resize(12);
            instagram.getUserRecentMedia("self",12);
            if (!instagram.getImageURL().empty())
            {
                for ( int i = 0; i < instagram.getImageURL().size(); i++)
                {
                    getImages.loadFromURL(images[i], instagram.getImageURL()[i]);
                    
                }
                
            }
            break;
        case 'f':
            images.clear();
            images.resize(12);
            instagram.getUserFeed(12);
            if (!instagram.getImageURL().empty())
            {
                for ( int i = 0; i < instagram.getImageURL().size(); i++)
                {
                    getImages.loadFromURL(images[i], instagram.getImageURL()[i]);
                }
            }
            break;
        case 'c':
            images.clear();
            break;
        default:
            break;
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY)
{
    instagram.mouseScroll(scrollY);
}
