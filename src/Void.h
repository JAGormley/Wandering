//
//  Void.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-01.
//
//

#pragma once

#ifndef __Wandering2__Void__
#define __Wandering2__Void__

#include <stdio.h>
#include "ofMain.h"

#ifndef __Wandering2__Domain__
#define __Wandering2__Domain__
#include "Domain.h"
#endif /* defined(__Wandering2__Domain__) */


#endif /* defined(__Wandering2__Void__) */

class Void: public Domain {
public:
    Void(Seed seed);
    void draw();
    void setColor(ofColor hue);
    void update();
    vector<ofVec3f> getMeshVerts();
    
    float colorHue;
//    ofMaterial material;
    ofColor materialColor;
    ofSpherePrimitive outer;
    ofSpherePrimitive inner;
    ofMaterial voidMaterial;
    ofVboMesh voidMesh;

};