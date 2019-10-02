/*********************************************************************
 ** Program name: Team Fight Simulation
 ** Author: John Olgin
 ** Date: 5/28/17
 ** Description: This program will be a battle simulation between two teams of creatures. The players will be able to choose from 5 characters to fill their team. The characters will battle until one team is out of players and then a score will be tallied to decide who the winner is. The losing character in each battle will be removed from the team, and the winner will go to the back of the queue of the player's team. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, inputValidation.cpp, CreatureQueue.cpp, CreatureQueue.hpp, Tournament.hpp, Tournament.cpp, LoserNode.cpp, LoserNode.hpp, LoserQueue.hpp, and LoserQueue.cpp.
 *********************************************************************/

#ifndef Tournament_hpp
#define Tournament_hpp

#include <stdio.h>
#include "CreatureQueue.hpp"
#include "LoserQueue.hpp"


/*
 Description: This class is an abstraction that represents the actual gameplay of the program. It will hold the players' teams, create the teams, and update the lists depending on the outcome of the battle. This class will run every aspect of the game, including scoring and deciding who wins the game.
 */
class Tournament
{
private:
    CreatureQueue player1List;
    CreatureQueue player2List;
    LoserQueue loserList;
    int p1WinCount = 0;
    int p2WinCount = 0;
    
public:
    Tournament();
    ~Tournament();
    void fillP1List(Creature *newCreature, string nickName);
    void fillP2List(Creature *newCreature, string nickName);
    void updateLoserList(Creature *newCreature);
    void updateScore(int winner, Creature *p1, Creature *p2);
    void printLoserList();
    void whoWon();
    bool anyEmptyTeams();
    int fight();
    Creature* returnP1Head();
    Creature* returnP2Head();
};
#endif /* Tournament_hpp */
