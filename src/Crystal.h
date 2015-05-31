//
//  Crystal.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.
//
//

#ifndef __Wandering2__Crystal__
#define __Wandering2__Crystal__

#include <stdio.h>
#include <iostream>
#include "Sprite.h"


#endif /* defined(__Wandering2__Crystal__) */


class Crystal: public Sprite {
public:
    Crystal(Seed seed);
    virtual void move();
    void activate();
    void setActivated(bool activated);
    void draw();
    ofVec3f getLocation();
    
    ofMaterial material;
};