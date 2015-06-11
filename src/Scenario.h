//
//  Scenario.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-03.
//
//

#pragma once

#include <stdio.h>
#include "Environment.h"
#include "Player.h"
#include "History.h"

#include "Air.h"
#include "mVoid.h"
#include "mWater.h"

#include "Void.h"
#include "Ground.h"
#include "Water.h"
#include "Plant.h"


class Scenario {
public:
    
    Scenario();
    
    
    // GLOBAL
    void setNew();
    void draw();
    void update();
    
    
    // ENVIRONMENT
    // TODO: add LIGHT
    Medium * getMedium();
    Surface * getSurface();
    Environment * environment;
    
    // PLAYER
    void setPlayer(Seed lSeed);
    Player player;
    
    
    
    // SPRITES
    
    void updateSprites();
    void setSprites();
    vector< shared_ptr<Sprite> > sprites;
    
    
    
    // TODO: remove hard-coded light, get from Seed
    Light moon;
    Seed seed;
    
    
    
    
    
    

    
};

