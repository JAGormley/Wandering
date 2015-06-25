//
//  Crystal.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-24.
//
//

#ifndef __Wandering2__Crystal__
#define __Wandering2__Crystal__

#include <stdio.h>
#include "Animal.h"

#endif /* defined(__Wandering2__Crystal__) */


class Crystal : public Animal {
public:
    
    Crystal(SpriteSeed sSeed);
    void setup();
    void update();
    void draw();
    void activate();
    // body
    ofSpherePrimitive body;
    ofCylinderPrimitive ring1;
    ofCylinderPrimitive ring2;
    int alphFill;
};