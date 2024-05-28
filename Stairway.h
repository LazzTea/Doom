//
// Created by tea on 5/27/24.
//

#ifndef PROJECT3_STAIRWAY_H
#define PROJECT3_STAIRWAY_H

#include "Objects.h"

class Stairway : public Objects{
public:
    Stairway();

    // Member Functions
    char symbol() const { return '>'; } // Override
private:
};


#endif //PROJECT3_STAIRWAY_H
