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
    void setPlayer();
    void draw();
    Medium * getMedium();
    Surface * getSurface();
    
    Environment * environment;
    Player player;
//    History history;
    Light moon;
    Seed seed;
    
    
private:
    void setPlayerMovement();
    void setPlayerLocation();
};

