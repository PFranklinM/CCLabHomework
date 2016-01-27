//
//  Particle.cpp
//  ParticleSystem
//
//  Created by Paul Mallon on 11/17/15.
//
//

#include "Particle.hpp"
#include "ofMain.h"

Particle::Particle(){
    setInitialCondition(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 0, 0);
    size = 1.1;
    r = ofRandom(0,80);
    g = ofRandom(50,120);
    b = ofRandom(100,200);
    
    dampening = 0.09;
}

void Particle::addRepulsion(float px, float py, float radius, float strength){
    
    ofVec2f posOfForce;
    
    posOfForce.set(px,py);
    
    ofVec2f diff = pos - posOfForce; //difference between two position vectors
    
    if(diff.length() < radius){
        float percent = 1 - (diff.length() / radius);
        diff.normalize();
        force.x += diff.x * percent * strength;
        force.y += diff.y * percent * strength;
    }
    
}

void Particle::addAttraction(float px, float py, float radius, float strength){
    
    ofVec2f posOfForce;
    
    posOfForce.set(px,py);
    
    ofVec2f diff = pos - posOfForce; //difference between two position vectors
    
    if(diff.length() < radius){
        float percent = 1 - (diff.length() / radius);
        diff.normalize();
        force.x -= diff.x * percent * strength;
        force.y -= diff.y * percent * strength;
    }
    
}

void Particle::trail(float catchX, float catchY){
    
    float catchUpSpeed = 0.5;
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
    pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    
}

void Particle::setInitialCondition(float px, float py, float vx, float vy){
    
    pos.set(px,py);
    vel.set(vx,vy);
    
}

void Particle::update(){
    
    vel += force;
    pos += vel;
    
}

void Particle::draw(){
    
    ofSetColor(r, g, b);
    ofCircle(pos.x, pos.y, size);
    
}

void Particle::resetForce(){
    force.set(0,0);
}

void Particle::addDampening(){
    force.x = force.x - vel.x * dampening;
    force.y = force.y - vel.y * dampening;
}
