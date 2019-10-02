/*********************************************************************
 ** Program name: Grocery List
 ** Author: John Olgin
 ** Date: 4/28/17
 ** Description: This function will ultimately allow the user to make a grocery list, add items, remove items, and display the list. The user will be prompted to enter information about the items they want in the list, such as name, unit type, price, and quantity. All of this data will then be displayed once the entire list is output in the program. In order for this program to run these files will need to be in the same directory and compiled together: main.cpp, item.cpp, item.hpp, List.cpp, List.hpp, menuFunction.cpp, menuFunction.hpp, inputValidation.cpp, inputValidation.hpp.
 *********************************************************************/

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include <string> 
using namespace std;

/*
 Description: This class will represent an individual item to be found in a grocery store. It will contain variables for the item’s name, quantity, unit price, unit type, and extended price. There will also be functions to set these variables and print the item out for the user to see. Therefore, this class is an abstraction of what a customer would want to see for each item at a grocery store. The concept of this class is to have numerous instances of this Item placed into an array within the List class.
 */
class Item
{
private:
    string unitType;
    string itemName;
    int itemQuantity;
    int unitPrice;
    int totalPrice;
    
public:
    Item();
    Item(string itemName, int itemPrice, string unit, int itemQuantity);
    void setUnitType(string type);
    string getUnitType();
    void setName(string name);
    string getName();
    void setQuantity(int quantity);
    int getQuantity();
    void setUnitPrice(int price);
    int getUnitPrice();
    int calculateTotalPrice();
    void printItem();
    
    
};


#endif /* Item_hpp */
