//
//  History.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#include "History.h"

History::History(){};


void History::addHistory(int type){
    
}

History::Present History::getPresent(){
    return present;
}

void History::setPresent(){
    
    // TRAVERSAL
    // 0 = ORBIT, 1 = WALK, 2 = FLOAT, 3 = FLY
    present.traversal = ofRandom(4);
    
    // DEBUG:
//    present.traversal = 0;
    
    // MEDIUM
    // 0 = AIR, 1 = VOID, 2 = WATER
    if (present.traversal == 0 || present.traversal == 1){
        present.medium = ofRandom(2);
    }
    else if (present.traversal == 3){
        do{
            present.medium = ofRandom(3);
        }
        while (present.medium == 1);
    }
    else present.medium = ofRandom(3);
    
    
    // SURFACE_TYPE
    // 0 = WATER, 1 = GROUND, 2 = VOID, 3 = NONE
    
    // ORBIT
    if (present.traversal == 0){
        do{
            present.surface = ofRandom(4);
        }
        while (present.surface == 3);
    }
    // WALK
    else if (present.traversal == 1){
        present.surface = 1;
    }
    // FLOAT
    else if (present.traversal == 2){
        do{
            present.surface = ofRandom(4);
        }
        while (present.surface == 0 || present.surface == 2);
    }
    // FLY:
    else if (present.traversal == 3 && present.medium == 0){
        do{
            present.surface = ofRandom(4);
        }
        while (present.surface == 1 || present.surface == 2);
    }
    else if (present.traversal == 3 && present.medium == 3){
        do{
            present.surface = ofRandom(4);
        }
        while (present.surface == 0 || present.surface == 1);
    }
    // DEBUG:
    present.surface = 1;
    
//    present.medium = ofRandom(2);
//    present.surface = ofRandom(4);
}