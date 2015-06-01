//
//  Environment.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#ifndef __Wandering2__Environment__
#define __Wandering2__Environment__

#include <stdio.h>
#include "Light.h"
#include "Domain.h"


#endif /* defined(__Wandering2__Environment__) */

class Environment {
public:
    Environment();
    Environment(Light light, Domain &up, Domain &down);
    void draw();
    
    Domain * up;
    Domain * down;
    Light light;
    
    
};