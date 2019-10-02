/*********************************************************************
 ** Program name: Team Fight Simulation
 ** Author: John Olgin
 ** Date: 5/28/17
 ** Description: This program will be a battle simulation between two teams of creatures. The players will be able to choose from 5 characters to fill their team. The characters will battle until one team is out of players and then a score will be tallied to decide who the winner is. The losing character in each battle will be removed from the team, and the winner will go to the back of the queue of the player's team. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, inputValidation.cpp, CreatureQueue.cpp, CreatureQueue.hpp, Tournament.hpp, and Tournament.cpp.
 *********************************************************************/


#include "inputValidation.hpp"
#include <iostream>
using namespace std;


/*
 Description: This function will validate the user input for the menu function. It will force the user to enter a valid choice from the menu. It will take an integer representing the user's initial choice. This must be determined and input by the user before calling this function. It will return an integer representing the user's final choice that has been validated.
 */
int menuChoiceValidation(int choice)
{
    while(!cin || (choice != 1 && choice != 2 && choice != 3))
    {
        cout << "Invalid input. Please enter an integer corresponding to a valid option from the menu below:" << endl;
        cout << "\t" << "1. Play Game" << endl;
        cout << "\t" << "2. Print Losers" << endl;
        cout << "\t" << "3. Exit" << endl;
        cin.clear();
        cin.ignore();
        
        
        cin >> choice;
    }
    
    return choice;
}



/*
 Description: This function will validate the user's input when they choose a creature type to use in battle. It will force them to choose a number between 1-5 according to the creature they want. It will take an integer parameter representing the user's initial choice. This must be determined and input by the user before this function is called. It will return an integer representing the user's final validated choice. 
 */
int creatureChoiceValidation(int choice)
{
    while(!cin || (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5))
    {
        cout << "Invalid input. Please enter an integer corresponding to a valid option from the menu below:" << endl;
        cout << "\t1. Vampire" << endl;
        cout << "\t2. Barbarian" << endl;
        cout << "\t3. Blue Men" << endl;
        cout << "\t4. Medusa" << endl;
        cout << "\t5. Harry Potter" << endl;
        cin.clear();
        cin.ignore();
        
        
        cin >> choice;
    }
    
    
    return choice;
}



int teamSizeValidation(int size)
{
    while(!cin || size > 10 || size < 1)
    {
        cout << "Invalid input. Please enter an integer for the team size (Less than 10): " << endl;
        cin.clear();
        cin.ignore();
        
        cin >> size;
    }
    
    return size;
}



string nameValidation(string name)
{
    while(name.length() >= 20)
    {
        cout << "That name is too long, please enter a name of 20 characters or less: " << endl;
        cin.clear();
        cin.ignore();
        
        
        getline(cin, name);
        cin.clear();
        cin.ignore();
    }
    
    return name; 
}
