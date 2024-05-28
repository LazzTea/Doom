//
// Created by tea on 5/18/24.
//

#ifndef PROJECT3_SCROLLSOFTELEPORTATION_H
#define PROJECT3_SCROLLSOFTELEPORTATION_H

#include "Scrolls.h"
#include "Coord.h"

class ScrollsOfTeleportation : public Scrolls{
public:
    ScrollsOfTeleportation();

    // Member Function
    void read(Player *p, Coord c); // Override
private:
};


#endif //PROJECT3_SCROLLSOFTELEPORTATION_H
