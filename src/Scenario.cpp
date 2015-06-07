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
    environment = new Environment(moon, *new Ground(seed), *new Void(seed));
//    history.addHistory(1);
    this->setPlayer();
}

void Scenario::draw(){
    environment->draw();
    player.draw();
//    this->setPlayer();
}


void Scenario::setPlayer(){
    setPlayerMovement();
    setPlayerLocation();
    
}


void Scenario::setPlayerMovement(){
    player.setMovementType(Controls::ORBIT);
}

void Scenario::setPlayerLocation(){
    switch (player.getMovementType()){
        case Controls::FLOAT:
            cout << "FLOAT" << endl;
            break;
        case Controls::WALK:
            cout << "WALK" << endl;
            break;
        case Controls::FLY:
            cout << "FLY" << endl;
            break;
        case Controls::ORBIT:
            player.setLocation(ofVec3f(0, seed.getRadius(), 0));
            break;
    }
}