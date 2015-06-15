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
    light->setPosition(ofVec3f(light->getPosition().x, x, y));
}

void Scenario::setNew(){
    
    // ensure the seed is populated before anything else is set
    seed.populate();
    // set the environment to new seed values
    environment = new Environment(*getSurface(), *getMedium());
    spriteSeed = SpriteSeed(seed, environment->getSurfaceVerts());
    
    // set light to new seed values
    light = getLight();
    
    // set the player to new seed values
    setPlayer(seed);
    
    // TODO: FIX
    sprites.clear();
    setSprites();
    
    
    //    history.addHistory(1);
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
            return new None(seed);
            break;
    }
}

// SPRITES
void Scenario::setSprites(){
    // TODO: DENSITY
    for (int i = 0; i < 100; i++) {
        sprites.push_back(shared_ptr<Sprite>(new Plant(spriteSeed)));
    }
    
//    for (int i = 0; i < 200; i++) {
//        sprites.push_back(shared_ptr<Sprite>(new Animal()));
//    }
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

// LIGHT

Light * Scenario::getLight(){
    switch (seed.getLightType()){
        case Seed::SUN:
            return new Sun(seed);
            break;
//        case Seed::MOON:
//            return new Moon(seed);
//            break;
//        case Seed::CLOUDY:
//            return new Cloudy(seed);
//            break;
    }
}

