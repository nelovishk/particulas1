//
//  particle.cpp
//  sineParticles
//
//  Created by Noel Rivas Cárdenas on 10/16/16.
//
//

#include "particle.h"
#include "ofMain.h"
#include "math.h"

particle::particle() {
    tileWidth = 0;
    tileHeight = 0;
    
    myColor.r = ofRandom(0, 255);
    myColor.g = ofRandom(220, 255);
    myColor.b = ofRandom(230, 255);
    myColor.a = 255;
    radius = 1.5;
    y = 0;
    x = 0;
}

void particle::setPosition(int nr, int nc) {
    numRow = nr;
    numCol = nc;
}

void particle::setTileDimensions(float tw, float th) {
    tileWidth = tw;
    tileHeight = th;
}

void particle::updatePosition() {
    if(!hasParent) {
        float maxDisplacementX = 5;
        float maxDisplacementY = 50;
        float frameNum = ofGetFrameNum();
        float displaceX = (cos(frameNum / 10) * maxDisplacementX);
        float displaceY = (sin((frameNum - (numCol)) / 100) * maxDisplacementY);
        x = (tileWidth * numCol) + (tileWidth / 2);
        y = (tileHeight * numRow) + (tileHeight / 2) + displaceY;
    }
    else {
        //x = (tileWidth * numCol) + (tileWidth / 2);
        //y = (tileHeight * numRow) + (tileHeight / 2);
        particle p = *parent;
        printf("Parent has position in x %f", p.x);
        x = p.x + 5;
        y = p.y + 5;
    }
}

void particle::setParent(particle * p) {
    hasParent = true;
    parent = p;
}

void particle::draw() {
    ofSetColor(myColor);
    ofDrawCircle(x, y, radius);
}