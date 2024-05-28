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
    Coord turn(const char floor[18][70], Actors* a);
private:
};


#endif //PROJECT3_SNAKEWOMEN_H
