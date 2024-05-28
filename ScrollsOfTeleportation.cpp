//
// Created by tea on 5/18/24.
//

#include "ScrollsOfTeleportation.h"
#include "Player.h"

ScrollsOfTeleportation::ScrollsOfTeleportation()
: Scrolls("Scrolls of Teleportation")
{}

void ScrollsOfTeleportation::read(Player *p, Coord c) {
    p->move(c);
}