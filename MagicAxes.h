//
// Created by tea on 5/16/24.
//

#ifndef PROJECT3_MAGICAXES_H
#define PROJECT3_MAGICAXES_H

#include "Weapons.h"

class MagicAxes : public Weapons{
public:
    MagicAxes();

    // Member Function
    virtual std::string getAttackString() const;
};


#endif //PROJECT3_MAGICAXES_H
