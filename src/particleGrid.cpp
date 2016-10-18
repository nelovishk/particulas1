//
//  particleGrid.cpp
//  sineParticles
//
//  Created by Noel Rivas Cárdenas on 10/16/16.
//
//

#include "particleGrid.h"
#include "particle.h"
#include <vector>

particleGrid::particleGrid(int nr, int nc, int ww, int wh) {
    numRows = nr;
    numColumns = nc;
    windowWidth = ww;
    windowHeight = wh;
    
    for(int i = 0; i < numRows; i++) {
        vector<particle> row;
        rows.push_back(row);
        
        for(int j = 0; j < numColumns; j++) {
            particle p = particle();
            p.tileHeight = windowHeight / numRows;
            p.tileWidth = windowWidth / numColumns;
            p.windowHeight = windowHeight;
            p.windowWidth = windowWidth;
            p.setPosition(i, j);
            
            if(i > 0) {
                p.setParent(&rows[i-1][j]);
            }
            
            rows[i].push_back(p);
        }
    }
}

void particleGrid::update() {
    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numColumns; j++) {
            rows[i][j].updatePosition();
        }
    }
    
}

void particleGrid::draw() {
    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numColumns; j++) {
            rows[i][j].draw();
        }
    }
}