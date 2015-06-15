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
#include "None.h"

#include "Plant.h"
#include "Animal.h"

#include "Sun.h"


class Scenario {
public:
    
    Scenario();
    
    
    
    // GLOBAL
    void setNew();
    void draw();
    void update();
    void moveLight(int x, int y);
    
    Seed seed;
    SpriteSeed spriteSeed;
    
    
    // ENVIRONMENT
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
    
    
    // LIGHT
//    void setLight(Seed seed);
    Light * getLight();
    Light * light;
    
    
    
    
    
    

    
};

