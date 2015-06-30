//
//  Bird.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-26.
//
//

#ifndef __Wandering2__Bird__
#define __Wandering2__Bird__

#include <stdio.h>
#include "Animal.h"

#endif /* defined(__Wandering2__Bird__) */


class Bird : public Animal{
public:
    Bird(SpriteSeed spriteSeed);
    void setup();
    void update();
    void draw();
    
    ofSpherePrimitive body;
    
};