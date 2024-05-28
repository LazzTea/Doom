//
// Created by tea on 5/16/24.
//

#ifndef PROJECT3_ACTORS_H
#define PROJECT3_ACTORS_H

#include "ShortSwords.h"
#include "LongSwords.h"
#include "MagicAxes.h"
#include "MagicFang.h"
#include "Maces.h"
#include "Objects.h"
#include "Weapons.h"
#include "utilities.h"
#include "Coord.h"

class Player;

class Actors { // Base class for all monsters and player
public:
    Actors(Coord c, int hpSt, int armSt, int strSt, int dexSt, int maxHpSt, Weapons* wpSt);
    virtual inline ~Actors(){ delete wp; }

    // Functions for Child Classes
    virtual inline char symbol() const = 0; // The symbol each enemy and play displays on map
    virtual inline std::string name() const = 0;
    virtual inline Objects* drops() { return nullptr; } // This is what enemies drop when they die it will be implemeted by enemy type
    virtual Coord turn(const char floor[18][70], Actors* a) = 0; // What each entity will do during their turn

    // Memeber Functions
    inline void changeWeapon(Weapons* wpNew) { wp = wpNew; }
    inline Weapons* getWeapon() const { return wp; }
    inline void move(Coord c) {
        m_c = c;
    }
    inline Coord getCoords() { return m_c; }


    inline int getHp() const { return hp; }
    inline int getArm() const { return arm; }
    inline int getStr() const { return str; }
    inline int getDex() const { return dex; }
    inline int getMaxHp() const { return maxHp; }
    inline int getSleep() const { return sleep; }

    inline void incHp(int v = 1) {
        if(hp + v >= maxHp){
            hp = maxHp;
        } else {
            hp += v;
        }
    }

    inline void decHp(int v = 1) {
        hp -= v;
        if(hp < 0){
            hp = 0;
        }
    }

    inline void incArm(int v = 1) {
        if(arm + v >= 99)
            arm = 99;
        else
            arm += v;
    }
    inline void incStr(int v = 1) {
        if(str + v >= 99)
            str = 99;
        else
            str += v;
    }
    inline void incDex(int v = 1) {
        if(dex + v >= 99)
            dex = 99;
        else
            dex += v;
    }
    inline void incMaxHp(int v = 1) {
        if(maxHp + v >= 99)
            maxHp = 99;
        else
            maxHp += v;
    }
    inline void setSleep(int v){
        if(v > 9)
            v = 9;
        if(sleep < v)
            sleep = v;
    }
    inline void decSleep(){
        sleep--;
        if(sleep <0)
            sleep = 0;
    }
private:
    Coord m_c;
    int hp, arm, str, dex, maxHp;
    int sleep = 0;
    Weapons* wp;
};


#endif //PROJECT3_ACTORS_H
