//
// Created by tea on 5/16/24.
//

#ifndef PROJECT3_OBJECTS_H
#define PROJECT3_OBJECTS_H

#include <iostream>
#include "Coord.h"

class Objects {
public:
    Objects(std::string name);

    // Member Function
    void place(Coord c);
    void pickUp();
    virtual char symbol() const = 0;

    inline std::string getName() const { return name; }
    inline Coord getCoords() const { return m_c; }
private:
    std::string name;
    Coord m_c;
};


#endif //PROJECT3_OBJECTS_H
