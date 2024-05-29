//
// Created by tea on 5/18/24.
//

#ifndef PROJECT3_SCROLLSOFENHANCEDHEALTH_H
#define PROJECT3_SCROLLSOFENHANCEDHEALTH_H

#include "Scrolls.h"

class ScrollsOfEnhancedHealth : public Scrolls{ // Increases users max health
public:
    ScrollsOfEnhancedHealth();
    inline ~ScrollsOfEnhancedHealth() {}

    // Member Functions
    void read(Player* p, Coord c); // Override
};


#endif //PROJECT3_SCROLLSOFENHANCEDHEALTH_H
