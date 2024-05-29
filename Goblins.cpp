//
// Created by tea on 5/16/24.
//

#include "Goblins.h"
#include <cmath>
using namespace std;

Goblins::Goblins(Coord c, int smell)
: Actors(c, randInt(15,20), 1, 3, 1, 20, new ShortSwords), smell(smell)
{}

Objects *Goblins::drop() { // Determines the goblins drops
    if(randInt(1,3)==3){
        if(randInt(1,2)==2){
            return new MagicFang;
        }else{
            return new MagicAxes;
        }
    }
    return nullptr;
}

Coord Goblins::turn(const char (*floor)[70], Actors *a) {
    int dist = abs(this->getCoords().r() - a->getCoords().r()) + abs(this->getCoords().c() - a->getCoords().c());
    if(dist > smell){
        return this->getCoords();
    }

    vector<Coord> shortestPath;
    shortestPath.clear();
    vector<Coord> curPath;
    curPath.clear();
    char maze[18][70];
    for(int i = 0; i<18; i++){ // Sets maze equal to floor
        for(int j=0;j<70;j++){
            maze[i][j] = floor[i][j];
        }
    }
    Goblins::findPath(maze, shortestPath,curPath, this->getCoords(), a->getCoords(), dist);


    if(shortestPath.size() <= smell && !shortestPath.empty()){
        return shortestPath[1];
    } else {
        return this->getCoords();
    }
}

void Goblins::findPath(char maze[18][70], vector<Coord>& shortestPath, vector<Coord>& curPath, Coord start, Coord end, int optimalDistance) {

    if(curPath.size() > smell){
        return;
    }

    if((abs(start.r()-end.r()) + abs(start.c()-end.c())) > smell){
        return;
    }

    if(curPath.size() < shortestPath.size() && !shortestPath.empty()){
        return;
    }

    if(shortestPath.size() <= optimalDistance && !shortestPath.empty()){
        return;
    }

    // Base cases
    char c = maze[start.r()][start.c()];
    if (!((c == ' ' || c == ')' || c == '?' || c == '>' || c == '@' || c == '0' || c ==  'G') && c != '#' && c != 'B' && c != 'D' && c != 'S' )) {
        return;
    }
    if (maze[start.r()][start.c()] == '@') {
        curPath.emplace_back(start.r(),start.c());
        if (maze[start.r()][start.c()] == '@' && (shortestPath.empty() || curPath.size() < shortestPath.size())) {
            shortestPath = curPath;
        }
        curPath.pop_back();
        return;
    }


    // Mark Cell as Visited
    maze[start.r()][start.c()] = '0';
    curPath.emplace_back(start.r(),start.c());
    if(start.c() < end.c() && start.r() < end.c()) {
        // Go in each direction
        if (isValid(maze[start.r()][start.c() + 1])) { // East South
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() + 1), end,
                              optimalDistance); // East
        }
        if (isValid(maze[start.r() + 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() + 1, start.c()), end,
                              optimalDistance); // South
        }
        if (isValid(maze[start.r()][start.c() - 1])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() - 1), end,
                              optimalDistance); // West
        }
        if (isValid(maze[start.r() - 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() - 1, start.c()), end,
                              optimalDistance); // North
        }
    } else if(start.c() > end.c() && start.r() < end.r()){ // West South
        if (isValid(maze[start.r()][start.c() - 1])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() - 1), end,
                              optimalDistance); // West
        }
        if (isValid(maze[start.r() + 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() + 1, start.c()), end,
                              optimalDistance); // South
        }
        if (isValid(maze[start.r()][start.c() + 1])) { // East South
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() + 1), end,
                              optimalDistance); // East
        }
        if (isValid(maze[start.r() - 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() - 1, start.c()), end,
                              optimalDistance); // North
        }
    } else if(start.c() < end.c() && start.r() > end.r()){ // East North
        if (isValid(maze[start.r()][start.c() + 1])) { // East South
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() + 1), end,
                              optimalDistance); // East
        }
        if (isValid(maze[start.r() - 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() - 1, start.c()), end,
                              optimalDistance); // North
        }
        if (isValid(maze[start.r()][start.c() - 1])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() - 1), end,
                              optimalDistance); // West
        }
        if (isValid(maze[start.r() + 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() + 1, start.c()), end,
                              optimalDistance); // South
        }
    } else if(start.c() > end.c() && start.r() > end.r()){ // West North
        if (isValid(maze[start.r()][start.c() - 1])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() - 1), end,
                              optimalDistance); // West
        }
        if (isValid(maze[start.r() - 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() - 1, start.c()), end,
                              optimalDistance); // North
        }
        if (isValid(maze[start.r()][start.c() + 1])) { // East South
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() + 1), end,
                              optimalDistance); // East
        }
        if (isValid(maze[start.r() + 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() + 1, start.c()), end,
                              optimalDistance); // South
        }
    } else if(start.c() == end.c() && start.r() > end.r()){ // North
        if (isValid(maze[start.r() - 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() - 1, start.c()), end,
                              optimalDistance); // North
        }
        if (isValid(maze[start.r()][start.c() + 1])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() + 1), end,
                              optimalDistance); // East
        }
        if (isValid(maze[start.r()][start.c() - 1])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() - 1), end,
                              optimalDistance); // West
        }
        if (isValid(maze[start.r() + 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() + 1, start.c()), end,
                              optimalDistance); // South
        }
    } else if(start.c() == end.c() && start.r() < end.r()){ // South
        if (isValid(maze[start.r() + 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() + 1, start.c()), end,
                              optimalDistance); // South
        }
        if (isValid(maze[start.r()][start.c() + 1])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() + 1), end,
                              optimalDistance); // East
        }
        if (isValid(maze[start.r()][start.c() - 1])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() - 1), end,
                              optimalDistance); // West
        }
        if (isValid(maze[start.r() - 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() - 1, start.c()), end,
                              optimalDistance); // North
        }
    } else if(start.c() > end.c() && end.r() == start.r()){ // West
        if (isValid(maze[start.r()][start.c() - 1])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() - 1), end,
                              optimalDistance); // West
        }
        if (isValid(maze[start.r() - 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() - 1, start.c()), end,
                              optimalDistance); // North
        }
        if (isValid(maze[start.r() + 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() + 1, start.c()), end,
                              optimalDistance); // South
        }
        if (isValid(maze[start.r()][start.c() + 1])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() + 1), end,
                              optimalDistance); // East
        }
    } else if( start.c() < end.c() && end.r() == start.r()){ // East
        if (isValid(maze[start.r()][start.c() + 1])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() + 1), end,
                              optimalDistance); // East
        }
        if (isValid(maze[start.r() - 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() - 1, start.c()), end,
                              optimalDistance); // North
        }
        if (isValid(maze[start.r() + 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() + 1, start.c()), end,
                              optimalDistance); // South
        }
        if (isValid(maze[start.r()][start.c() - 1])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() - 1), end,
                              optimalDistance); // West
        }
    } else { // Default argument
        if (isValid(maze[start.r()][start.c() + 1])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() + 1), end,
                              optimalDistance); // East
        }
        if (isValid(maze[start.r() - 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() - 1, start.c()), end,
                              optimalDistance); // North
        }
        if (isValid(maze[start.r() + 1][start.c()])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r() + 1, start.c()), end,
                              optimalDistance); // South
        }
        if (isValid(maze[start.r()][start.c() - 1])) {
            Goblins::findPath(maze, shortestPath, curPath, Coord(start.r(), start.c() - 1), end,
                              optimalDistance); // West
        }
    }

    // Remove when Dead End
    maze[start.r()][start.c()] = ' ';
    curPath.pop_back();
}

bool Goblins::isValid(char c) const{
    if((c == ' ' || c == ')' || c == '?' || c == '>' || c == '@' || c == '0') && c != '#' && c != 'B' && c != 'D' && c != 'S' && c != 'G'){
        return true;
    }
    return false;
}

//Coord Goblins::turn(const char floor[18][70], Actors* a) { // Complex Goblin move function explained further in report.txt
//    char maze[18][70];
//
//    for(int i = 0; i<18; i++){ // Sets maze equal to floor
//        for(int j=0;j<70;j++){
//            maze[i][j] = floor[i][j];
//        }
//    }
//
//    findPath(maze, this->getCoords().r(),this->getCoords().c(),a->getCoords().r(),a->getCoords().c(), 0); // Builds a distance map for each of the four directions than
//    // chooses the one where the destination is the shorted distance from that point
//
//    for(int i = 0; i<18; i++){ // Sets maze equal to floor
//        for(int j=0;j<70;j++){
//            maze[i][j] = floor[i][j];
//        }
//    }
//    findPath(maze, this->getCoords().r(),this->getCoords().c()+1,a->getCoords().r(),a->getCoords().c(), 0);
//    int east = maze[a->getCoords().r()][a->getCoords().c()]-42;
//
//
//    for(int i = 0; i<18; i++){ // Sets maze equal to floor
//        for(int j=0;j<70;j++){
//            maze[i][j] = floor[i][j];
//        }
//    }
//    findPath(maze, this->getCoords().r()+1,this->getCoords().c(),a->getCoords().r(),a->getCoords().c(), 0);
//    int south = maze[a->getCoords().r()][a->getCoords().c()]-42;
//
//    for(int i = 0; i<18; i++){ // Sets maze equal to floor
//        for(int j=0;j<70;j++){
//            maze[i][j] = floor[i][j];
//        }
//    }
//    findPath(maze, this->getCoords().r(),this->getCoords().c()-1,a->getCoords().r(),a->getCoords().c(), 0);
//    int west = maze[a->getCoords().r()][a->getCoords().c()]-42;
//
//    for(int i = 0; i<18; i++){ // Sets maze equal to floor
//        for(int j=0;j<70;j++){
//            maze[i][j] = floor[i][j];
//        }
//    }
//    findPath(maze, this->getCoords().r()-1,this->getCoords().c(),a->getCoords().r(),a->getCoords().c(), 0);
//    int north = maze[a->getCoords().r()][a->getCoords().c()]-42;
//
//
//    if(east <= south && east <= west && east <= north && east <= 15){
//        return Coord(this->getCoords().r(),this->getCoords().c()+1);
//    }
//    if(south <= east && south <= west && south <= north && south <= 15){
//        return Coord(this->getCoords().r()+1,this->getCoords().c());
//    }
//    if(west <= east && west <= south && west <= north && west <= 15){
//        return Coord(this->getCoords().r(),this->getCoords().c()-1);
//    }
//    if(north <= east && north <= west && north <= south && north <= 15){
//        return Coord(this->getCoords().r()-1,this->getCoords().c());
//    }
//
//    //findPath(maze, this->getCoords().r(),this->getCoords().c(),a->getCoords().r(),a->getCoords().c(), 0, dist);
//    return Coord(this->getCoords().r(),this->getCoords().c());
//}

//bool Goblins::findPath(char maze[18][70], int sr, int sc, int er, int ec, int n) // Recursively creates the distance map described more in the report
//{
//    if((maze[sr][sc] == ' ' || maze[sr][sc] == ')' || maze[sr][sc] == '?' || maze[sr][sc] == '>' || maze[sr][sc] == '@' || maze[sr][sc] == 'G') && maze[sr][sc] != '#' && maze[sr][sc] != 'B' && maze[sr][sc] != 'D' && maze[sr][sc] != 'S' && maze[sr][sc] != 'G'){
//        maze[sr][sc] = n+42;
//    } else {
//        return false;
//    }
//
//    if(n>18)
//        return false;
//
//
//
//    if((maze[sr][sc+1] == ' ' || maze[sr][sc+1] == ')' || maze[sr][sc+1] == '?' || maze[sr][sc+1] == '>' || maze[sr][sc+1] == '@' || maze[sr][sc+1] == 'G' || maze[sr][sc+1]>maze[sr][sc]) && maze[sr][sc+1] != '#' && maze[sr][sc+1] != 'B' && maze[sr][sc+1] != 'D' && maze[sr][sc+1] != 'S' && maze[sr][sc+1] != 'G'){ // East
//        Goblins::findPath(maze, sr,sc+1,er,ec,n+1);
//    }
//    if((maze[sr+1][sc] == ' ' || maze[sr+1][sc] == ')' || maze[sr+1][sc] == '?' || maze[sr+1][sc] == '>' || maze[sr+1][sc] == '@' || maze[sr+1][sc] == 'G' || maze[sr+1][sc]>maze[sr][sc]) && maze[sr+1][sc] != '#' && maze[sr+1][sc] != 'B' && maze[sr+1][sc] != 'D' && maze[sr+1][sc] != 'S' && maze[sr+1][sc] != 'G'){ // South
//        Goblins::findPath(maze,sr+1,sc,er,ec,n+1);
//    }
//    if((maze[sr][sc-1] == ' ' || maze[sr][sc-1] == ')' || maze[sr][sc-1] == '?' || maze[sr][sc-1] == '>' || maze[sr][sc-1] == '@' || maze[sr][sc-1] == 'G' || maze[sr][sc-1]>maze[sr][sc]) && maze[sr][sc-1] != '#' && maze[sr][sc-1] != 'B' && maze[sr][sc-1] != 'D' && maze[sr][sc-1] != 'S' && maze[sr][sc-1] != 'G'){ // West
//        Goblins::findPath(maze,sr,sc-1,er,ec,n+1);
//    }
//    if((maze[sr-1][sc] == ' ' || maze[sr-1][sc] == ')' || maze[sr-1][sc] == '?' || maze[sr-1][sc] == '>' || maze[sr-1][sc] == '@' || maze[sr-1][sc] == 'G' || maze[sr-1][sc]>maze[sr][sc]) && maze[sr-1][sc] != '#' && maze[sr-1][sc] != 'B' && maze[sr-1][sc] != 'D' && maze[sr-1][sc] != 'S' && maze[sr-1][sc] != 'G'){ // North
//        Goblins::findPath(maze,sr-1,sc,er,ec,n+1);
//    }
//
//    return false;
//}