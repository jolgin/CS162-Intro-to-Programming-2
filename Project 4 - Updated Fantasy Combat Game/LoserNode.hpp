/*********************************************************************
 ** Program name: Team Fight Simulation
 ** Author: John Olgin
 ** Date: 5/28/17
 ** Description: This program will be a battle simulation between two teams of creatures. The players will be able to choose from 5 characters to fill their team. The characters will battle until one team is out of players and then a score will be tallied to decide who the winner is. The losing character in each battle will be removed from the team, and the winner will go to the back of the queue of the player's team. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, inputValidation.cpp, CreatureQueue.cpp, CreatureQueue.hpp, Tournament.hpp, Tournament.cpp, LoserNode.cpp, LoserNode.hpp, LoserQueue.hpp, and LoserQueue.cpp.
 *********************************************************************/

#ifndef LoserNode_hpp
#define LoserNode_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

/*
 Description: This struct represents a node that holds a string inside of a queue. It will connect to another node of the same type to create a linked list. It will represent a losing creature from the tournament rounds. This struct is meant to be held within the LoserQueue class. 
 */
struct LoserNode
{
protected:
    string name;
    LoserNode *next;
    
public:
    friend class Tournament;
    friend class LoserQueue;
    
};
#endif /* LoserNode_hpp */
