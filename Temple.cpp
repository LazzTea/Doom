//
// Created by tea on 5/18/24.
//

#include "Temple.h"
using namespace std;

Temple::Temple()
{}

Actors* Temple::randomEnemy() {
    int i;
    switch (level) {
        case 0:
        case 1:
            i = randInt(0, 1);
            break;
        case 2:
            i = randInt(0, 2);
            break;
        case 3:
        case 4:
            i = randInt(0, 3);
            break;
        default:
            cerr << "Random Enemy" << endl;
            exit(1);
    }

    Coord c = randomPlacement();
    switch (i) {
        case 0:
            return new Snakewomen(c);
        case 1:
            return new Goblins(c);
        case 2:
            return new Bogeymen(c);
        case 3:
            return new Dragons(c);
        default:
            cerr << "Random Enemy" << endl;
            exit(1);
    }
}

Objects *Temple::randomObject() {
    int i = randInt(1,7);
    switch (i) {
        case 1:
            return new ShortSwords;
        case 2:
            return new LongSwords;
        case 3:
            return new Maces;
        case 4:
            return new ScrollsOfEnhancedDexterity;
        case 5:
            return new ScrollsOfEnhancedHealth;
        case 6:
            return new ScrollsOfRaisedStrength;
        case 7:
            return new ScrollsOfImprovedArmor;
        default:
            cerr << "Random Object Error" << endl;
            exit(1);
    }
}

Coord Temple::randomPlacement() const {
    while(true){
        int row = randInt(1,17);
        int col = randInt(1,69);

        if(floor[row][col] == ' '){
            Coord c(row,col);
            return c;
        }
    }
}

void Temple::buildFloor() {
    for(int i = 0; i < 18; i++){ // Fills with #
        for(int j=0;j<70;j++){
            floor[i][j] = '#';
        }
    }

    int numRooms = randInt(4,8);
    Square s[numRooms];
    for(int i = 0;i < numRooms; i++){
        s[i] = Square(randInt(3,15),randInt(3,67), randInt(2,4), randInt(6,18));
    }

    for(int i = 1; i <17; i++){ // Removes # if in a square
        for(int j=1;j<69;j++){
            for(int sq=0;sq<numRooms;sq++){
                if(i>=s[sq].r && i<=s[sq].r+s[sq].h && j>=s[sq].c && j<=s[sq].c+s[sq].w){
                    floor[i][j]=' ';
                }
            }
        }
    }

    for(int sq = 0;sq<numRooms-1;sq++){ // Adds Paths between rooms
        if(s[sq].cc < s[sq+1].cc){
            for(int i = s[sq].cc; i <s[sq+1].cc;i++){
                floor[s[sq].cr][i] = ' ';
            }
        } else {
            for(int i = s[sq+1].cc; i <s[sq].cc;i++){
                floor[s[sq].cr][i] = ' ';
            }
        }

        if(s[sq].cr < s[sq+1].cr){
            for(int i = s[sq].cr; i <s[sq+1].cr;i++){
                floor[i][s[sq].cc] = ' ';
            }
        } else {
            for(int i = s[sq+1].cc; i <s[sq].cr;i++){
                floor[i][s[sq].cc] = ' ';
            }
        }
    }

//    for(int i = 0;i<18;i++){ // Makes sure the sides are walls
//        floor[i][0] = '#';
//    }
//    for(int i = 0;i<18;i++){
//        floor[i][17] = '#';
//    }
//    for(int i = 0;i<70;i++){
//        floor[0][i] = '#';
//    }
//    for(int i = 0;i<70;i++){
//        floor[69][i] = '#';
//    }


}

// M = randInt(2, 5*(L+1)+1)
void Temple::populateFloor() {
    int M = randInt(2, 5*(level+1)+1);
    for(int i=0; i < M; i++){
        Actors* a = randomEnemy();
        enemies.push_back(a);
        floor[a->getCoords().r()][a->getCoords().c()] = a->symbol();
    }

    int O = randInt(2,3);

    for(int i=0; i < O; i++){
        Objects* o =randomObject();
        o->place(randomPlacement());
        loot.push_back(o);
        floor[o->getCoords().r()][o->getCoords().c()] = o->symbol();
    }

    if(level==4){
        Objects* o = new Idol;
        o->place(randomPlacement());
        loot.push_back(o);
        floor[o->getCoords().r()][o->getCoords().c()] = o->symbol();
    } else {
        Objects* o = new Stairway;
        o->place(randomPlacement());
        loot.push_back(o);
        floor[o->getCoords().r()][o->getCoords().c()] = o->symbol();
    }
}

void Temple::printFloor() const {
    for(int i=0;i<18;i++){
        for(int j=0;j<70;j++){
            cout << floor[i][j];
        }
        cout << endl;
    }
}

