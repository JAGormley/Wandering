//
//  Light.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#ifndef __Wandering2__Light__
#define __Wandering2__Light__

#include <stdio.h>

#endif /* defined(__Wandering2__Light__) */

class Light {
public:
    enum Type {MOON, SUN, DIFFUSE};
    Type currentType;
    void setType(Type newType);
};