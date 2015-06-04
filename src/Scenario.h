//
//  Scenario.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-03.
//
//

#ifndef __Wandering2__Scenario__
#define __Wandering2__Scenario__

#include <stdio.h>
#include "Environment.h"
#include "Player.h"

#endif /* defined(__Wandering2__Scenario__) */


class Scenario {
public:
    Scenario();
    void setNew();
    
    Environment environment;
    Player player;
};

