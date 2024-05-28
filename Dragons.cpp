//
// Created by tea on 5/16/24.
//

#include "Dragons.h"

Dragons::Dragons(Coord c)
: Actors(c, 20, 4, 4, 4, randInt(20,25), new LongSwords)
{
    incHp(5);
}

Objects *Dragons::drops() {
    int i = randInt(1,5);
    switch (i) {
        case 1:
            return new ScrollsOfEnhancedDexterity;
        case 2:
            return new ScrollsOfEnhancedHealth;
        case 3:
            return new ScrollsOfRaisedStrength;
        case 4:
            return new ScrollsOfImprovedArmor;
        case 5:
            return new ScrollsOfTeleportation;
        default:
            return nullptr;
    }
}

void Dragons::turn(Player *p) {
    return;
}