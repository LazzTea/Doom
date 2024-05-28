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
    inline std::string name() const { return "the Goblin"; }
    Objects* drop();
    Coord turn(const char floor[18][70], Actors* a);
    bool findPath(char maze[18][70], int sr, int sc, int er, int ec, int n, int& dist);
};


#endif //PROJECT3_GOBLINS_H
