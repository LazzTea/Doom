//
// Created by tea on 5/16/24.
//

#include "Player.h"
using namespace std;

Player::Player(Coord c) : Actors(c, 20, 2, 2, 2, 20, new ShortSwords)
{
    inv.push_back(Actors::getWeapon());
}

void Player::pickedUp(Objects* o) { // handles picking up object
    if(inv.size()>=20)
        return;
    o->pickUp();
    inv.push_back(o);
}

void Player::readScroll(int i, Coord c) { // Reads scrolls
    if(i+1 > inv.size())
        return;
    Scrolls* sc = dynamic_cast<Scrolls*>(inv[i]);
    if(sc != nullptr){
        cout << "Player reads scroll " << sc->getName() << endl;
        sc->read(this, c);
        inv.erase(inv.begin()+i);
    }
}

void Player::changeWp(int i) { // Adds weapon to hand
    if(i+1 > inv.size())
        return;
    Weapons* wp = dynamic_cast<Weapons*>(inv[i]);
    if(wp != nullptr){
        cout << "Player changed weapon to " << wp->getName() << endl;
        Actors::changeWeapon(wp);
    }
}

void Player::printInv() const { // displays the inventory
    cout << "Inventory:" << endl;
    for(int i = 0; i < inv.size(); i++){
        cout << char(97+i) << ". " << inv[i]->getName() << endl;
    }
}

Coord Player::turn(const char floor[18][70], Actors* a) { // extra function for player not implemented
    return Coord(-1,-1);
}

