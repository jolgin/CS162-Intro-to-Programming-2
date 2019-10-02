/*********************************************************************
 ** Program name: Team Fight Simulation
 ** Author: John Olgin
 ** Date: 5/28/17
 ** Description: This program will be a battle simulation between two teams of creatures. The players will be able to choose from 5 characters to fill their team. The characters will battle until one team is out of players and then a score will be tallied to decide who the winner is. The losing character in each battle will be removed from the team, and the winner will go to the back of the queue of the player's team. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, inputValidation.cpp, CreatureQueue.cpp, CreatureQueue.hpp, Tournament.hpp, and Tournament.cpp.
 *********************************************************************/


#ifndef BlueMen_hpp
#define BlueMen_hpp

#include <stdio.h>
#include "Creature.hpp"


/*
 Description: This class is an abstraction that represents the Blue Men Creature. It will be a subclass of the base Creature class. It will inherit all member data and member functions from the Creature class. The only independent functionality this class will have is a default constructor, an attack function, a defense function, and a special ability function all specific to the Blue Men class. These functions will override the parent functions in the Creature class. Objects of this class are to be used when a player elects to use the Blue Men creature in the simulated fight game.
 */
class BlueMen: public Creature
{
protected:
    
    
public:
    BlueMen();
    BlueMen(string nName);
    virtual int attackRoll();
    virtual int defenseRoll();
    void specialAbility(int deathCount);
};



#endif /* BlueMen_hpp */
