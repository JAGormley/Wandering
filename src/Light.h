//
//  Light.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#pragma once

#ifndef __Wandering2__Light__
#define __Wandering2__Light__

#include <stdio.h>
#include "ofMain.h"

#endif /* defined(__Wandering2__Light__) */

class Light : public ofLight{
public:
    Light();
    enum Type {MOON, SUN, DIFFUSE};
    Type currentType;
    void setType(Type newType);
    static ofVec3f getLightPos();
    
    static ofLight light;
    
    ofColor lightColor;
    
    
};


