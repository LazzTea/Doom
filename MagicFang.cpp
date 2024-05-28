//
// Created by tea on 5/16/24.
//

#include "MagicFang.h"

MagicFang::MagicFang()
: Weapons("Magic Fang of Sleep", 3, 2)
{}

std::string MagicFang::getAttackString() const {
    return "stabs their Magic Fang of Sleep at";
}