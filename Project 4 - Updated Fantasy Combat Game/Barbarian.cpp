/*********************************************************************
 ** Program name: Team Fight Simulation
 ** Author: John Olgin
 ** Date: 5/28/17
 ** Description: This program will be a battle simulation between two teams of creatures. The players will be able to choose from 5 characters to fill their team. The characters will battle until one team is out of players and then a score will be tallied to decide who the winner is. The losing character in each battle will be removed from the team, and the winner will go to the back of the queue of the player's team. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, inputValidation.cpp, CreatureQueue.cpp, CreatureQueue.hpp, Tournament.hpp, Tournament.cpp, LoserNode.cpp, LoserNode.hpp, LoserQueue.hpp, and LoserQueue.cpp.
 *********************************************************************/

#include "Barbarian.hpp"
#include "Creature.hpp"
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

/*
 Description: This is the default constructor that will define the name and amount of strength and armor points the character has initially.
 */
Barbarian::Barbarian():Creature()
{
    name = "Barbarian";
    strengthPoints = 12;
    armorPoints = 0;
}




/*
 Description: This is the attacking dice roll function. It will generate two random numbers that represent the character's dice rolls. It will also output the value of the dice rolls. It won't take any arguments, but it will return an integer representing the sum of all the dice (the total attack).
 */
int Barbarian::attackRoll()
{
    int attackRoll1, attackRoll2, totalAttack;
    
    attackRoll1 = rand() % 6 + 1;
    attackRoll2 = rand() % 6 + 1;
    totalAttack = attackRoll1 + attackRoll2;
    
    cout << "Attack: dice roll one is " << attackRoll1 << " and two is " << attackRoll2 << "." << endl;
    
    
    return totalAttack;
}




/*
 Description: This is the defensive dice roll function. It will generate two random numbers that represent the character's dice rolls. It will also output the value of the dice rolls. It won't take any arguments, but it will return an integer representing the sum of all the dice (the total defense).
 */
int Barbarian::defenseRoll()
{
    int defenseRoll1, defenseRoll2, totalDefense;
    
    defenseRoll1 = rand() % 6 + 1;
    defenseRoll2 = rand() % 6 + 1;
    totalDefense = defenseRoll1 + defenseRoll2;
    
    cout << "Defense: dice roll one is " << defenseRoll1 << "and two is " << defenseRoll2 << "." << endl;
    
    
    return totalDefense;
}



/*
 Description: This function will not do anything. It is solely included to allow Harry Potter's special ability function to work properly.
 */
void Barbarian::specialAbility(int deathCount)
{
    
}
