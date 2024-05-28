//
// Created by tea on 5/16/24.
//

#ifndef PROJECT3_GOBLINS_H
#define PROJECT3_GOBLINS_H

#include "Actors.h"

class Goblins : public Actors{
public:
    Goblins(Coord c);
    inline ~Goblins() {}

    // Member Functions
    inline char symbol() const { return 'G'; }
    inline std::string name() const { return "Goblin"; }
    Objects* drop();
    void turn(Player* p);
};


#endif //PROJECT3_GOBLINS_H
