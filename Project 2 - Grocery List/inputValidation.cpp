/*********************************************************************
 ** Program name: Grocery List
 ** Author: John Olgin
 ** Date: 4/28/17
 ** Description: This function will ultimately allow the user to make a grocery list, add items, remove items, and display the list. The user will be prompted to enter information about the items they want in the list, such as name, unit type, price, and quantity. All of this data will then be displayed once the entire list is output in the program. In order for this program to run these files will need to be in the same directory and compiled together: main.cpp, item.cpp, item.hpp, List.cpp, List.hpp, menuFunction.cpp, menuFunction.hpp, inputValidation.cpp, inputValidation.hpp.
 *********************************************************************/

#include "inputValidation.hpp"
#include <iostream>
using namespace std;



/*
 Description: This function will be used to validate the user's choice from the menu. Therefore, it will force the user to enter an integer value of 1, 2, 3 or 4. It will return the user's choice as an integer. It will also take one integer parameter that represents the user's choice. This must be determined and input by the user before this function is called.
 */
int menuChoiceInputVal(int choice)
{
    while(!choice || (choice != 1 && choice != 2 && choice != 3 && choice != 4))
    {
        cout << "Invalid Input. Please enter a 1, 2, 3 or 4 to choose an option from below: " << endl;
        cout << "\t" << "1.  Add an item to the grocery list" << endl;
        cout << "\t" << "2.  Remove an item from the grocery list" << endl;
        cout << "\t" << "3.  Display the grocery list" << endl;
        cout << "\t" << "4.  Exit the program" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        
        cin >> choice;
    }
    
    return choice;
}



/*
 Description: This function will be used to validate the user's input for the price and quantity of an item. It will force the user to enter an integer value. It will return the user's number as an integer. It will also take one integer parameter that represents the user's number. This must be determined and input by the user before this function is called.
 */
int priceAndQuantityInputVal(int priceOrQuantity)
{
    while(!priceOrQuantity)
    {
        cout << "Please enter an integer value: " << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        
        cin >> priceOrQuantity;
    }
    
    return priceOrQuantity;
}



/*
 Description: This function will be used to validate the user's input for whether or not the user wants to update the item they entered. It will force the user to enter a Y, y, N, or n character. It will return the user's choice as a character. It will also take one character parameter that represents the user's choice. This must be determined and input by the user before this function is called.
 */
char updateChoiceInputVal(char updateChoice)
{
    while(updateChoice != 'Y' && updateChoice != 'y' && updateChoice != 'N' && updateChoice != 'n')
    {
        cout << "Please enter 'Y' for yes or 'N' for no." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        
        cin >> updateChoice;
    }
    
    return updateChoice;
}



string stringInputVal(string itemName)
{
    while(itemName.size() > 25)
    {
        cout << "The item name is too long. It must be less than 25 characters. Please enter the item name: " << endl;
        cin.clear();
        cin.ignore(1000, 'n');
        
        getline(cin, itemName);
    }
    
    
    return itemName;
}



