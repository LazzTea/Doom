//
// Created by tea on 5/16/24.
//

#include "ShortSwords.h"

ShortSwords::ShortSwords()
: Weapons("short sword", 0, 2)
{}

std::string ShortSwords::getAttackString() const {
    return " swings their short sword at ";
}