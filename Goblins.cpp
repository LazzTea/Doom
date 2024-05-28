//
// Created by tea on 5/16/24.
//

#include "Goblins.h"

Goblins::Goblins(Coord c)
: Actors(c, randInt(15,20), 1, 3, 1, 20, new ShortSwords)
{}

Objects *Goblins::drop() {
    if(randInt(1,3)==3){
        if(randInt(1,2)==2){
            return new MagicFang;
        }else{
            return new MagicAxes;
        }
    }
    return nullptr;
}

Coord Goblins::turn(const char floor[18][70], Actors* a) {
    char maze[18][70];

    for(int i = 0; i<18; i++){ // Sets maze equal to floor
        for(int j=0;j<70;j++){
            maze[i][j] = floor[i][j];
        }
    }

    int east = 0;
    findPath(maze, this->getCoords().r(),this->getCoords().c()+1,a->getCoords().r(),a->getCoords().c(), 0, east);
    int south = 0;
    findPath(maze, this->getCoords().r()+1,this->getCoords().c(),a->getCoords().r(),a->getCoords().c(), 0, south);
    int west = 0;
    findPath(maze, this->getCoords().r(),this->getCoords().c()-1,a->getCoords().r(),a->getCoords().c(), 0, west);
    int north = 0;
    findPath(maze, this->getCoords().r()-1,this->getCoords().c(),a->getCoords().r(),a->getCoords().c(), 0, north);

    if(east < south && east < west && east < north && east <= 15){
        return Coord(this->getCoords().r(),this->getCoords().c()+1);
    }
    if(south < east && south < west && south < north && south <= 15){
        return Coord(this->getCoords().r()+1,this->getCoords().c());
    }
    if(west < east && west < south && west < north && west <= 15){
        return Coord(this->getCoords().r(),this->getCoords().c()-1);
    }
    if(north < east && north < west && north < south && north <= 15){
        return Coord(this->getCoords().r()+1,this->getCoords().c());
    }

    //findPath(maze, this->getCoords().r(),this->getCoords().c(),a->getCoords().r(),a->getCoords().c(), 0, dist);
    return Coord(this->getCoords().r(),this->getCoords().c());
}

bool Goblins::findPath(char maze[18][70], int sr, int sc, int er, int ec, int n, int& dist)
{
    if(maze[sr][sc] == '#' || maze[sr][sc] == '0'  || maze[sr][sc] == 'B' || maze[sr][sc] == 'S' || maze[sr][sc] == 'D' || maze[sr][sc] == 'G') {
        dist = 50000000;
        return false;
    }

    maze[sr][sc] = '0';

    if(sr == er && sc == ec) {
        dist = n;
        return true;
    }

    if(maze[sr][sc+1] != '#' && maze[sr][sc+1] != '0' && maze[sr][sc+1] != 'B' && maze[sr][sc+1] != 'S' && maze[sr][sc+1] != 'D' && maze[sr][sc+1] != 'G'){ // East
        if(Goblins::findPath(maze, sr,sc+1,er,ec,n+1, dist))
            return true;
    }
    if(maze[sr+1][sc] != '#' && maze[sr+1][sc] != '0' && maze[sr+1][sc] != 'B' && maze[sr+1][sc] != 'S' && maze[sr+1][sc] != 'D' && maze[sr+1][sc] != 'G'){ // South
        if(Goblins::findPath(maze,sr+1,sc,er,ec,n+1, dist))
            return true;
    }
    if(maze[sr][sc-1] != '#' && maze[sr][sc-1] != '0' && maze[sr][sc-1] != 'B' && maze[sr][sc-1] != 'S' && maze[sr][sc-1] != 'D' && maze[sr][sc-1] != 'G'){ // West
        if(Goblins::findPath(maze,sr,sc-1,er,ec,n+1, dist))
            return true;
    }
    if(maze[sr-1][sc] != '#' && maze[sr-1][sc] != '0' && maze[sr-1][sc] != 'B' && maze[sr-1][sc] != 'S' && maze[sr-1][sc] != 'D' && maze[sr-1][sc] != 'G'){ // North
        if(Goblins::findPath(maze,sr-1,sc,er,ec,n+1, dist))
            return true;
    }

    dist = 50000000;
    return false;
}