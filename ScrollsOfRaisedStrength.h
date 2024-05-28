//
// Created by tea on 5/18/24.
//

#ifndef PROJECT3_SCROLLSOFRAISEDSTRENGTH_H
#define PROJECT3_SCROLLSOFRAISEDSTRENGTH_H

#include "Scrolls.h"

class ScrollsOfRaisedStrength : public Scrolls{ // Increases users strength
public:
    ScrollsOfRaisedStrength();

    // Member Functions
    void read(Player* p, Coord c); // Override
private:
};


#endif //PROJECT3_SCROLLSOFRAISEDSTRENGTH_H
