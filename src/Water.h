//
//  Water.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-05.
//
//

#pragma once

#include <stdio.h>
#include "Surface.h"



class Water: public Surface {
public:
    Water(Seed seed);
//    void draw();
    void setColor(ofColor hue);
    void update();
    void draw();
    vector<ofVec3f> getMeshVerts();
    
    ofMaterial material;
    
    ofPlanePrimitive plane;
    ofVboMesh groundMesh;
    
};