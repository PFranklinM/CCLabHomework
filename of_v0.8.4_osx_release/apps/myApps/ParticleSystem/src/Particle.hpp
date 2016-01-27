//
//  Particle.hpp
//  ParticleSystem
//
//  Created by Paul Mallon on 11/17/15.
//
//

//#ifndef Particle_hpp
//#define Particle_hpp
//
//#include <stdio.h>
//
//#endif /* Particle_hpp */

#include "ofMain.h"

class Particle{
public:
    
    Particle(); //constructor
    virtual ~Particle(){};
    
    ofVec2f pos; //vector position
    ofVec2f vel; //vector velocity
    ofVec2f force; //vector force
    
    void setInitialCondition(float px, float py, float vx, float vy);
    
    void update();
    void draw();
    
    void addRepulsion(float px, float py, float radius, float strength); //when the particles get close to the mouse, they get pushed away
    void addAttraction(float px, float py, float radius, float strength);
    void trail(float catchX, float catchY);
    
    float size;
    
    int r, g, b;
    
    float dist;
    
    ofColor color;
    
    void resetForce();
    
    void addDampening();
    float dampening;
};
