//
//  Soil.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.



#pragma once

#ifndef __Wandering2__Soil__
#define __Wandering2__Soil__

#include <stdio.h>
#include "Seed.h"

#endif /* defined(__Wandering2__Soil__) */

// this class will contain all the variables that effect the growth of the seed (domains, light, etc) and return the object
class Soil {
public:
    Soil();
    bool isOrbital();
    
    History::Present present;
    History history;
};

