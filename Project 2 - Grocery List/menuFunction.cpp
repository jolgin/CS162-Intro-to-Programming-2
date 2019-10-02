/*********************************************************************
 ** Program name: Grocery List
 ** Author: John Olgin
 ** Date: 4/28/17
 ** Description: This function will ultimately allow the user to make a grocery list, add items, remove items, and display the list. The user will be prompted to enter information about the items they want in the list, such as name, unit type, price, and quantity. All of this data will then be displayed once the entire list is output in the program. In order for this program to run these files will need to be in the same directory and compiled together: main.cpp, item.cpp, item.hpp, List.cpp, List.hpp, menuFunction.cpp, menuFunction.hpp, inputValidation.cpp, inputValidation.hpp.
 *********************************************************************/

#include "menuFunction.hpp"
#include "inputValidation.hpp"
#include <iostream>
using namespace std;

/*
 Description: This function will serve as a menu for the user to choose a task they want to do on the grocery list. The user can either add, remove, display the list, or exit the program. It will not take any parameters, but it will return an integer representing the user's choice. 
 */
int menuFunction()
{
    int menuChoice;
    
    
    cout << "Please select an option from the menu below." << endl;
    cout << "\t" << "1.  Add an item to the grocery list" << endl;
    cout << "\t" << "2.  Remove an item from the grocery list" << endl;
    cout << "\t" << "3.  Display the grocery list" << endl;
    cout << "\t" << "4.  Exit the program" << endl;
    
    
    cin >> menuChoice;
    menuChoice = menuChoiceInputVal(menuChoice);
    cin.ignore();
    
    
    return menuChoice;
}
