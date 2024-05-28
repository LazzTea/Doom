//
// Created by tea on 5/16/24.
//

#include "Maces.h"

Maces::Maces()
: Weapons("mace", 0, 2)
{}

std::string Maces::getAttackString() const {
    return "crushes their mace at";
}