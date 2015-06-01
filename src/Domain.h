//
//  Domain.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#ifndef __Wandering2__Domain__
#define __Wandering2__Domain__

#include <stdio.h>
#include "ofMain.h"

#endif /* defined(__Wandering2__Domain__) */

class Domain {

    Domain(){};
    virtual void setColor(ofColor hue) =0;
    virtual void draw() =0;
    virtual void update() =0;

};