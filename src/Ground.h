//
//  Ground.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#ifndef __Wandering2__Ground__
#define __Wandering2__Ground__

#include <stdio.h>
#include "ofMain.h"
#include "Domain.h"
#include "Seed.h"

#endif /* defined(__Wandering2__Ground__) */

class Ground: public Domain {
public:
    Ground(Seed seed);
    void move();
    void activate();
    void setActivated(bool activated);
    void draw();
    ofVec3f getLocation();
    
    ofMaterial material;
    ofBoxPrimitive box;
};