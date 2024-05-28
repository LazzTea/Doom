//
// Created by tea on 5/16/24.
//

#include "Bogeymen.h"
#include <cmath>

Bogeymen::Bogeymen(Coord c)
: Actors(c, 2, randInt(5,10), randInt(2,3), randInt(2,3), 10, new ShortSwords)
{}

Coord Bogeymen::turn(const char floor[18][70], Actors* a) { // Compares each coordinate to the coordiante for the player to see which direction will reduce the number of moves to get to player
    if((std::abs(this->getCoords().r() - a->getCoords().r()) + std::abs(this->getCoords().c() - a->getCoords().c())) <= 5){
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

