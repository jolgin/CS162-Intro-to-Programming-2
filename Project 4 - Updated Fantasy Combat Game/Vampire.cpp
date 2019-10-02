/*********************************************************************
 ** Program name: Team Fight Simulation
 ** Author: John Olgin
 ** Date: 5/28/17
 ** Description: This program will be a battle simulation between two teams of creatures. The players will be able to choose from 5 characters to fill their team. The characters will battle until one team is out of players and then a score will be tallied to decide who the winner is. The losing character in each battle will be removed from the team, and the winner will go to the back of the queue of the player's team. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, inputValidation.cpp, CreatureQueue.cpp, CreatureQueue.hpp, Tournament.hpp, Tournament.cpp, LoserNode.cpp, LoserNode.hpp, LoserQueue.hpp, and LoserQueue.cpp.
 *********************************************************************/


#include "Vampire.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

/*
 Description: This is the default constructor that will define the name and amount of strength and armor points the character has initially.
 */
Vampire::Vampire():Creature()
{
    name = "Vampire";
    strengthPoints = 18;
    armorPoints = 1;
}



/*
 Description: This is the attacking dice roll function. It will generate one random number that represents the character's dice roll. It will also output the value of the dice roll. It won't take any arguments, but it will return an integer representing the sum of all the dice (the total attack).
 */
int Vampire::attackRoll()
{
    int attackRoll1;
    
    attackRoll1 = rand() % 12 + 1;
    cout << "Attack: dice roll is " << attackRoll1 << "." << endl;
    
    
    return attackRoll1;
}




/*
 Description: This is the defensive dice roll function. It will generate one random number that represents the character's dice roll. It will also output the value of the dice roll. It won't take any arguments, but it will return an integer representing the sum of all the dice (the total defense). This function has the vampire's special ability in it as well. It will initially generate a random number of either 1 of 2 to decide if the vampire uses charm or not.
 */
int Vampire::defenseRoll()
{
    int charmRoll, totalDefense, defenseRoll1;
    
    charmRoll = rand() % 2 + 1;
    
    if(charmRoll == 1)
    {
        defenseRoll1 = rand() % 6 + 1;
        cout << "Defense: dice roll is " << defenseRoll1 << "." << endl;
        
        totalDefense = defenseRoll1;
    }
    else
    {
        totalDefense = 60;
        cout << "Vampire has charmed the opponent and can't be attacked this round!" << endl;
    }
    
    
    return totalDefense;
}



/*
 Description: This function will not do anything. It is solely included to allow Harry Potter's special ability function to work properly.
 */
void Vampire::specialAbility(int deathCount)
{
    
}
