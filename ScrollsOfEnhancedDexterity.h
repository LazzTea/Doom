//
// Created by tea on 5/18/24.
//

#ifndef PROJECT3_SCROLLSOFENHANCEDDEXTERITY_H
#define PROJECT3_SCROLLSOFENHANCEDDEXTERITY_H

#include "Scrolls.h"

class Player;

class ScrollsOfEnhancedDexterity : public Scrolls{
public:
    ScrollsOfEnhancedDexterity();

    // Member Functions
    void read(Player* p); // Override
};


#endif //PROJECT3_SCROLLSOFENHANCEDDEXTERITY_H
