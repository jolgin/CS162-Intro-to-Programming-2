/*********************************************************************
 ** Program name: Team Fight Simulation
 ** Author: John Olgin
 ** Date: 5/28/17
 ** Description: This program will be a battle simulation between two teams of creatures. The players will be able to choose from 5 characters to fill their team. The characters will battle until one team is out of players and then a score will be tallied to decide who the winner is. The losing character in each battle will be removed from the team, and the winner will go to the back of the queue of the player's team. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, inputValidation.cpp, CreatureQueue.cpp, CreatureQueue.hpp, Tournament.hpp, and Tournament.cpp.
 *********************************************************************/

#include "BlueMen.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;

/*
 Description: This is the default constructor that will define the name and amount of strength and armor points the character has initially.
 */
BlueMen::BlueMen():Creature()
{
    name = "Blue Men";
    strengthPoints = 12;
    armorPoints = 3;
}



/*
 Description: This is the attacking dice roll function. It will generate two random numbers that represent the character's dice rolls. It will also output the value of the dice rolls. It won't take any arguments, but it will return an integer representing the sum of all the dice (the total attack).
 */
int BlueMen::attackRoll()
{
    int attackRoll1, attackRoll2, totalAttack;
    
    attackRoll1 = rand() % 10 + 1;
    attackRoll2 = rand() % 10 + 1;
    totalAttack = attackRoll1 + attackRoll2;
    
    cout << "Attack: dice roll one is " << attackRoll1 << " and two is " << attackRoll2 << endl;

    
    return totalAttack;
}




/*
 Description: This is the defensive dice roll function. It will generate two random numbers that represent the character's dice rolls. It will also output the value of the dice rolls. It won't take any arguments, but it will return an integer representing the sum of all the dice (the total defense). This function will also implement Blue Men's special ability. It will use 3 dice rolls if the character's strength is more than 8, 2 dice rolls if it's greater than 4 but no greater than 8, and one dice roll is it is greater than zero but no greater than 4. 
 */
int BlueMen::defenseRoll()
{
    int defenseRoll1, defenseRoll2, defenseRoll3, totalDefense;
    
    defenseRoll1 = rand() % 6 + 1;
    defenseRoll2 = rand() % 6 + 1;
    defenseRoll3 = rand() % 6 + 1;
    

    
    if(strengthPoints > 8)
    {
        totalDefense = defenseRoll1 + defenseRoll2 + defenseRoll3;
        cout << "Defense: dice roll one is " << defenseRoll1 << ", two is " << defenseRoll2 << ", and three is " << defenseRoll3 << "." << endl;
    }
    
    else if(strengthPoints > 4 && strengthPoints <= 8)
    {
        totalDefense = defenseRoll1 + defenseRoll2;
        cout << "Blue Men has lost a defensive dice roll and now only has two." << endl;
        cout << "Defense: dice roll one is " << defenseRoll1 << " and two is " << defenseRoll2 << "." << endl;
    }
    
    else if(strengthPoints > 0 && strengthPoints <= 4)
    {
        totalDefense = defenseRoll1;
        cout << "Blue Men has lost two defensive dice rolls and now only has one." << endl;
        cout << "Defense: dice roll one is " << defenseRoll1 << "." << endl;
    }
    
    
    return totalDefense;
}



/*
 Description: This function will not do anything. It is solely included to allow Harry Potter's special ability function to work properly.
 */
void BlueMen::specialAbility(int deathCount)
{
    
}
