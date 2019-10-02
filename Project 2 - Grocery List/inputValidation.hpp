/*********************************************************************
 ** Program name: Grocery List
 ** Author: John Olgin
 ** Date: 4/28/17
 ** Description: This function will ultimately allow the user to make a grocery list, add items, remove items, and display the list. The user will be prompted to enter information about the items they want in the list, such as name, unit type, price, and quantity. All of this data will then be displayed once the entire list is output in the program. In order for this program to run these files will need to be in the same directory and compiled together: main.cpp, item.cpp, item.hpp, List.cpp, List.hpp, menuFunction.cpp, menuFunction.hpp, inputValidation.cpp, inputValidation.hpp.
 *********************************************************************/

#ifndef inputValidation_hpp
#define inputValidation_hpp

#include <stdio.h>
#include <string>
using namespace std;

int menuChoiceInputVal(int choice);
int priceAndQuantityInputVal(int priceOrQuantity);
char updateChoiceInputVal(char updateChoice);
string stringInputVal(string itemName);

#endif /* inputValidation_hpp */
