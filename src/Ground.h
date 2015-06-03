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
#endif /* defined(__Wandering2__Ground__) */

#ifndef __Wandering2__Domain__
#define __Wandering2__Domain__
#include "Domain.h"
#endif /* defined(__Wandering2__Domain__) */


class Ground: public Domain {
public:
    Ground(Seed seed);
    void draw();
    void setColor(ofColor hue);
    void update();
    vector<ofVec3f> getMeshVerts();
    
    ofMaterial material;
    
    ofPlanePrimitive plane;
    ofVboMesh groundMesh;

};