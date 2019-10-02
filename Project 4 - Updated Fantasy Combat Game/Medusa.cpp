/*********************************************************************
 ** Program name: Team Fight Simulation
 ** Author: John Olgin
 ** Date: 5/28/17
 ** Description: This program will be a battle simulation between two teams of creatures. The players will be able to choose from 5 characters to fill their team. The characters will battle until one team is out of players and then a score will be tallied to decide who the winner is. The losing character in each battle will be removed from the team, and the winner will go to the back of the queue of the player's team. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, inputValidation.cpp, CreatureQueue.cpp, CreatureQueue.hpp, Tournament.hpp, Tournament.cpp, LoserNode.cpp, LoserNode.hpp, LoserQueue.hpp, and LoserQueue.cpp.
 *********************************************************************/


#include "Medusa.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

/*
 Description: This is the default constructor that will define the name and amount of strength and armor points the character has initially.
 */
Medusa::Medusa():Creature()
{
    name = "Medusa";
    strengthPoints = 8;
    armorPoints = 3;
}




/*
 Description: This is the attacking dice roll function. It will generate two random numbers that represent the character's dice rolls. It will also output the value of the dice rolls and implement Glare if the player rolls two sixes. It won't take any arguments, but it will return an integer representing the sum of all the dice (the total attack).
 */
int Medusa::attackRoll()
{
    int attackRoll1, attackRoll2, totalAttack;
    
    attackRoll1 = rand() % 6 + 1;
    attackRoll2 = rand() % 6 + 1;
    totalAttack = attackRoll1 + attackRoll2;
    
    cout << "Attack: dice roll one is " << attackRoll1 << " and two is " << attackRoll2 << "." <<  endl;
    
    //Medusa uses Glare if the player rolls two sixes
    if(totalAttack == 12)
    {
        totalAttack = 40;
        cout  << "Medusa used Glare to turn the opponent to stone! Her attack will kill the opponent." << endl;
    }
    
    
    return totalAttack;
}




/*
 Description: This is the defensive dice roll function. It will generate one random number that represents the character's dice roll. It will also output the value of the dice roll. It won't take any arguments, but it will return an integer representing the sum of all the dice (the total defense).
 */
int Medusa::defenseRoll()
{
    int defenseRoll1;
    
    defenseRoll1 = rand() % 6 + 1;
    
    cout << "Defense: dice roll is " << defenseRoll1 << "." << endl;
    
    return defenseRoll1;
}



/*
 Description: This function will not do anything. It is solely included to allow Harry Potter's special ability function to work properly.
 */
void Medusa::specialAbility(int deathCount)
{
    
}
