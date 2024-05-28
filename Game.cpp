// Game.cpp

#include "Game.h"
#include "utilities.h"
#include <iostream>
using namespace std;

// Implement these and other Game member functions you may have added.

Game::Game(int goblinSmellDistance)
{}

void Game::play()
{
    Temple t;
    t.buildFloor();
    t.populateFloor();

    bool running = true;

    while(running){
        t.printFloor();

        std::cin >> std::ws;
        char action = getCharacter();
        cout << endl;

        if(action == 'q'){
            running = false;
            break;
        }

        t.playerTurn(action);

        clearScreen();
    }
}

// You will presumably add to this project other .h/.cpp files for the various
// classes of objects you need to play the game:  player, monsters, weapons, 
// etc.  You might have a separate .h/.cpp pair for each class (e.g., Player.h,
// Bogeyman.h, etc.), or you might put the class declarations for all actors in
// Actor.h, all game objects in GameObject.h, etc.
