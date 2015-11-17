#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>
#include "ofMain.h"

class Rectangle{
public:
    Rectangle();
    void xenoToPoint(float catchX, float catchY);
    void draw();
    
    ofPoint pos, targetPos;
    float catchUpSpeed;
};

#endif /* Rectangle_hpp */

