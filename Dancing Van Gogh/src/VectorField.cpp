//
//  VectorField.cpp
//  final
//
//  Created by TAO WEI on 12/9/16.
//
//

#include "VectorField.hpp"

void VectorField::setup(int _w, int _h, int  _res){
    width = _w;
    height = _h;
    res = _res; // passing in 20, so the space between each dot is 20 pixels
    
    cols = width / res;
    rows = height / res;
    
    for(int x = 0; x < cols; x++){
        
        vector<ofPoint> column;
        column.resize(rows);
        table.push_back(column);
        
        for(int y = 0; y < rows; y++){
            ofPoint v=ofPoint(ofMap(x, 0, cols, 1, -1), ofMap(y, 0, rows, 1, -1));
            v.normalize();
            table[x][y]=v;
        }
    }
}

//
void VectorField::setNoise(float _time){
    for (int x = 0; x < table.size(); x++) {
        for (int y = 0; y < table[x].size(); y++) {
            float noise = ofMap( ofNoise(x*0.05, y*0.05, _time*0.05), 0, 1, 0, TWO_PI);
            table[x][y] = ofPoint( cos(noise), sin(noise) );
        }
    }
}

void VectorField::draw(){
    for (int x = 0; x < table.size(); x++) {
        for (int y = 0; y < table[x].size(); y++) {
            ofPushMatrix();
            ofTranslate(x*res, y*res);
            ofLine(ofPoint(0,0), table[x][y]);
            ofPopMatrix();
        }
    }
}

ofPoint VectorField::getForce(ofPoint _pos){
    _pos /= res;
    int x = ofClamp(int(_pos.x),0, cols-1);
    int y = ofClamp(int(_pos.y),0, rows-1);
    
    return table[x][y];
}

//This is decreasing the force of the vecotr field by 1%
void VectorField::update(){
    for (int x = 0; x < table.size(); x++) {
        for (int y = 0; y < table[x].size(); y++) {
            table[x][y] *= 0.25; //try setting to 0.1 and seeing the effects this has on the particles
        }
    }
}
