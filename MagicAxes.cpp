//
// Created by tea on 5/16/24.
//

#include "MagicAxes.h"

MagicAxes::MagicAxes()
: Weapons("magic axe", 5, 5)
{}

std::string MagicAxes::getAttackString() const {
    return " chops ";
}