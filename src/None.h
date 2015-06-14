//
//  None.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-13.
//
//

#ifndef __Wandering2__None__
#define __Wandering2__None__

#include <stdio.h>
#include "Surface.h"

#endif /* defined(__Wandering2__None__) */


class None: public Surface {
public:
    None(Seed seed);
    void setColor(ofColor hue);
    void update();
    void draw();
    vector<ofVec3f> getMeshVerts();
    ofMaterial material;
    
    ofPlanePrimitive plane;
    ofVboMesh noneMesh;
    
};