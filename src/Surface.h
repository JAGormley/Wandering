//
//  Surface.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-05.
//
//

#pragma once

#ifndef __Wandering2__Surface__
#define __Wandering2__Surface__

#include <stdio.h>

#endif /* defined(__Wandering2__Surface__) */


#ifndef __Wandering2__Surface__
#define __Wandering2__Surface__
#include <stdio.h>
#include "ofMain.h"
//#include "Ground.h"
#endif /* defined(__Wandering2__Surface__) */

#ifndef __Wandering2__Seed__
#include "Seed.h"
#define __Wandering2__Seed__
#endif /* defined(__Wandering2__Seed__) */


class Surface {
public:
    Surface(Seed seed);
    static enum Shape {SPHERE, PLANE} shape;
    of3dPrimitive rawShape;
    virtual void setColor(ofColor hue) =0;
    virtual void draw() =0;
    virtual void update() =0;
    virtual vector<ofVec3f> getMeshVerts()=0;
    Shape getType();
    Shape type;
    
};