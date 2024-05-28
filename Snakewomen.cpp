//
// Created by tea on 5/16/24.
//

#include "Snakewomen.h"

Snakewomen::Snakewomen(Coord c)
: Actors(c, randInt(3,6), 3, 2, 3, 6, new MagicFang)
{}

Objects *Snakewomen::drops() {
    if(randInt(1,3) == 3)
        return new MagicFang;
    return nullptr;
}

void Snakewomen::turn(Player *p) {
    return;
}