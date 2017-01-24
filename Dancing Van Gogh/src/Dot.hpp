//
//  Dot.hpp
//  final
//
//  Created by TAO WEI on 12/6/16.
//
//

#pragma once
#include "ofMain.h"

class Dot {
public:
    Dot();
    void setup(float _x, float _y);
    void draw(float _radius);
    void update();
    void addForce(ofPoint _force);
    ofPoint getPosition();
    
    ofPoint pos,vel,acc;
    float angle;
    float radius;
    ofColor color;
    float damp;
};