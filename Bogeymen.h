//
// Created by tea on 5/16/24.
//

#ifndef PROJECT3_BOGEYMEN_H
#define PROJECT3_BOGEYMEN_H

#include "Actors.h"

class Bogeymen : public Actors{
public:
    Bogeymen(Coord c);
    inline ~Bogeymen() {}

    // Member Function
    inline std::string name() const { return "the Bogeyman"; }
    inline char symbol() const { return 'B'; }
    inline Objects* drop(){
        if(randInt(1,10)==10)
            return new MagicAxes;
        return nullptr;
    }
    Coord turn(const char floor[18][70], Actors* a);
private:
};


#endif //PROJECT3_BOGEYMEN_H
