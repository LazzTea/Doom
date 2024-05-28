//
// Created by tea on 5/16/24.
//

#include "LongSwords.h"

LongSwords::LongSwords()
: Weapons("long sword", 2 ,4)
{}

std::string LongSwords::getAttackString() const {
    return " swings long sword at ";
}