//
// Created by tea on 5/16/24.
//

#include "Player.h"
using namespace std;

Player::Player(Coord c) : Actors(c, 20, 2, 2, 2, 20, new ShortSwords)
{
    inv.push_back(Actors::getWeapon());
}

void Player::pickedUp(Objects* o) {
    if(inv.size()>=20)
        return;
    o->pickUp();
    inv.push_back(o);
}

void Player::readScroll(int i) {
    Scrolls* sc = dynamic_cast<Scrolls*>(inv[i]);
    if(sc != nullptr){
        sc->read(this);
        inv.erase(inv.begin()+i);
    }
}

void Player::changeWp(int i) {
    Weapons* wp = dynamic_cast<Weapons*>(inv[i]);
    if(wp != nullptr){
        Actors::changeWeapon(wp);
    }
}

void Player::printInv() const {
    cout << "Inventory:" << endl;
    for(int i = 0; i < inv.size(); i++){
        cout << char(61+i) << ". " << inv[i]->getName() << endl;
    }
}

Coord Player::turn(const char floor[18][70], Actors* a) {
    return Coord(-1,-1);
}

