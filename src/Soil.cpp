//
//  Soil.cpp
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.



#include "Soil.h"


Soil::Soil(){
    present = history.getPresent();
};

bool Soil::isOrbital(){
    return (present.traversal == 0);
}