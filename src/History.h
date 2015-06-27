//
//  History.h
//  Wandering2
//
//  Created by J Andrew Gormley on 2015-05-31.
//
//

#pragma once

#ifndef __Wandering2__History__
#define __Wandering2__History__
#include <stdio.h>
#include "ofMain.h"

#endif /* defined(__Wandering2__History__) */


class History {
public:
    History();
    void addHistory(int t, int m, int s);
    vector<int> calculatePresent();
    int calculateTraversal();
    int calculateMedium(int nt);
    int calculateSurface(int nt, int nm);
    
    struct Present {
        int traversal;
        int medium;
        int surface;
    };
    
    struct Past {
        int traversal[4]={};
        int medium[3]={};
        int surface[4]={};
    };
    
    Present getPresent();
    void setPresent();
    Present present;
    Past past;
};