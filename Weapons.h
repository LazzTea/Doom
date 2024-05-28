//
// Created by tea on 5/16/24.
//

#ifndef PROJECT3_WEAPONS_H
#define PROJECT3_WEAPONS_H

#include "Objects.h"

class Weapons : public Objects{
public:
    Weapons(std::string name, int dexBonus, int dmgBonus);

    // Member Functions
    virtual std::string getAttackString() const = 0;
    virtual inline char symbol() const { return ')'; };

    inline int getDexBonus() const { return dexBonus; }
    inline int getDmgBonus() const { return dmgBonus; }

    inline void addDexBonus(int dexPoints) { dexBonus += dexPoints; }
    inline void addDmgBonus(int dmgPoints) { dmgBonus += dmgPoints; }
private:
    int dexBonus, dmgBonus;
};


#endif //PROJECT3_WEAPONS_H
