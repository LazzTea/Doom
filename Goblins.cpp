//
// Created by tea on 5/16/24.
//

#include "Goblins.h"

Goblins::Goblins(Coord c)
: Actors(c, randInt(15,20), 1, 3, 1, 20, new ShortSwords)
{}

Objects *Goblins::drop() {
    if(randInt(1,3)==3){
        if(randInt(1,2)==2){
            return new MagicFang;
        }else{
            return new MagicAxes;
        }
    }
    return nullptr;
}

void Goblins::turn(Player *p) {
    return;
}