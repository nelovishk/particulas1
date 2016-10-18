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
    
    myColor.r = ofRandom(150, 255);
    myColor.g = ofRandom(230, 255);
    myColor.b = ofRandom(150, 255);
    myColor.a = 255;
    radius = 1.5;
    //y = rand() % 800;
    y = 0;
    x = rand() % 1280;
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
    int frameNum = ofGetFrameNum();
    float floatFrameNum = frameNum;
    if(!hasParent) {
        float maxDisplacementX = 5;
        float maxDisplacementY = windowHeight / 2;

        //float displaceX = (cos(floatFrameNum / 10) * maxDisplacementX);
        float displaceY = (sin((floatFrameNum - (numCol * 10)) / 30) * maxDisplacementY);
        x = (tileWidth * numCol) + (tileWidth / 2);
        y = (windowHeight / 2) + displaceY;
    }
    else if (frameNum % 3600 == 0) {
        //y = rand() % 800;
        y = 0;
        x = rand() % 1280;
    }
    else {
        particle p = *parent;
        float speed = .09;
        x += (p.x - x) * speed;
        y += (p.y - y) * speed;
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