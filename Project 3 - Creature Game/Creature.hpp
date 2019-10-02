/*********************************************************************
 ** Program name: Team Fight Simulation
 ** Author: John Olgin
 ** Date: 5/28/17
 ** Description: This program will be a battle simulation between two teams of creatures. The players will be able to choose from 5 characters to fill their team. The characters will battle until one team is out of players and then a score will be tallied to decide who the winner is. The losing character in each battle will be removed from the team, and the winner will go to the back of the queue of the player's team. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, inputValidation.cpp, CreatureQueue.cpp, CreatureQueue.hpp, Tournament.hpp, and Tournament.cpp.
 *********************************************************************/


#ifndef Creature_hpp
#define Creature_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Creature
{
protected:
    string name;
    string nickName;
    int strengthPoints;
    int armorPoints;
    Creature *next;
    

public:
    Creature();
    Creature(string nickName);
    virtual int attackRoll();
    virtual int defenseRoll();
    string getName();
    void setStrength(int strength);
    int getStrength();
    void setArmor(int armor);
    int getArmor();
    virtual void specialAbility(int deathCount);
    void recoverStrength();
    friend class CreatureQueue;
    friend class Tournament;
};


#endif /* Creature_hpp */
