//
//  Ground.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#pragma once

#ifndef __Wandering2__Ground__
#define __Wandering2__Ground__
#include <stdio.h>
#include "ofMain.h"
#include "Player.h"
#endif /* defined(__Wandering2__Ground__) */

#ifndef __Wandering2__Surface__
#define __Wandering2__Surface__
#include "Surface.h"
#endif /* defined(__Wandering2__Surface__) */


class Ground: public Surface {
public:
    Ground(Seed seed);
//    void draw();
    void setColor(ofColor hue);
    void update();
    void draw();
    vector<ofVec3f> getMeshVerts();
    
    
    ofMaterial material;
    
    ofPlanePrimitive plane;
    int groundCount;
    vector<pair<int, int> > distances;
};