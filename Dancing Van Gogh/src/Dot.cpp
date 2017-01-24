//
//  Dot.cpp
//  final
//
//  Created by TAO WEI on 12/6/16.
//
//

#include "Dot.hpp"
Dot::Dot() {
    
    vel.set(0,0);
    acc.set(0,0);
    
    damp = 0.99; // de resistance!!!
}


void Dot::setup(float _x, float _y) {
    pos.x=_x;
    pos.y=_y;
}

void Dot::draw(float _radius) {
    ofCircle(pos.x+_radius,pos.y+_radius,_radius);
}

void Dot::addForce(ofPoint _force){
    acc += _force;
}

ofPoint Dot::getPosition(){
    return pos;
}


void Dot::update() {
    
    vel += acc;
    vel *= damp;
    pos += vel;
    acc *= 0.0;
    
}
