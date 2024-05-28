//
// Created by tea on 5/16/24.
//

#ifndef PROJECT3_LONGSWORDS_H
#define PROJECT3_LONGSWORDS_H

#include "Weapons.h"

class LongSwords : public Weapons{
public:
    LongSwords();
    inline ~LongSwords() {}

    // Member Functions
    virtual std::string getAttackString() const;
};


#endif //PROJECT3_LONGSWORDS_H
