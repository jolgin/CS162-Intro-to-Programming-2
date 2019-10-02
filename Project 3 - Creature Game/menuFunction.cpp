/*********************************************************************
 ** Program name: Team Fight Simulation
 ** Author: John Olgin
 ** Date: 5/28/17
 ** Description: This program will be a battle simulation between two teams of creatures. The players will be able to choose from 5 characters to fill their team. The characters will battle until one team is out of players and then a score will be tallied to decide who the winner is. The losing character in each battle will be removed from the team, and the winner will go to the back of the queue of the player's team. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, inputValidation.cpp, CreatureQueue.cpp, CreatureQueue.hpp, Tournament.hpp, and Tournament.cpp.
 *********************************************************************/


#include "menuFunction.hpp"
#include <iostream>
#include "menuFunction.hpp"
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "inputValidation.hpp"
using namespace std;


/*
 Description: This function will serve as the menu for the entire program. It will allow the user to run different tasks. It will not take any arguments, but it will return an integer representing the user's choice of task.
 */
int menuFunction()
{
    int choice;
    
    cout << "Please choose an option below by entering the corresponding integer: " << endl;
    cout << "\t" << "1. Play Game" << endl;
    cout << "\t" << "2. Print Losers" << endl;
    cout << "\t" << "3. Exit Game" << endl;
    cin >> choice;
    choice = menuChoiceValidation(choice);
    
    return choice;
}



/*
 Description: This function will display the list for player 1 to choose a creature type. It won't take any parameters, but it will return an integer representing player 1's choice of creature.
 */
int player1List()
{
    int choice;
    
    cout << "Choose a player by entering the corresponding integer: " << endl;
    cout << "\t1. Vampire" << endl;
    cout << "\t2. Barbarian" << endl;
    cout << "\t3. Blue Men" << endl;
    cout << "\t4. Medusa" << endl;
    cout << "\t5. Harry Potter" << endl;
    cin >> choice;
    choice = creatureChoiceValidation(choice);


    return choice;
}



/*
 Description: This function will display the list for player 2 to choose a creature type. It won't take any parameters, but it will return an integer representing player 1's choice of creature.
 */
int player2List()
{
    int choice;
  
    
    cout << "Choose a player by entering the corresponding integer: " << endl;
    cout << "\t1. Vampire" << endl;
    cout << "\t2. Barbarian" << endl;
    cout << "\t3. Blue Men" << endl;
    cout << "\t4. Medusa" << endl;
    cout << "\t5. Harry Potter" << endl;
    cin >> choice;
    choice = creatureChoiceValidation(choice);

    
    return choice;
}
