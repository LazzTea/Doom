//
// Created by tea on 5/16/24.
//

#ifndef PROJECT3_DRAGONS_H
#define PROJECT3_DRAGONS_H

#include "Actors.h"
#include "ScrollsOfEnhancedDexterity.h"
#include "ScrollsOfEnhancedHealth.h"
#include "ScrollsOfRaisedStrength.h"
#include "ScrollsOfImprovedArmor.h"
#include "ScrollsOfTeleportation.h"

class Dragons : public Actors{
public:
    Dragons(Coord c);
    inline ~Dragons() {}

    // Member Functions
    inline char symbol() const { return 'D'; } // Override
    inline std::string name() const { return "the Dragon"; } // Override
    Objects* drops(); // Override
    Coord turn(const char floor[18][70], Actors* a);
};


#endif //PROJECT3_DRAGONS_H
