//
//  mVoid.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-01.
//
//

#pragma once

#ifndef __Wandering2__mVoid__
#define __Wandering2__mVoid__

#include <stdio.h>
#include "ofMain.h"

#ifndef __Wandering2__Medium__
#define __Wandering2__Medium__
#include "Medium.h"
#endif /* defined(__Wandering2__Medium__) */


#endif /* defined(__Wandering2__mVoid__) */

class mVoid: public Medium {
public:
    mVoid(Seed seed);
    void draw();
    void setColor(ofColor hue);
    void update();
    vector<ofVec3f> getMeshVerts();
//    ~mVoid();
    float colorHue;
    ofColor materialColor;
    ofMaterial voidMaterial;
    ofVboMesh voidMesh;

};