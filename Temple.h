//
// Created by tea on 5/18/24.
//

#ifndef PROJECT3_TEMPLE_H
#define PROJECT3_TEMPLE_H

#include <vector>
#include "Coord.h"
#include "Actors.h"
#include "Bogeymen.h"
#include "Dragons.h"
#include "Snakewomen.h"
#include "Goblins.h"
#include "Objects.h"
#include "Weapons.h"
#include "ShortSwords.h"
#include "LongSwords.h"
#include "Maces.h"
#include "MagicFang.h"
#include "MagicAxes.h"
#include "Scrolls.h"
#include "ScrollsOfEnhancedDexterity.h"
#include "ScrollsOfEnhancedHealth.h"
#include "ScrollsOfImprovedArmor.h"
#include "ScrollsOfRaisedStrength.h"
#include "ScrollsOfTeleportation.h"
#include "Stairway.h"
#include "Idol.h"
#include "utilities.h"

class Temple {
public:
    Temple();

    // Member Functions
    Actors* randomEnemy();
    Objects* randomObject();
    Coord randomPlacement() const;


    void buildFloor();
    void populateFloor();
    void printFloor() const;

    inline void incLevel(){ level++; }
private:
    class Square{
    public:
        Square() : cr(0), cc(0), h(0), w(0), r(0), c(0) {}
        Square(int cr, int cc, int h, int w) : cr(cr), cc(cc), h(h), w(w){
            r = cr - int(h/2);
            c = cc - int(w/2);
        }

        int cr, cc, h, w, r, c;
    };

    char floor[18][70];
    int level = 0;

    std::vector<Actors*> enemies;
    std::vector<Objects*> loot;
};


#endif //PROJECT3_TEMPLE_H
