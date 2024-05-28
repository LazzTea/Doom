//
// Created by tea on 5/18/24.
//

#ifndef PROJECT3_SCROLLSOFIMPROVEDARMOR_H
#define PROJECT3_SCROLLSOFIMPROVEDARMOR_H

#include "Scrolls.h"

class ScrollsOfImprovedArmor : public Scrolls{
public:
    ScrollsOfImprovedArmor();

    // Member Functions
    void read(Player* p); // Override
};


#endif //PROJECT3_SCROLLSOFIMPROVEDARMOR_H
