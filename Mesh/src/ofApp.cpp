#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
//    gui.setup( "", "settings.xml" );
//    mixerGroup.setup( "Mixer" );
//    mixerGroup.setHeaderBackgroundColor( ofColor::darkRed );
//    mixerGroup.setBorderColor( ofColor::darkRed );
//    shader.load( "kaleido" );
//    mixerGroup.add( kenabled.setup( "kenabled", true ) );
//    mixerGroup.add( ksectors.setup( "ksectors", 10, 1, 100 ) );
//    mixerGroup.add( kangle.setup( "kangle", -10, -180, 180 ) );
//    mixerGroup.add( kx.setup( "kx", 0.15, 0, 1 ) );
//    mixerGroup.add( ky.setup( "ky", 0.5, 0, 1 ) );
//    
//    gui.minimizeAll();
//    gui.add( &mixerGroup );
//    showGui = true;
    
    gridWidth=360;
    gridHeight=360;
    gridStep = 4;
    size = gridWidth/gridStep;
    
    radius = 300;
    
    for(int i = 0; i <size; i++){
        for(int j = 0; j <size; j++){
            
            theta = ofMap(i, 0, size, 0, 2*PI);
            phi = ofMap(j, 0, size, 0, 2*PI);
            
//            float a = radius*abs(cos(theta))*sin(phi);
//            float b = radius*abs(cos(theta))*cos(phi);
//            float c = radius*sin(theta);
//            mesh.addVertex(ofPoint(a,b,c));
            ofPoint point=ofPoint(radius*cos(theta)*sin(phi), radius*cos(theta)*cos(phi),radius*sin(theta));
            mesh.addVertex(point);
        
            mesh.addColor(ofColor(240,100,100));
        }
    }
    
    //create the triangle indices
    for(int i = 0; i <size; i++){
        for(int j = 0; j <size; j++){
            
            i1 = j + size * i;
            i2 = j+1 + size * i;
            i3 = j + size * (i+1);
            i4 = j+1 + size * (i+1);
            
            mesh.addTriangle(i1, i2, i3);
            mesh.addTriangle(i2, i3, i4);
        }
    }
    
    fbo.allocate( ofGetWidth(), ofGetHeight(), GL_RGB );
   

}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    
    //Now we want to loop through every vertex:
    //0, 1, 2, 3...
    
    for(int i = 0; i <size; i++){
        for(int j = 0; j <size; j++){
            int index = j + size *i;
            
            ofPoint p = mesh.getVertex(index);
            
            float perlin = ofNoise(j*0.1, i*0.1, time *0.5);
//            radius = 150+ (perlin * 150);
            
            radius=150+150*perlin;
            
//            p=ofPoint(radius*cos(theta)*sin(phi), radius*cos(theta)*cos(phi),radius*sin(theta));
            
            
            mesh.setVertex(index, p.normalize()*radius);
            mesh.setColor(index, ofColor(perlin*10, perlin*162, perlin*255));
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    fbo.begin();
    ofBackground(255, 182, 193);
    cam.begin();
    
    
    mesh.drawWireframe();
    
//    if ( kenabled ) {
//        shader.begin();
//        shader.setUniform1i( "ksectors", ksectors );
//        shader.setUniform1f( "kangleRad", ofDegToRad(kangle) );
//        shader.setUniform2f( "kcenter", kx*ofGetWidth(),
//                            ky*ofGetHeight() );
//        shader.setUniform2f( "screenCenter", 0.5*ofGetWidth(),
//                            0.5*ofGetHeight() );
//    }
//    fbo.draw( 0, 0, ofGetWidth(), ofGetHeight() );
//    if ( kenabled ) shader.end();
   
    cam.end();
//    fbo.end();
    
//    if ( kenabled ) {
//        shader.begin();
//        shader.setUniform1i( "ksectors", ksectors );
//        shader.setUniform1f( "kangleRad", ofDegToRad(kangle) );
//        shader.setUniform2f( "kcenter", kx*ofGetWidth(),
//                            ky*ofGetHeight() );
//        shader.setUniform2f( "screenCenter", 0.5*ofGetWidth(),
//                            0.5*ofGetHeight() );
//    }
//    fbo.draw( 0, 0, ofGetWidth(), ofGetHeight() );
//    if ( kenabled ) shader.end();
    
//    if ( showGui ) gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
