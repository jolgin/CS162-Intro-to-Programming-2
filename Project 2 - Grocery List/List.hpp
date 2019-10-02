/*********************************************************************
 ** Program name: Grocery List
 ** Author: John Olgin
 ** Date: 4/28/17
 ** Description: This function will ultimately allow the user to make a grocery list, add items, remove items, and display the list. The user will be prompted to enter information about the items they want in the list, such as name, unit type, price, and quantity. All of this data will then be displayed once the entire list is output in the program. In order for this program to run these files will need to be in the same directory and compiled together: main.cpp, item.cpp, item.hpp, List.cpp, List.hpp, menuFunction.cpp, menuFunction.hpp, inputValidation.cpp, inputValidation.hpp.
 *********************************************************************/

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include "Item.hpp"

/*
 Description: This class will represent a list of Item objects to be placed into a dynamically allocated array. It will have a function that displays all these items, including their names, quantity, unit price, unit type, and extended price. It will also have variables for the list size, the max capacity, and the total price of all products in the list. The member functions are also designed to allow the user to add items, remove items, increase the size of the array when needed, and test the user’s string input to see if it is in the list. These member functions are made to be organized into a menu function where the user can choose what they want to do. 
 */
class List
{
private:
    Item **itemList;
    int listSize;
    int maxListSize;
    int totalPrice = 0;
    
public:
    List();
    void increaseSize();
    void removeItem(string itemName);
    void addItem(string itemName, int itemPrice, string unit, int itemQuantity);
    void displayItems();
    bool operator==(string itemName);
    void deleteLists();
    
};

#endif /* List_hpp */
