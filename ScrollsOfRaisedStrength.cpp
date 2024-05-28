//
// Created by tea on 5/18/24.
//

#include "ScrollsOfRaisedStrength.h"
#include "Player.h"

ScrollsOfRaisedStrength::ScrollsOfRaisedStrength() : Scrolls("Scrolls of Raised Strength")
{}

void ScrollsOfRaisedStrength::read(Player *p) {
    p->incStr(randInt(1,3));
}
