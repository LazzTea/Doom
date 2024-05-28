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

Coord Dragons::turn(Player *p) {
    if(randInt(1,10)==10)
        this->incHp();

    if(this->getCoords().r()+1 == p->getCoords().r() && this->getCoords().c() == p->getCoords().c()){
        return Coord(this->getCoords().r()+1,this->getCoords().c());
    }
    if(this->getCoords().r()-1 == p->getCoords().r() && this->getCoords().c() == p->getCoords().c()){
        return Coord(this->getCoords().r()-1,this->getCoords().c());
    }
    if(this->getCoords().c()+1 == p->getCoords().c() && this->getCoords().r() == p->getCoords().r()){
        return Coord(this->getCoords().r()+1,this->getCoords().c());
    }
    if(this->getCoords().c()-1 == p->getCoords().c() && this->getCoords().r() == p->getCoords().r()){
        return Coord(this->getCoords().r()-1,this->getCoords().c());
    }

    return Coord(this->getCoords().r(),this->getCoords().c());
}