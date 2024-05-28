//
// Created by tea on 5/16/24.
//

#ifndef PROJECT3_MAGICFANG_H
#define PROJECT3_MAGICFANG_H

#include "Weapons.h"

class MagicFang : public Weapons{
public:
    MagicFang();
    inline ~MagicFang() {}

    //Member Functions
    virtual std::string getAttackString() const;
};


#endif //PROJECT3_MAGICFANG_H
