//
// Created by tea on 5/16/24.
//

#ifndef PROJECT3_SNAKEWOMEN_H
#define PROJECT3_SNAKEWOMEN_H

#include "Actors.h"

class Snakewomen : public Actors{
public:
    Snakewomen(Coord c);
    inline ~Snakewomen() {}

    // Member Functions
    inline char symbol() const { return 'S'; } // Override
    inline std::string name() const { return "Snakewomen"; } // Override
    Objects* drops(); // Override
    void turn(Player* p);
private:
};


#endif //PROJECT3_SNAKEWOMEN_H
