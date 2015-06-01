//
//  Animal.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-30.
//
//

#ifndef __Wandering2__Animal__
#define __Wandering2__Animal__
#include <stdio.h>
#include <iostream>
#include "ofMain.h"
#endif /* defined(__Wandering2__Animal__) */

#ifndef __Wandering2__Sprite__
#define __Wandering2__Sprite__
#include "Sprite.h"
#endif /* defined(__Wandering2__Sprite__) */

class Animal: public Sprite {
public:
    Animal(Seed seed);
    void move();
    void activate();
    void setActivated(bool activated);
    void draw();
    ofVec3f getLocation();
    
    ofMaterial material;
    ofBoxPrimitive box;
};