/*********************************************************************
 ** Program name: Grocery List
 ** Author: John Olgin
 ** Date: 4/28/17
 ** Description: This function will ultimately allow the user to make a grocery list, add items, remove items, and display the list. The user will be prompted to enter information about the items they want in the list, such as name, unit type, price, and quantity. All of this data will then be displayed once the entire list is output in the program. In order for this program to run these files will need to be in the same directory and compiled together: main.cpp, item.cpp, item.hpp, List.cpp, List.hpp, menuFunction.cpp, menuFunction.hpp, inputValidation.cpp, inputValidation.hpp.
 *********************************************************************/

#include "Item.hpp"
#include <iostream>
using namespace std;



/*
 Description: This is the default constructor that will set the different member variables to a default amount or string when a new item is created.
*/
Item::Item()
{
    setName("No name");
    setUnitType("No unit");
    setQuantity(0);
    setUnitPrice(0);
}



/*
 Description: This is a non default constructor that will set the member variables euqal to the user-entered data and call the total price function. It will take 4 arguments: a string for the item name, an integer for the item's price, a string for the item unit type, and an integer for the item quantity. All of this data must be entered and determined by the user before this function is called.
*/
Item::Item(string itemName, int itemPrice, string unit, int itemQuantity)
{
    setName(itemName);
    setUnitPrice(itemPrice);
    setUnitType(unit);
    setQuantity(itemQuantity);
    calculateTotalPrice();
}



/*
 Description: This will set the item's unit type equal to the user-entered unit type. It will take a string for the unit type as an argument. This argument must be determined by the user before the function is called. There is no return type.
*/
void Item::setUnitType(string type)
{
    unitType = type;
}



/*
 Description: This will return the unit type as a string. It has no parameters.
 */
string Item::getUnitType()
{
    return unitType;
}



/*
 Description: This will set the item's name equal to the user-entered item name. It will take a string for the name as an argument. This argument must be determined by the user before the function is called. There is no return type.
 */
void Item::setName(string name)
{
    itemName = name;
}



/*
 Description: This will return the item's name as an integer. It has no parameters.
 */
string Item::getName()
{
    return itemName;
}



/*
 Description: This will set the item's quantity equal to the user-entered quantity. It will take an integer for the quantity as an argument. This argument must be determined by the user before the function is called. There is no return type.
 */
void Item::setQuantity(int quantity)
{
    itemQuantity = quantity;
}



/*
 Description: This function will return the quantity of the item on the list. It has no parameters, but will retun the unit price as an integer.
 */
int Item::getQuantity()
{
    return itemQuantity;
}



/*
 Description: This will set the item's unit price equal to the user-entered unit price. It will take an integer for the quantity as an argument. This argument must be determined by the user before the function is called. There is no return type.
 */
void Item::setUnitPrice(int price)
{
    unitPrice = price;
}



/*
 Description: This function will return the unit price of the item. It has no parameters, but will return the unit price as an integer.
 */
int Item::getUnitPrice()
{
    return unitPrice;
}



/*
 Description: This function will calculate the total price for a specific item. It will multiply the unit price by the quantity. This value will be returned as an integer. The function has no parameters.
 */
int Item::calculateTotalPrice()
{
    totalPrice = unitPrice * itemQuantity;
    
    
    return totalPrice;
}



/*
 Description: This function will print all the information about a specific item: name, unit type, quantity, unit price, and the total price. It takes no arguments and will not return anything.
 */
void Item::printItem()
{
    cout << "Product Name: " << itemName << endl;
    cout << "Product Unit: " << unitType << endl;
    cout << "Quantity: " << itemQuantity << endl;
    cout << "Unit Price: " << unitPrice << endl;
    cout << "Total Price: " << totalPrice << endl << endl;
}
