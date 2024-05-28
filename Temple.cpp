//
// Created by tea on 5/18/24.
//

#include "Temple.h"
using namespace std;

Temple::Temple()
{
    Coord c(-1,-1);
    p = new Player(c);
}

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
            cerr << "Random Enemy Error" << endl;
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

    int numRooms = randInt(3,6);
    Square s[numRooms];
    for(int i = 0;i < numRooms; i++){
        s[i] = Square(randInt(2,16),randInt(2,68), randInt(2,3), randInt(6,12));
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
            for(int i = s[sq].cc; i <= s[sq+1].cc;i++){
                floor[s[sq].cr][i] = ' ';
            }
        } else {
            for(int i = s[sq+1].cc; i <= s[sq].cc;i++){
                floor[s[sq].cr][i] = ' ';
            }
        }

        if(s[sq].cr < s[sq+1].cr){
            for(int i = s[sq].cr; i <= s[sq+1].cr;i++){
                floor[i][s[sq].cc] = ' ';
            }
        } else {
            for(int i = s[sq+1].cc; i <= s[sq].cr;i++){
                floor[i][s[sq].cc] = ' ';
            }
        }
    }

    for(int sq =numRooms-1;sq>0;sq--){ // Adds Paths between rooms
        if(s[sq].cr < s[sq-1].cr){
            for(int i = s[sq].cr; i <= s[sq-1].cr;i++){
                floor[i][s[sq].cc] = ' ';
            }
        } else {
            for(int i = s[sq-1].cr; i <= s[sq].cr;i++){
                floor[i][s[sq].cc] = ' ';
            }
        }

        if(s[sq].cc < s[sq-1].cc){
            for(int i = s[sq].cc; i <= s[sq-1].cc;i++){
                floor[s[sq].cr][i] = ' ';
            }
        } else {
            for(int i = s[sq-1].cc; i <= s[sq].cc;i++){
                floor[s[sq].cr][i] = ' ';
            }
        }
    }

    for(int i = 0;i<18;i++){ // Makes sure the sides are walls
        floor[i][0] = '#';
    }
    for(int i = 0;i<18;i++){
        floor[i][69] = '#';
    }
    for(int i = 0;i<70;i++){
        floor[0][i] = '#';
    }
    for(int i = 0;i<70;i++){
        floor[17][i] = '#';
    }
}

// M = randInt(2, 5*(L+1)+1)
void Temple::populateFloor() {
    p->move(randomPlacement());
    floor[p->getCoords().r()][p->getCoords().c()] = p->symbol();

    loot.empty();
    enemies.empty();

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

void Temple::printFloor() {
    for(int i = 0; i< loot.size();i++){
        floor[loot[i]->getCoords().r()][loot[i]->getCoords().c()] = loot[i]->symbol();
    }
    for(int i = 0; i< enemies.size();i++){
        floor[enemies[i]->getCoords().r()][enemies[i]->getCoords().c()] = enemies[i]->symbol();
    }
    floor[p->getCoords().r()][p->getCoords().c()] = p->symbol();

    for(int i=0;i<18;i++){
        for(int j=0;j<70;j++){
            cout << floor[i][j];
        }
        cout << endl;
    }

    cout << "Level: " << level << ", Hit points: " << p->getHp() << ", Armor: " << p->getArm() << ", Strength: " << p->getStr() << ", Dextarity: " << p->getDex() << endl;
}

Objects *Temple::getObjectLocation(Coord c) const{
    for(int i = 0;i < loot.size();i++){
        if(loot[i]->getCoords().r() == c.r() && loot[i]->getCoords().c() == c.c()){
            return loot[i];
        }
    }
    return nullptr;
}

Actors *Temple::getEnemyLocation(Coord c) const{
    for(int i = 0;i < enemies.size();i++){
        if(enemies[i]->getCoords().r() == c.r() && enemies[i]->getCoords().c() == c.c()){
            return enemies[i];
        }
    }
    return nullptr;
}

//attackerPoints = attackerDexterity + weaponDexterityBonus;
//defenderPoints = defenderDexterity + defenderArmorPoints;
//if (randInt(1, attackerPoints) >= randInt(1, defenderPoints))
//attacker has hit defender
//damagePoints = randInt(0, attackerStrength + weaponDamageAmount - 1);
void Temple::attack(Actors *attacker, Actors *defender) {
    int attackerPoints = attacker->getDex() + attacker->getWeapon()->getDexBonus();
    int defenderPoints = defender->getDex() + defender->getArm();
    if(randInt(1,attackerPoints) >= randInt(1, defenderPoints)){
        int damagePoints = randInt(0, attacker->getStr() + attacker->getWeapon()->getDmgBonus() -1);
        defender->decHp(damagePoints);
        cout << attacker->name() << " " << attacker->getWeapon()->getAttackString() << " " << defender->name() << " and Hits!" << endl;
    } else {
        cout << attacker->name() << " " << attacker->getWeapon()->getAttackString() << " " << defender->name() << " but misses!" << endl;
    }
}

bool Temple::playerTurn(char t) {
    if(t == 'g'){
        Objects* item = Temple::getObjectLocation(p->getCoords());
        if(item == nullptr) {
            return false;
        }
        if(item->getName()=="Idol"){
            return true;
        }
        if(item->getName()!="Stairway") {
            p->pickedUp(item);
        }
    }

    if(t == 'i'){
        p->printInv();
    }

    if(t == 'w'){
        p->printInv();
        char i;
        cin >> i;
        cout << endl;
        i-='`';
        int j = int(i);

        p->changeWp(j);
    }

    if(t == 'r'){
        p->printInv();
        char i = getCharacter();
        cout << endl;
        i-='`';
        int j = int(i);

        p->readScroll(j);
    }

    if(t == '>'){
        Objects* item = Temple::getObjectLocation(p->getCoords());
        if(item->getName()=="Stairway") {
            return true;
        }
    }

    if(t == 'h'){
        Coord c(p->getCoords().r(),p->getCoords().c()-1);
        Actors* enem = Temple::getEnemyLocation(c);
        if(enem != nullptr){
            attack(p,enem);
        }else {
            char m = floor[p->getCoords().r()][p->getCoords().c()-1];

            if(m == ' ' || m == '(' || m == '&' || m == '>'){
                floor[p->getCoords().r()][p->getCoords().c()] = ' ';
                p->move(Coord(p->getCoords().r(),p->getCoords().c()-1));
            }
        }
    }
    else if(t == 'l'){
        Coord c(p->getCoords().r(),p->getCoords().c()+1);
        Actors* enem = Temple::getEnemyLocation(c);
        if(enem != nullptr){
            attack(p,enem);
        } else {
            char m = floor[p->getCoords().r()][p->getCoords().c()+1];
            if(m == ' ' || m == '(' || m == '&' || m == '>'){
                floor[p->getCoords().r()][p->getCoords().c()] = ' ';
                p->move(Coord(p->getCoords().r(),p->getCoords().c()+1));
            }
        }
    }
    else if(t == 'k'){
        Coord c(p->getCoords().r()-1,p->getCoords().c());
        Actors* enem = Temple::getEnemyLocation(c);
        if(enem != nullptr){
            attack(p,enem);
        } else {
            char m = floor[p->getCoords().r()-1][p->getCoords().c()];
            if(m == ' ' || m == '(' || m == '&' || m == '>'){
                floor[p->getCoords().r()][p->getCoords().c()] = ' ';
                p->move(Coord(p->getCoords().r()-1,p->getCoords().c()));
            }
        }
    }
    else if(t == 'j'){
        Coord c(p->getCoords().r()+1,p->getCoords().c());
        Actors* enem = Temple::getEnemyLocation(c);
        if(enem != nullptr){
            attack(p,enem);
        } else {
            char m = floor[p->getCoords().r()+1][p->getCoords().c()];
            if(m == ' ' || m == '(' || m == '&' || m == '>'){
                floor[p->getCoords().r()][p->getCoords().c()] = ' ';
                p->move(Coord(p->getCoords().r()+1,p->getCoords().c()));
            }
        }
    }

    if(t == 'c'){
        p->incDex(50);
        p->incStr(50);
        p->incArm(50);
        p->incMaxHp(50);
        p->incHp(50);
    }

    return false;
}

