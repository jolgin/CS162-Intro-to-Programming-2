/*********************************************************************
 ** Program name: Team Fight Simulation
 ** Author: John Olgin
 ** Date: 5/28/17
 ** Description: This program will be a battle simulation between two teams of creatures. The players will be able to choose from 5 characters to fill their team. The characters will battle until one team is out of players and then a score will be tallied to decide who the winner is. The losing character in each battle will be removed from the team, and the winner will go to the back of the queue of the player's team. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, inputValidation.cpp, CreatureQueue.cpp, CreatureQueue.hpp, Tournament.hpp, Tournament.cpp, LoserNode.cpp, LoserNode.hpp, LoserQueue.hpp, and LoserQueue.cpp.
 *********************************************************************/

#ifndef LoserQueue_hpp
#define LoserQueue_hpp

#include <stdio.h>
#include <iostream>
#include "LoserNode.hpp"
using namespace std;

/*
 Description: This class represents an abstraction that will hold the list of Loser Nodes and allow the user to manipulate the list by different tasks. This class will hold the stack of creatures that lose in their respective round in the tournament. This class will be within the tournament class. 
 */
class LoserQueue
{
private:
    LoserNode *head;
    LoserNode *tail;
    
public:
    LoserQueue();
    ~LoserQueue();
    void addFront(LoserNode *node, string name);
    void print();
};
#endif /* LoserQueue_hpp */
