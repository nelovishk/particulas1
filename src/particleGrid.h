//
//  particleGrid.h
//  sineParticles
//
//  Created by Noel Rivas Cárdenas on 10/16/16.
//
//

#ifndef __sineParticles__particleGrid__
#define __sineParticles__particleGrid__

#include <stdio.h>
#include "particle.h"
#include <vector>

class particleGrid {
public:
    particleGrid(int numRows, int numColumns, int windowWidth, int windowHeight);
    void update();
    void draw();
    
    std::vector<std::vector<particle> > rows;
    int numRows;
    int numColumns;
    int windowWidth;
    int windowHeight;
};

#endif /* defined(__sineParticles__particleGrid__) */