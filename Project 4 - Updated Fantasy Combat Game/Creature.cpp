/*********************************************************************
 ** Program name: Team Fight Simulation
 ** Author: John Olgin
 ** Date: 5/28/17
 ** Description: This program will be a battle simulation between two teams of creatures. The players will be able to choose from 5 characters to fill their team. The characters will battle until one team is out of players and then a score will be tallied to decide who the winner is. The losing character in each battle will be removed from the team, and the winner will go to the back of the queue of the player's team. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, inputValidation.cpp, CreatureQueue.cpp, CreatureQueue.hpp, Tournament.hpp, Tournament.cpp, LoserNode.cpp, LoserNode.hpp, LoserQueue.hpp, and LoserQueue.cpp.
 *********************************************************************/

#include "Creature.hpp"
#include <cstdlib>

/*
 Description: This is the default constructor that will set the name of the creature and the amount of strength and armor points.
 */
Creature::Creature()
{
    name = "Empty";
    strengthPoints = 0;
    armorPoints = 0;
}


/*
 Description: This function is only meant to be overridden by the child classes of this parent class. This function will just return 0 if called from the Creature class.
 */
int Creature::attackRoll()
{
    return 0;
}



/*
 Description: This function is only meant to be overridden by the child classes of this parent class. This function will just return 0 if called from the Creature class.
 */
int Creature::defenseRoll()
{
    return 0;
}



/*
 Description: This function will simply return a string representing the name of the type of creature. This function is meant to be inherited by the sub classes. It will not take any arguments.
 */
string Creature::getName()
{
    return name;
}



/*
 Description: This function take an integer argument that represents the updated strength of the character. The function will set this equal to the character's data for strength points. It will not return anything. This is meant to be inherited by the subclasses.
 */
void Creature::setStrength(int strength)
{
    strengthPoints = strength;
}



/*
 Description: This function will return the amount of strength the character currently has as an integer. This is meant to be inherited by the subclasses. There will be no parameters taken.
 */
int Creature::getStrength()
{
    return strengthPoints;
}



/*
 Description: This function will take an integer argument that represents the updated armor of the character. The function will se this equal to the character's data for armor points. It will not return anything. This is meant to be inherited by the subclasses.
 */
void Creature::setArmor(int armor)
{
    armorPoints = armor;
}



/*
 Description: This function will reutrn the amount of armor the character currently has as an integer. This is meant to be ingerited by the subclasses. There will be no parameters taken.
 */
int Creature::getArmor()
{
    return armorPoints;
}



/*
 Description: This function is only meant to be overridden by the child classes of this parent class. This function will not return anything from the Creature class. It will take an integer argument representing the number of times the character has died. This must be determined before this function is called.
 */
void Creature::specialAbility(int deathCount)
{
    
}


/*
 Description: This function will allow the creature to recover some health if they win their battle. It won't return anything or take any arguments.
 */
void Creature::recoverStrength()
{
    int random;
    random = rand() % 8 + 1;
    
    strengthPoints = strengthPoints + random;
}
