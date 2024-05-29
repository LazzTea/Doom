//
// Created by tea on 5/16/24.
//

#include "Actors.h"
using namespace std;

Actors::Actors(Coord c, int hpSt, int armSt, int strSt, int dexSt, int maxHpSt, Weapons* wpSt)
        : m_c(c), hp(hpSt), arm(armSt), str(strSt), dex(dexSt), maxHp(maxHpSt), wp(wpSt)
{}

Actors::~Actors() {
    if(wp != nullptr){
        delete wp;
        wp = nullptr;
    }
}


