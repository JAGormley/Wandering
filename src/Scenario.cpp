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

void Scenario::setNew(){
    reset();
    
    
    // ensure the seed is populated before anything else is set
    seed.populate(history);
    
    // set the environment to new seed values
    environment = new Environment(*getSurface(), *getMedium());
    
    // TODO: move mesh into setSurface method for Sprites
    spriteSeed = SpriteSeed(seed, environment->getSurfaceMesh());
    
    // set light to new seed values
    light = getLight();
    
    // set surface first, then set the player to new seed values
    player.setSurface(environment->getSurfaceMesh());
    setPlayer(seed);
    
    sprites.clear();
    setSprites();
//    sound.loadMusic();
//    sound.playMusic();

}

void Scenario::draw(){
    light->enable();
    
    environment->draw();
    
    for (int i = 0; i < sprites.size(); i++) {
        sprites[i]->draw();
    }
    
    light->draw();
    light->disable();
}

void Scenario::update(){
    updateSprites();
    environment->update();
    light->update();
    player.move();
    if (seed.getTraversal() == Seed::WALK)
        player.setNewHeight();
    
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
            return new None(seed);
            break;
    }
}

// SPRITES
void Scenario::setSprites(){
    // TODO: DENSITY
    for (int i = 0; i < 50; i++) {
        sprites.push_back(shared_ptr<Sprite>(new Crystal(spriteSeed)));
        sprites.push_back(shared_ptr<Sprite>(new Tree(spriteSeed)));
        
    }
}

void Scenario::updateSprites(){
    for (int i = 0; i < sprites.size(); i++) {
        sprites[i]->update();
    }
}

// PLAYER

void Scenario::setPlayer(Seed lSeed){
    player.setSeed(lSeed);
    player.setMovementType();
    player.setInitHeight();
}

// LIGHT

// TODO: handle cloudy

Light * Scenario::getLight(){
    switch (seed.getLightType()){
        case Seed::SUN:
            return new Sun(seed);
            break;
        case Seed::MOON:
            return new Moon(seed);
            break;
            //        case Seed::CLOUDY:
            //            return new Cloudy(seed);
            //            break;
    }
}


void Scenario::reset(){
    delete light;
    delete environment;
}
