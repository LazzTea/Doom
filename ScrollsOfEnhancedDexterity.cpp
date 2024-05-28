//
// Created by tea on 5/18/24.
//

#include "ScrollsOfEnhancedDexterity.h"
#include "Player.h"

ScrollsOfEnhancedDexterity::ScrollsOfEnhancedDexterity() : Scrolls("Scrolls of Enhanced Dexterity")
{}

void ScrollsOfEnhancedDexterity::read(Player *p) {
    p->incDex(1);
}