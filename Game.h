// Game.h

#ifndef GAME_INCLUDED
#define GAME_INCLUDED

// You may add data members and other member functions to this class.
#include "Player.h"
#include "Bogeymen.h"
#include "Snakewomen.h"
#include "Dragons.h"
#include "Goblins.h"
#include "Maces.h"
#include "ShortSwords.h"
#include "LongSwords.h"
#include "MagicAxes.h"
#include "MagicFang.h"
#include "Temple.h"

class Game
{
public:
    Game(int goblinSmellDistance);
    void play();
private:
    int smell;
};

#endif // GAME_INCLUDED
