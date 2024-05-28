//
// Created by tea on 5/16/24.
//

#include "Bogeymen.h"

Bogeymen::Bogeymen(Coord c)
: Actors(c, 2, randInt(5,10), randInt(2,3), randInt(2,3), 10, new ShortSwords)
{}

Coord Bogeymen::turn(char floor[18][70]) {
    if(ss)
}

