//
//  Environment.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//


#pragma once
#ifndef __Wandering2__Environment__
#define __Wandering2__Environment__

#include <stdio.h>
#include "Light.h"
#include "Domain.h"

#endif /* defined(__Wandering2__Environment__) */

//#include "ofApp.h"

class Environment {
public:
    Environment();
    Environment(Light light, Domain &down, Domain &up);
    
    enum Type {ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN};
    Type type;
    
    void draw();
    int getType();
    
    Domain * up;
    Domain * down;
    Light light;
};