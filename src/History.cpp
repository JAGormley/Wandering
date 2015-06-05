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
    envHistory.push_back(type);
}