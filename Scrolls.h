//
// Created by tea on 5/18/24.
//

#ifndef PROJECT3_SCROLLS_H
#define PROJECT3_SCROLLS_H

#include <iostream>
#include "Objects.h"
#include "Player.h"
#include "utilities.h"

class Scrolls : public Objects{
public:
    Scrolls(std::string name);

    // Member Functions
    virtual void read(Player* p, Coord c) = 0;
    inline char symbol() const { return '?'; }
private:
};


#endif //PROJECT3_SCROLLS_H
