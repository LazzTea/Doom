//
// Created by tea on 5/16/24.
//

#ifndef PROJECT3_DRAGONS_H
#define PROJECT3_DRAGONS_H

#include "Actors.h"
#include "Temple.h"

class Dragons : public Actors{
public:
    Dragons(Coord c);
    inline ~Dragons() {}

    // Member Functions
    inline char symbol() const { return 'D'; } // Override
    inline std::string name() const { return "Dragon"; } // Override
    Objects* drops(); // Override
    void turn(Player* p);
};


#endif //PROJECT3_DRAGONS_H
