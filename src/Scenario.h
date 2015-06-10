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
#include "History.h"
#include "Void.h"
#include "Ground.h"
#include "Water.h"

#endif /* defined(__Wandering2__Scenario__) */

class Scenario {
public:
    
    Scenario();
    
    void setNew();
    
    void draw();
    
    // ENVIRONMENT
    Medium * getMedium();
    Surface * getSurface();
    Environment * environment;
    
    // PLAYER
    void setPlayer(Seed lSeed);
    void setPlayerMovement(Seed lSeed);
    void setPlayerLocation(Seed lSeed);
    Player player;
    
    Light moon;
    Seed seed;
    
    

    
};

