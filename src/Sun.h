//
//  Sun.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-14.
//
//

#ifndef __Wandering2__Sun__
#define __Wandering2__Sun__

#include <stdio.h>
#include "Light.h"

#endif /* defined(__Wandering2__Sun__) */



class Sun : public Light {
public:
    Sun(Seed seed);
    
    void draw();
};