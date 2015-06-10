//
//  Scenario.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-03.
//
//

#include "Scenario.h"


Scenario::Scenario(){
    
}

void Scenario::setNew(){
    seed.populate();
    environment = new Environment(moon, *getSurface(), *getMedium());
    setPlayer(seed);
//    history.addHistory(1);
    
}

void Scenario::draw(){
    environment->draw();
}


// ENVIRONMENT

Medium * Scenario::getMedium(){
    switch (seed.getMedium()){
        case Seed::M_VOID:
            return new Void(seed);
            break;
        case Seed::AIR:
            break;
        case Seed::M_WATER:
            break;
    }
}

Surface * Scenario::getSurface(){
    switch (seed.getSurfaceType()){
        case Seed::GROUND:
            return new Ground(seed);
            break;
        case Seed::S_VOID:
            break;
        case Seed::S_WATER:
            return new Water(seed);
            break;
        case Seed::NONE:
            break;
    }
}

// PLAYER

void Scenario::setPlayer(Seed lSeed){
    player.setMovementType(lSeed);
    player.setLocation(lSeed);
//    
//    setPlayerMovement(lSeed);
//    setPlayerLocation(lSeed);
}

//void Scenario::setPlayerMovement(Seed lSeed){
//    
//    
//}
//
//void Scenario::setPlayerLocation(Seed lSeed){
//    
//}