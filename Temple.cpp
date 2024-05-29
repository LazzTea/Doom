//
// Created by tea on 5/18/24.
//

#include "Temple.h"
using namespace std;

Temple::Temple(int smell) : p(nullptr), smell(smell) // Creates the temple class
{
    Coord c(-1,-1);
    p = new Player(c);
}

Temple::~Temple(){
    if(p){
        delete p;
    }
    for(auto& enemy : enemies) {
        delete enemy;
    }
    enemies.clear();

    for(auto& item : loot) {
        delete item;
    }
    loot.clear();
}

Actors* Temple::randomEnemy() { // gets random enemy depending on level
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
            return new Goblins(c, smell);
        case 2:
            return new Bogeymen(c);
        case 3:
            return new Dragons(c);
        default:
            cerr << "Random Enemy Error" << endl;
            exit(1);
    }
}

Objects *Temple::randomObject() { // gets a random object excluding fang and teleport
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

Coord Temple::randomPlacement() const { // gives a random open coordinate for use
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

    int numRooms = randInt(2,5);
    vector<Square*> s;
    for(int i = 0;i < numRooms; i++){
        s.push_back(new Square(randInt(2,16),randInt(2,68), randInt(2,3), randInt(4,8)));
    }

    for(int i = 1; i <17; i++){ // Removes # if in a square
        for(int j=1;j<69;j++){
            for(int sq=0;sq<numRooms;sq++){
                if(i>=s[sq]->r && i<=s[sq]->r+s[sq]->h && j>=s[sq]->c && j<=s[sq]->c+s[sq]->w){
                    floor[i][j]=' ';
                }
            }
        }
    }

    for(int sq = 0;sq<numRooms-1;sq++){ // Adds Paths between rooms
        if(s[sq]->cc < s[sq+1]->cc){
            for(int i = s[sq]->cc; i <= s[sq+1]->cc;i++){
                floor[s[sq]->cr][i] = ' ';
            }
        } else {
            for(int i = s[sq+1]->cc; i <= s[sq]->cc;i++){
                floor[s[sq]->cr][i] = ' ';
            }
        }

        if(s[sq]->cr < s[sq+1]->cr){
            for(int i = s[sq]->cr; i <= s[sq+1]->cr;i++){
                floor[i][s[sq]->cc] = ' ';
            }
        } else {
            for(int i = s[sq+1]->cc; i <= s[sq]->cr;i++){
                floor[i][s[sq]->cc] = ' ';
            }
        }
    }

    for(int sq =numRooms-1;sq>0;sq--){ // Adds Paths between rooms
        if(s[sq]->cr < s[sq-1]->cr){
            for(int i = s[sq]->cr; i <= s[sq-1]->cr;i++){
                floor[i][s[sq]->cc] = ' ';
            }
        } else {
            for(int i = s[sq-1]->cr; i <= s[sq]->cr;i++){
                floor[i][s[sq]->cc] = ' ';
            }
        }

        if(s[sq]->cc < s[sq-1]->cc){
            for(int i = s[sq]->cc; i <= s[sq-1]->cc;i++){
                floor[s[sq]->cr][i] = ' ';
            }
        } else {
            for(int i = s[sq-1]->cc; i <= s[sq]->cc;i++){
                floor[s[sq]->cr][i] = ' ';
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

    for(int i =0;i <s.size();i++){
        delete s[i];
    }
}

// M = randInt(2, 5*(L+1)+1)
void Temple::populateFloor() {
    p->move(randomPlacement());
    floor[p->getCoords().r()][p->getCoords().c()] = p->symbol();

    for(int i =0;i<loot.size();i++){
        delete loot[i];
    }
    for(int i =0; i< enemies.size();i++){
        delete enemies[i];
    }

    loot.clear();
    enemies.clear();

    int M = randInt(2, 5*(level+1)+1); // Determines the numer of monster than creates them
    for(int i=0; i < M; i++){
        Actors* a = randomEnemy();
        enemies.push_back(a);
        floor[a->getCoords().r()][a->getCoords().c()] = a->symbol();
    }

    int O = randInt(2,3);

    for(int i=0; i < O; i++){ // Determines the number of scrolls and weapons and places them
        Objects* o =randomObject();
        o->place(randomPlacement());
        loot.push_back(o);
        floor[o->getCoords().r()][o->getCoords().c()] = o->symbol();
    }

    if(level==4){ // If level is 4 than place the idol if not place stairway
        Objects* o = new Idol;
        o->place(randomPlacement());
        loot.push_back(o);
        floor[o->getCoords().r()][o->getCoords().c()] = o->symbol();
        cout << "FINAL LEVEL" << endl;
    } else {
        Objects* o = new Stairway;
        o->place(randomPlacement());
        loot.push_back(o);
        floor[o->getCoords().r()][o->getCoords().c()] = o->symbol();
    }
}

void Temple::printFloor() { // prints out the floor and determines layers like monster go on top of loot
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

Objects *Temple::pickUpObject(Coord c) { // gets object based on coords
    for(int i = 0;i < loot.size();i++){
        if(loot[i]->getCoords().r() == c.r() && loot[i]->getCoords().c() == c.c()){
            Objects* o = loot[i];
            loot.erase(loot.begin()+i);
            return o;
        }
    }
    return nullptr;
}

Actors *Temple::getEnemyLocation(Coord c) const{ // gets enemy based on coords
    for(int i = 0;i < enemies.size();i++){
        if(enemies[i]->getCoords().r() == c.r() && enemies[i]->getCoords().c() == c.c()){
            return enemies[i];
        }
    }
    return nullptr;
}

Objects *Temple::getObjectLocation(Coord c) const{ // gets enemy based on coords
    for(int i = 0;i < loot.size();i++){
        if(loot[i]->getCoords().r() == c.r() && loot[i]->getCoords().c() == c.c()){
            return loot[i];
        }
    }
    return nullptr;
}

//attackerPoints = attackerDexterity + weaponDexterityBonus;
//defenderPoints = defenderDexterity + defenderArmorPoints;
//if (randInt(1, attackerPoints) >= randInt(1, defenderPoints))
//attacker has hit defender
//damagePoints = randInt(0, attackerStrength + weaponDamageAmount - 1);
void Temple::attack(Actors *attacker, Actors *defender) { // Calculates whether an enemy attacks and their damage
    int attackerPoints = attacker->getDex() + attacker->getWeapon()->getDexBonus();
    int defenderPoints = defender->getDex() + defender->getArm();
    if(randInt(1,attackerPoints) >= randInt(1, defenderPoints)){
        int damagePoints = randInt(0, attacker->getStr() + attacker->getWeapon()->getDmgBonus() -1);
        defender->decHp(damagePoints);
        cout << attacker->name() << " " << attacker->getWeapon()->getAttackString() << " " << defender->name() << " and Hits!" << endl;
        if(attacker->getWeapon()->getName() == "Magic Fang of Sleep"){ // Determines if the defender is put to sleep by magic fang
            if(randInt(1,5)==5){
                defender->setSleep(randInt(2,6));
            }
        }
    } else {
        cout << attacker->name() << " " << attacker->getWeapon()->getAttackString() << " " << defender->name() << " but misses!" << endl;
    }
}

bool Temple::playerTurn(char t) { // Covers players variety of moves
    if(randInt(1,10) == 10){  // determines if player will gain health this turn
        p->incHp();
    }

    if(p->getSleep() > 0) { // if player is asleep skips their turn
        cout << "Player is Asleep" << endl;
        p->decSleep();
        return false;
    }

    if(t == 'g'){ // allows player to pick up items or wins if idol is picked up
        Objects* item = Temple::pickUpObject(p->getCoords());
        if(item == nullptr) {
            return false;
        }
        if(item->getName()=="Idol"){
            delete item;
            return true;
        }
        if(item->getName()!="Stairway") {
            cout << "Player picked up " << item->getName() << endl;
            p->pickedUp(item);
        }
    }

    if(t == 'i'){ // displays inventory
        p->printInv();
        char temp;
        cin >> temp;
    }

    if(t == 'w'){ // allows user to switch weapons
        p->printInv();
        char i;
        cin >> i;
        cout << endl;
        i-=97;
        int j = int(i);
        p->changeWp(j);
    }

    if(t == 'r'){ // Allows player to  read a scroll
        p->printInv();
        char i = getCharacter();
        cout << endl;
        i-=97;
        int j = int(i);
        p->readScroll(j, randomPlacement());
    }

    if(t == '>'){ // Allows player to move to the next floor
        Objects* item = Temple::pickUpObject(p->getCoords());
        if(item->getName()=="Stairway") {
            delete item;
            return true;
        }
    }

    // Allows player to move in certain  directions
    if(t == 'h'){ // move/attack left
        Coord c(p->getCoords().r(),p->getCoords().c()-1); // next coords
        Actors* enem = Temple::getEnemyLocation(c); // gets whats at coords
        if(enem != nullptr){ // if its an enemy fight
            attack(p,enem);
        }else { // if not see if you can move to that space
            cout << endl;
            char m = floor[p->getCoords().r()][p->getCoords().c()-1];

            if(m == ' ' || m == ')' || m == '&' || m == '>' || m == '?'){
                floor[p->getCoords().r()][p->getCoords().c()] = ' ';
                p->move(Coord(p->getCoords().r(),p->getCoords().c()-1));
                floor[p->getCoords().r()][p->getCoords().c()] = p->symbol();
            }
        }
    } // Repeat for other directions
    else if(t == 'l'){ // move/attack right
        Coord c(p->getCoords().r(),p->getCoords().c()+1);
        Actors* enem = Temple::getEnemyLocation(c);
        if(enem != nullptr){
            attack(p,enem);
        } else {
            cout << endl;
            char m = floor[p->getCoords().r()][p->getCoords().c()+1];
            if(m == ' ' || m == ')' || m == '&' || m == '>' || m == '?'){
                floor[p->getCoords().r()][p->getCoords().c()] = ' ';
                p->move(Coord(p->getCoords().r(),p->getCoords().c()+1));
                floor[p->getCoords().r()][p->getCoords().c()] = p->symbol();
            }
        }
    }
    else if(t == 'k'){ // move/attack upward
        Coord c(p->getCoords().r()-1,p->getCoords().c());
        Actors* enem = Temple::getEnemyLocation(c);
        if(enem != nullptr){
            attack(p,enem);
        } else {
            cout << endl;
            char m = floor[p->getCoords().r()-1][p->getCoords().c()];
            if(m == ' ' || m == ')' || m == '&' || m == '>' || m == '?'){
                floor[p->getCoords().r()][p->getCoords().c()] = ' ';
                p->move(Coord(p->getCoords().r()-1,p->getCoords().c()));
                floor[p->getCoords().r()][p->getCoords().c()] = p->symbol();
            }
        }
    }
    else if(t == 'j'){ // move/attack downward
        Coord c(p->getCoords().r()+1,p->getCoords().c());
        Actors* enem = Temple::getEnemyLocation(c);
        if(enem != nullptr){
            attack(p,enem);
        } else {
            cout << endl;
            char m = floor[p->getCoords().r()+1][p->getCoords().c()];
            if(m == ' ' || m == ')' || m == '&' || m == '>' || m == '?'){
                floor[p->getCoords().r()][p->getCoords().c()] = ' ';
                p->move(Coord(p->getCoords().r()+1,p->getCoords().c()));
                floor[p->getCoords().r()][p->getCoords().c()] = p->symbol();
            }
        }
    }

    if(t == 'c'){ // Increase stats the cheat mode
        cout << "Cheats Enabled" << endl;
        p->incDex(50);
        p->incStr(50);
        p->incArm(50);
        p->incMaxHp(50);
        p->incHp(50);
    }
    return false;
}

void Temple::enemyTurn() { // What enemies do during their turn
    for(int i = 0;i < enemies.size(); i++){
        if(enemies[i]->getHp() == 0){ // Describes what happens when enemies die like what they drop
            Objects* o1 = getObjectLocation(Coord(enemies[i]->getCoords().r(), enemies[i]->getCoords().c()));
            if(o1 == nullptr){
                Objects* o = enemies[i]->drops();
                if(o != nullptr){
                    o->place(Coord(enemies[i]->getCoords().r(), enemies[i]->getCoords().c()));
                    loot.push_back(o);
                    floor[enemies[i]->getCoords().r()][enemies[i]->getCoords().c()] = o->symbol();
                } else {
                    floor[enemies[i]->getCoords().r()][enemies[i]->getCoords().c()] = ' ';
                }
            } else {
                floor[enemies[i]->getCoords().r()][enemies[i]->getCoords().c()] = o1->symbol();
            }
            cout << enemies[i]->name() << " was Slain" << endl;
            delete enemies[i];
            enemies.erase(enemies.begin()+i);
            i--;
        } else { // Describes how enemies will move or if they attack the player
            if(enemies[i]->getSleep()>0){
                enemies[i]->decSleep();
                continue;
            }
            Coord c = enemies[i]->turn(floor, p);
            if(floor[c.r()][c.c()] == ' ' || floor[c.r()][c.c()] == ')' || floor[c.r()][c.c()] == '&' || floor[c.r()][c.c()] == '>' || floor[c.r()][c.c()] == '?'){
                floor[enemies[i]->getCoords().r()][enemies[i]->getCoords().c()] = ' ';
                enemies[i]->move(Coord(c));
                floor[enemies[i]->getCoords().r()][enemies[i]->getCoords().c()] = enemies[i]->symbol();
            } else if(floor[c.r()][c.c()] == p->symbol()){
                attack(enemies[i],p);
            }
        }
    }
}

