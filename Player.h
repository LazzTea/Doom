//
// Created by tea on 5/16/24.
//

#ifndef PROJECT3_PLAYER_H
#define PROJECT3_PLAYER_H

#include <vector>
#include "Actors.h"
#include "Scrolls.h"


class Player : public Actors{
public:
    Player(Coord c);
    inline ~Player() {}

    void pickedUp(Objects* o);
    void readScroll(int i);
    void changeWp(int i);
    inline char symbol() { return '@'; }
    inline std::string name() { return "Player"; }
    void printInv() const;
    void turn(Player* p);
private:
    std::vector<Objects*> inv;
};


#endif //PROJECT3_PLAYER_H
