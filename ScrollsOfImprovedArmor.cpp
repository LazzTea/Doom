//
// Created by tea on 5/18/24.
//

#include "ScrollsOfImprovedArmor.h"
#include "Player.h"

ScrollsOfImprovedArmor::ScrollsOfImprovedArmor()
: Scrolls("Scrolls of Improved Armor")
{}

void ScrollsOfImprovedArmor::read(Player *p, Coord c) {
    p->incArm(randInt(1,3));
}