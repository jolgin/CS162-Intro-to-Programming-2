/*********************************************************************
 ** Program name: Grocery List
 ** Author: John Olgin
 ** Date: 4/28/17
 ** Description: This function will ultimately allow the user to make a grocery list, add items, remove items, and display the list. The user will be prompted to enter information about the items they want in the list, such as name, unit type, price, and quantity. All of this data will then be displayed once the entire list is output in the program. In order for this program to run these files will need to be in the same directory and compiled together: main.cpp, item.cpp, item.hpp, List.cpp, List.hpp, menuFunction.cpp, menuFunction.hpp, inputValidation.cpp, inputValidation.hpp.
 *********************************************************************/

#include "List.hpp"
#include "Item.hpp"
#include <iostream>
using namespace std;


/*
 Description: This is the default constructor. It will set the initial size of the list and max capacity  of the list. It will also dynamically allocate a new array. It has no parameters.
 */
List::List()
{
    listSize = 0;
    maxListSize = 4;
    itemList = new Item*[maxListSize];
}



/*
 Description: This function will increase the size of the array if the list size exceeds the max list size. It will do this by adding 15 to the capacity, dynamically allocating a new array, and then it will set the first list equal to the new list. It will not return anything and has no paramets.
 */
void List::increaseSize()
{
    maxListSize += 15;
    Item **biggerList = new Item*[maxListSize];
    
    for(int i = 0; i < listSize; i++)
    {
        biggerList[i] = itemList[i];
    }
    
    itemList = biggerList;
}



/*
 Description: This function will add an item to the grocery list. It takes 4 arguments, a string for the item's name, an integer for the item's price, a string for the item's unit type, and an integer for the item's quantity. It will not return anything.
 */
void List::addItem(string itemName, int itemPrice, string unit, int itemQuantity)
{
    //If the list size is at capacity, call the increaseSize() function to make it bigger
    if(listSize == maxListSize)
    {
        increaseSize();
    }
    
    //Increment
    itemList[listSize++] = new Item(itemName, itemPrice, unit, itemQuantity);
}



/*
 Description: This function will remove an item from the grocery list if the user wants to exclude it. It takes a string representing the item's name as an argument. This must be determined and entered by the user before this function is called. Nothing will be returned.
 */
void List::removeItem(string itemName)
{
    for(int i = 0; i < listSize; i++)
    {
        if(itemList[i]->getName() == itemName)
        {
            for(int j = i; j < listSize - 1; j++)
            {
                itemList[j] = itemList[j + 1];
            }
            --listSize;
        }
    }
}



/*
 Description: This function will display the items in the cart and all of their information. It will then display the grand total of all products in the cart. 
 */
void List::displayItems()
{
    //This loop will print all the items and their information as well as sum up their total prices
    for (int i = 0; i < listSize; i++)
    {
        itemList[i]->printItem();
        
        
        totalPrice += itemList[i]->calculateTotalPrice();
    }
    
    cout << "Grand Total: " << totalPrice << endl << endl;
    totalPrice = 0;
}



/*
 Description: This is the overloader that will compare the user's input to the item's in the list. It will return a bool variable. It will take a string parameter representing the item's name. This will have to be determined and input by the user before this function is called.
 */
bool List::operator==(string itemName)
{
    bool match = false;
    
    for(int i = 0; i < listSize; i++)
    {
        if(itemName == itemList[i]->getName())
        {
            match = true;
            break;
        }
        else
        {
            match = false;
        }
    }
    
    return match;
}



/*
 Description: This function will deallocate the array to free up the memory
 */
void List::deleteLists()
{
    delete [] itemList;
}
