/********************************************************************* 
 ** Program name: Grocery List
 ** Author: John Olgin
 ** Date: 4/28/17
 ** Description: This function will ultimately allow the user to make a grocery list, add items, remove items, and display the list. The user will be prompted to enter information about the items they want in the list, such as name, unit type, price, and quantity. All of this data will then be displayed once the entire list is output in the program. In order for this program to run these files will need to be in the same directory and compiled together: main.cpp, item.cpp, item.hpp, List.cpp, List.hpp, menuFunction.cpp, menuFunction.hpp, inputValidation.cpp, inputValidation.hpp.
 *********************************************************************/

#include <iostream>
#include <string>
#include "Item.hpp"
#include "List.hpp"
#include "menuFunction.hpp"
#include "inputValidation.hpp"
using namespace std;

int main()
{
    int menuChoice;
    List groceryList;
    
    menuChoice = menuFunction();
    
    
    while(menuChoice != 4)
    {
        //If the user chooses to add an item this section will run
        if(menuChoice == 1)
        {
            string addName, type;
            int price, quantity;
            bool match;
            
            
            //Prompt and validate item name
            cout << "Please enter the product information." << endl;
            cout << "Product Name (Must be 25 characters or less): " << endl;
            getline(cin, addName);
            addName = stringInputVal(addName);
            
            
            //Prompt and validate item unit type
            cout << "Product Unit Type (Must be 25 characters or less. i.e. can, box, ounces, pounds): " << endl;
            getline(cin, type);
            type = stringInputVal(type);
            
            //Prompt and validate item price
            cout << "Product Price (Please enter an integer): " << endl;
            cin >> price;
            price = priceAndQuantityInputVal(price);
            
            
            //Prompt and validate item quantity
            cout << "Product Quantity (Please enter an integer): " << endl;
            cin >> quantity;
            quantity = priceAndQuantityInputVal(quantity);
            
            
            
            
            //This block of code will determine if the item is already in the list, and will ask the user if they want to update it if it is.
            match = groceryList.operator==(addName);
            
            if(match == true)
            {
                char updateChoice;
                cout << "Item is already in the list, do you want to update it? Enter 'Y' for yes or 'N' for no." << endl;
                cin >> updateChoice;
                
                updateChoice = updateChoiceInputVal(updateChoice);
                
                
                
                //Remove the original item and replace it if the user chooses to update it
                if(updateChoice == 'Y' || updateChoice == 'y')
                {
                    groceryList.removeItem(addName);
                    groceryList.addItem(addName, price, type, quantity);
                }
            }
            
            
            // If the item does not match anything in the list, add the item to the list
            else if(match == false)
            {
                groceryList.addItem(addName, price, type, quantity);
            }
        }
        
        
        //If the user chooses to remove an item this section will run
        else if(menuChoice == 2)
        {
            string removeName;
            
            cout << "Please enter the name of the product you want to delete: " << endl;
            getline(cin, removeName);
            
            removeName = stringInputVal(removeName);
            
            
            
            groceryList.removeItem(removeName);
        }
        
        
        //If the user chooses to display the grocery list this section will run
        else if(menuChoice == 3)
        {
            cout << "Here is a list of the items on your grocery list: " << endl;
            
            
            groceryList.displayItems();
        }
        
        
        menuChoice = menuFunction();
    }
    
    
    //If the user chooses to exit this section will  run
    if(menuChoice == 4)
    {
        groceryList.deleteLists();
        cout << "Bye!" << endl;
    }
}
