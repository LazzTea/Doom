//
// Created by tea on 5/18/24.
//

#include "ScrollsOfEnhancedHealth.h"
#include "Player.h"

ScrollsOfEnhancedHealth::ScrollsOfEnhancedHealth() : Scrolls("Scrolls of Enhanced Health")
{}

void ScrollsOfEnhancedHealth::read(Player *p) {
    p->incMaxHp(randInt(3,8));
}