//
//  Void.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-10.
//
//

#ifndef __Wandering2__Void__
#define __Wandering2__Void__

#include <stdio.h>
#include "Surface.h"

#endif /* defined(__Wandering2__Void__) */

class Void: public Surface {
public:
    Void(Seed seed);
    //    void draw();
    void setColor(ofColor hue);
    void update();
    void draw();
    vector<ofVec3f> getMeshVerts();
    ofMaterial material;
    
    ofPlanePrimitive plane;
    ofVboMesh voidMesh;
    
};