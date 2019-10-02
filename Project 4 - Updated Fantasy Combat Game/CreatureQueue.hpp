/*********************************************************************
 ** Program name: Team Fight Simulation
 ** Author: John Olgin
 ** Date: 5/28/17
 ** Description: This program will be a battle simulation between two teams of creatures. The players will be able to choose from 5 characters to fill their team. The characters will battle until one team is out of players and then a score will be tallied to decide who the winner is. The losing character in each battle will be removed from the team, and the winner will go to the back of the queue of the player's team. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, inputValidation.cpp, CreatureQueue.cpp, CreatureQueue.hpp, Tournament.hpp, Tournament.cpp, LoserNode.cpp, LoserNode.hpp, LoserQueue.hpp, and LoserQueue.cpp.
 *********************************************************************/

#ifndef CreatureQueue_hpp
#define CreatureQueue_hpp

#include <stdio.h>
#include "Creature.hpp"
#include <string>

/*
 Description: This class is an abstraction that represents the team's queue of creature characters. It will also hold the functions that will manipulate the linked list as well. The class will allow the user to remove the head, add to the back, move the head to the end, add to the front, and print the linked list. This should be used to hold both players' team lineups and the loser pile.
 */
class CreatureQueue
{
protected:
    Creature *head;
    Creature *tail;
    
public:
    CreatureQueue();
    ~CreatureQueue();
    void addBack(Creature *creature, string alias);
    void removeFront();
    void moveToBack();
    void print();
    void addFront(Creature *creature);
    bool isEmpty();
    Creature* returnHead();
};

#endif /* CreatureQueue_hpp */
