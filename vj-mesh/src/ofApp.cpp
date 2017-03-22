#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(1080, 720);
    sound.loadSound( "yo.mp3" );
    sound.setLoop( true );
    sound.play();
    
    for (int i=0; i<N; i++) {
        spectrum[i] = 0.0f;
    }

    gridWidth=360;
    gridHeight=360;
    gridStep = 3;
    size = gridWidth/gridStep;
    
    radius = 200;
    
    for(int i = 0; i <size; i++){
        for(int j = 0; j <size; j++){
            
            theta = ofMap(i, 0, size, 0, 2*PI);
            phi = ofMap(j, 0, size, 0, 2*PI);
            
          
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
    ofSoundUpdate();
    
    
    float *data = ofSoundGetSpectrum(N);
    
    for ( int i=0; i<N; i++ ) {
        spectrum[i] *= 0.8;
        spectrum[i] = max(spectrum[i], data[i]);
    }
    
    float time = ofGetElapsedTimef();
    float dt = time - time0;
    dt = ofClamp(dt, 0.0, 0.1);
    time0 = time;
    
    move = ofMap(spectrum[specMove], 1, 3, 400, 500, true);
    vel = ofMap(spectrum[specVel], 0, 0.1, 0.05, 0.5);
//    
//    for (int i=0; i<size; i++) {
//        tx[i] += vel * dt;
//        pos[i].x = ofSignedNoise(tx[i]) * move;
//        for(int j=0;j<size;j++){
//            ty[j] += vel * dt;
//            tz[j] += vel * dt;
//        
//        pos[j].y = ofSignedNoise(ty[j]) * move;
//        pos[j].z = ofSignedNoise(ty[j]) * move;
//    }
//    }

    //Now we want to loop through every vertex:
    //0, 1, 2, 3...
    
    for(int i = 0; i <size; i++){
        for(int j = 0; j <size; j++){
            int index = j + size *i;
            
            ofPoint p = mesh.getVertex(index);
            
//            tx[i] += vel * dt;
//            p.x = ofSignedNoise(tx[i]) * move;
//            
//            ty[j] += vel * dt;
//            tz[j] += vel * dt;
//            
//            p.y = ofSignedNoise(ty[j]) * move;
//            p.z = ofSignedNoise(tz[j]) * move;
//            
//            float perlin=ofNoise(p.x, p.y, p.z);

             float perlin = ofNoise(j*vel*move*0.004, i*vel*move*0.004,time*0.1);
        
            radius=300+300*perlin;
            
              mesh.setVertex(index, p.normalize()*radius);
              ofEnableAlphaBlending();
              mesh.setColor(index, ofColor(0,0,0));
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofEnableAlphaBlending();
    ofBackgroundGradient(ofColor(255),ofColor(140),OF_GRADIENT_CIRCULAR );
    
    cam.begin();
    
//    ofSetLineWidth(0.01);
    mesh.drawWireframe();
    

   
    cam.end();

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
