//
// Created by tea on 5/16/24.
//

#ifndef PROJECT3_SHORTSWORDS_H
#define PROJECT3_SHORTSWORDS_H

#include "Weapons.h"

class ShortSwords : public Weapons{
public:
    ShortSwords();

    // Member Functions
    virtual std::string getAttackString() const;
};


#endif //PROJECT3_SHORTSWORDS_H
