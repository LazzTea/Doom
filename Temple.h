//
// Created by tea on 5/18/24.
//

#ifndef PROJECT3_TEMPLE_H
#define PROJECT3_TEMPLE_H

#include <vector>
#include "Coord.h"
#include "Actors.h"
#include "Player.h"
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
    Temple(int smell);
    ~Temple();

    // Member Functions
    Actors* randomEnemy(); // Functions to get random values
    Objects* randomObject();
    Coord randomPlacement() const;


    void buildFloor(); // Builds and increments the levels
    void populateFloor();
    void printFloor();
    inline void incLevel(){ level++; }
    inline int getLevel() const { return level; }

    Objects* pickUpObject(Coord c); // Gets objects based on their coord
    Actors* getEnemyLocation(Coord c) const;
    Objects* getObjectLocation(Coord c) const;
    void attack(Actors* attacker, Actors* defender); // Determines the out come of fights

    inline Player* getPlayer() { return p; }

    bool playerTurn(char t); // Determines what happens during players turn
    void enemyTurn(); // Determines what happens during enemies turn
private:
    class Square{ // Square class used to create rooms
    public:
        Square() : cr(0), cc(0), h(0), w(0), r(0), c(0) {}
        Square(int cr, int cc, int h, int w) : cr(cr), cc(cc), h(h), w(w){
            r = cr - int(h/2);
            c = cc - int(w/2);
        }

        int cr, cc, h, w, r, c;
    };

    char floor[18][70]; // The floor map
    int level = 0;

    std::vector<Actors*> enemies; // Vectors used to store monsters and objects
    std::vector<Objects*> loot;

    Player* p;

    int smell;
};


#endif //PROJECT3_TEMPLE_H
