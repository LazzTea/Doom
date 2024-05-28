//
// Created by tea on 5/16/24.
//

#ifndef PROJECT3_MACES_H
#define PROJECT3_MACES_H

#include "Weapons.h"

class Maces : public Weapons{
public:
    Maces();
    inline ~Maces() {}

    // Member Functions
    virtual std::string getAttackString() const;
};


#endif //PROJECT3_MACES_H
