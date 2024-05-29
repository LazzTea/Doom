//
// Created by tea on 5/18/24.
//

#ifndef PROJECT3_SCROLLSOFTELEPORTATION_H
#define PROJECT3_SCROLLSOFTELEPORTATION_H

#include "Scrolls.h"
#include "Coord.h"

class ScrollsOfTeleportation : public Scrolls{ // teleports user to a random location based on the coords given by the temple class later
public:
    ScrollsOfTeleportation();
    inline ~ScrollsOfTeleportation() {}

    // Member Function
    void read(Player *p, Coord c); // Override
private:
};


#endif //PROJECT3_SCROLLSOFTELEPORTATION_H
