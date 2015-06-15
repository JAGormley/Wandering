//
//  Moon.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-14.
//
//

#ifndef __Wandering2__Moon__
#define __Wandering2__Moon__

#include <stdio.h>
#include "Light.h"

#endif /* defined(__Wandering2__Moon__) */


class Moon : public Light {
public:
    Moon(Seed seed);
    void drawChild();
};