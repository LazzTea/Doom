// Game.cpp

#include "Game.h"
#include "utilities.h"
#include <iostream>
using namespace std;

// Implement these and other Game member functions you may have added.

Game::Game(int goblinSmellDistance) : smell(goblinSmellDistance)
{}

void Game::play()
{
    Temple t(smell); // Creates and populates the floor
    t.buildFloor();
    t.populateFloor();
    clearScreen();
    cout << endl;
    t.printFloor();

    while(true){


        std::cin >> std::ws; // Gets the action the player will perform
        char action = getCharacter();
        cout << endl;
        clearScreen();

        if(action == 'q'){ // Quits game when selected
            break;
        }

        if(t.playerTurn(action)){ // Determines if a player action continues levels or wins game
            if(t.getLevel()==4){
                cout << "VICTORY!!! The Idol is now yours!" << endl;
                break;
            } else {
                t.incLevel();
                t.buildFloor();
                t.populateFloor();
                clearScreen();
                cout << "Player climbed to level " << t.getLevel() << endl;
                t.printFloor();
                continue;
            }
        }

        t.enemyTurn();

        if(t.getPlayer()->getHp()<=0){ // Checks if the player is alive
            cout << "YOU DIED!" << endl;
            break;
        }
        t.printFloor();
    }
}

// You will presumably add to this project other .h/.cpp files for the various
// classes of objects you need to play the game:  player, monsters, weapons, 
// etc.  You might have a separate .h/.cpp pair for each class (e.g., Player.h,
// Bogeyman.h, etc.), or you might put the class declarations for all actors in
// Actor.h, all game objects in GameObject.h, etc.
