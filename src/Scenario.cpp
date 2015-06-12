//
//  Scenario.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-06-03.
//
//

#include "Scenario.h"


// GLOBAL

Scenario::Scenario(){

}

// TODO: REMOVE, DEBUG FUNCTION
void Scenario::moveLight(int x, int y){
    environment->light->setPosition(ofVec3f(environment->light->getPosition().x, x, y));
}

void Scenario::setNew(){
    
    // ensure the seed is populated before anything else is set
    seed.populate();
    
    // set the environment to new seed values
    environment = new Environment(*new Light(), *getSurface(), *getMedium());
    
    // set the player to new seed values
    setPlayer(seed);
    
    setSprites();
    
    
    //    history.addHistory(1);
}

void Scenario::draw(){
    environment->draw();
    
    for (int i = 0; i < sprites.size(); i++) {
        sprites[i]->draw();
    }
}

void Scenario::update(){
    updateSprites();
    environment->update();
    player.move();
}

// ENVIRONMENT

Medium * Scenario::getMedium(){
    switch (seed.getMedium()){
        case Seed::M_VOID:
            return new mVoid(seed);
            break;
        case Seed::AIR:
            return new Air(seed);
            break;
        case Seed::M_WATER:
            return new mWater(seed);
            break;
    }
}

Surface * Scenario::getSurface(){
    switch (seed.getSurfaceType()){
        case Seed::GROUND:
            return new Ground(seed);
            break;
        case Seed::S_VOID:
            return new Void(seed);
            break;
        case Seed::S_WATER:
            return new Water(seed);
            break;
        case Seed::NONE:
            break;
    }
}

// SPRITES

void Scenario::setSprites(){
    for (int i = 0; i < 200; i++) {
        sprites.push_back(shared_ptr<Sprite>(new Plant()));
    }
    
    for (int i = 0; i < 200; i++) {
        sprites.push_back(shared_ptr<Sprite>(new Animal()));
    }
}

void Scenario::updateSprites(){
    for (int i = 0; i < sprites.size(); i++) {
        sprites[i]->move();
    }
}

// PLAYER

void Scenario::setPlayer(Seed lSeed){
    player.setMovementType(lSeed);
    player.setLocation(lSeed);
}