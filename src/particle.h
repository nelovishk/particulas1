//
//  particle.h
//  sineParticles
//
//  Created by Noel Rivas Cárdenas on 10/16/16.
//
//

#ifndef __sineParticles__particle__
#define __sineParticles__particle__

#include <stdio.h>
#include "ofColor.h"

class particle {
public:
    particle();
    void setPosition(int numRow, int numCol);
    void setParent(particle * p);
    void updatePosition();
    void draw();
    void setTileDimensions(float tileWidth, float tileHeight);
    
    int numRow;
    int numCol;
    float tileWidth;
    float tileHeight;
    int windowHeight;
    int windowWidth;
    float x;
    float y;
    
    int radius;
    ofColor myColor;
    bool hasParent = false;
    particle * parent;
};

#endif /* defined(__sineParticles__particle__) */
