/*********************************************************************
 ** Program name: Dice War
 ** Author: John Olgin
 ** Date: 4/24/17
 ** Description: This program will allow two people to play a game of war using dice. There will be a Game class that has two classes within it--Die class and LoadedDie class--and uses them to play the game. The user will be prompted to choose the players' types (loaded or regular) and sizes of die. The user will also choose how many rounds the game lasts. The Game class will iterate through the rounds and compare the players' rolls, ultimately displaying a winner. Die.cpp, Die.hpp, LoadedDie.cpp, LoadedDie.hpp, Game.cpp, Game.hpp, inputValidation.cpp, inputValidation.hpp, and main.cpp need to be in the same directory and compiled together for this program to run correctly.
 *********************************************************************/

#include "inputValidation.hpp"
#include <iostream>
using namespace std;

/*
 Description: This function will validate the input for the number of rounds and sides the user enters. It will force the user to enter an integer value of one or greater for the number of rounds in the game and number of sides for each player's die. This function will take an integer as an argument that represents the user-entered value for rounds or sides. Therefore, the user must be prompted to enter in a value for rounds or sides before this function is called. It will return an integer for the rounds/sides once the user provides a valid input.
*/
int roundsAndSidesInputVal(int roundsOrSides)
{
    while(!roundsOrSides || roundsOrSides < 1)
    {
        cout << "Please enter an integer value of 1 or more." << endl;
        cin.clear();
        cin.ignore(1000, '\n');

        cin >> roundsOrSides;
    }
    
    return roundsOrSides;
}




/*
 Description: This function will validate the input for the type of die chosen for each player. It will force the user to enter one of the following characters for each player: Y, y, N, n. This function will take a character as an argument that represents the user-entered type of die for each player. Therefore, the user must be prompted to enter in a character before this function is called. It will return a character for the type of die once the user provides a valid input.
*/
char dieTypeInputVal(char dieType)
{
    while(dieType != 'Y' && dieType != 'y' && dieType != 'N' && dieType != 'n')
    {
        cout << "Invalid input. Please enter 'Y' for yes or 'N' for no." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        
        cin >> dieType;
    }
    
    return dieType;
}



/*
 Description: This function will validate the input for the game's option menu. It will force the user to enter one of the options from the menu, so an integer value of 1 or 2. This function will take an integer as an argument that represents the user-entered choice in the menu. Therefore, the user must be prompted to enter in a choice before this function is called. It will return an integer for the user's choice once the user provides a valid input.
 */
int menuChoiceInputVal(int choice)
{
    while(!choice || (choice != 1 && choice != 2))
    {
        cout << "Invalid input. Please choose and enter either option 1 or 2." << endl;
        cout << "\t" << "1. Start/Play Again" << endl;
        cout << "\t" << "2. Exit Game" << endl;
        
        cin.clear();
        cin.ignore(1000, '\n');
        
        cin >> choice;
    }
    
    return choice;
}
