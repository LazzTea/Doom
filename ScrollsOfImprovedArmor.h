//
// Created by tea on 5/18/24.
//

#ifndef PROJECT3_SCROLLSOFIMPROVEDARMOR_H
#define PROJECT3_SCROLLSOFIMPROVEDARMOR_H

#include "Scrolls.h"

class ScrollsOfImprovedArmor : public Scrolls{ // Increases users armor
public:
    ScrollsOfImprovedArmor();

    // Member Functions
    void read(Player* p, Coord c); // Override
};


#endif //PROJECT3_SCROLLSOFIMPROVEDARMOR_H
