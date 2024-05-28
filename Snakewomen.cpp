//
// Created by tea on 5/16/24.
//

#include "Snakewomen.h"
#include <cmath>

Snakewomen::Snakewomen(Coord c)
: Actors(c, randInt(3,6), 3, 2, 3, 6, new MagicFang)
{}

Objects *Snakewomen::drops() {
    if(randInt(1,3) == 3)
        return new MagicFang;
    return nullptr;
}

Coord Snakewomen::turn(const char floor[18][70], Actors *a) { // Same as the Bogeymans which is explained in the bogeyman class but it has 3 distance rather than 5
    if((std::abs(this->getCoords().r() - a->getCoords().r()) + std::abs(this->getCoords().c() - a->getCoords().c())) <= 3){
        double dist = (std::sqrt(std::pow((this->getCoords().r() - a->getCoords().r()),2) + std::pow((this->getCoords().c() - a->getCoords().c()),2)));

        if(this->getCoords().r() > a->getCoords().r()){
            char t = floor[this->getCoords().r()-1][this->getCoords().c()];
            if(t == ' ' || t == '(' || t == '&' || t == '>' || t == '@'){
                return Coord(this->getCoords().r()-1, this->getCoords().c());
            }
        }
        if(this->getCoords().r() < a->getCoords().r()){
            char t = floor[this->getCoords().r()+1][this->getCoords().c()];
            if(t == ' ' || t == '(' || t == '&' || t == '>' || t == '@'){
                return Coord(this->getCoords().r()+1, this->getCoords().c());
            }
        }
        if(this->getCoords().c() > a->getCoords().c()){
            char t = floor[this->getCoords().r()][this->getCoords().c()-1];
            if(t == ' ' || t == '(' || t == '&' || t == '>' || t == '@'){
                return Coord(this->getCoords().r(), this->getCoords().c()-1);
            }
        }
        if(this->getCoords().c() <a->getCoords().c()){
            char t = floor[this->getCoords().r()][this->getCoords().c()+1];
            if(t == ' ' || t == '(' || t == '&' || t == '>' || t == '@'){
                return Coord(this->getCoords().r(), this->getCoords().c()+1);
            }
        }
    }

    return Coord(this->getCoords().r(), this->getCoords().c());
}
