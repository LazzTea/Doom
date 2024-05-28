//
// Created by tea on 5/27/24.
//

#ifndef PROJECT3_IDOL_H
#define PROJECT3_IDOL_H


#include "Objects.h"

class Idol : public Objects{
public:
    Idol();

    // Member Functions
    char symbol() const { return '&'; } // Override
private:
};


#endif //PROJECT3_IDOL_H
