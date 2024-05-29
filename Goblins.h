//
// Created by tea on 5/16/24.
//

#ifndef PROJECT3_GOBLINS_H
#define PROJECT3_GOBLINS_H

#include "Actors.h"
#include <vector>

class Goblins : public Actors{
public:
    Goblins(Coord c,int smell);
    inline ~Goblins() {}

    // Member Functions
    inline char symbol() const { return 'G'; }
    inline std::string name() const { return "the Goblin"; }
    Objects* drop();
    Coord turn(const char floor[18][70], Actors* a);
    void findPath(char (*maze)[70], std::vector<Coord>& shortestPath, std::vector<Coord>& curPath, Coord start, Coord end, int optimalDistance);
    bool isValid(char c) const;
private:
    int smell;
};


#endif //PROJECT3_GOBLINS_H
