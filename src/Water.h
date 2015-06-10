//
//  Water.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-05.
//
//

#pragma once

#include <stdio.h>
#include "ofMain.h"

#ifndef __Wandering2__Surface__
#define __Wandering2__Surface__
#include "Surface.h"
#endif /* defined(__Wandering2__Surface__) */


class Water: public Surface {
public:
    Water(Seed seed);
//    void draw();
    void setColor(ofColor hue);
    void update();
    vector<ofVec3f> getMeshVerts();
    
    ofMaterial material;
    
    ofPlanePrimitive plane;
    ofVboMesh groundMesh;
    
};