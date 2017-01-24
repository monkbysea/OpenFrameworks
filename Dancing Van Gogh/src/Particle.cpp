//
//  Particle.cpp
//  final
//
//  Created by TAO WEI on 11/28/16.
//
//

#include "Particle.hpp"

void Particle::setup() {
    vel.x = 3*ofRandomf();
    vel.y = 3*ofRandomf();
    angle = ofRandomf()*TWO_PI;
    age = 0;
}

void Particle::draw() {
    ofSetColor(color,ofMap(age,0,20,255,0,true));
    ofSetLineWidth(10);
    ofLine(oldpos,pos);
}

void Particle::update() {
    angle += ofNoise(pos.x, pos.y)*TWO_PI;
    vel.rotate(angle);
    oldpos = pos;
    pos += vel;
    age++;
}