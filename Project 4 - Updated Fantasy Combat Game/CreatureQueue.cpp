/*********************************************************************
 ** Program name: Team Fight Simulation
 ** Author: John Olgin
 ** Date: 5/28/17
 ** Description: This program will be a battle simulation between two teams of creatures. The players will be able to choose from 5 characters to fill their team. The characters will battle until one team is out of players and then a score will be tallied to decide who the winner is. The losing character in each battle will be removed from the team, and the winner will go to the back of the queue of the player's team. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, inputValidation.cpp, CreatureQueue.cpp, CreatureQueue.hpp, Tournament.hpp, Tournament.cpp, LoserNode.cpp, LoserNode.hpp, LoserQueue.hpp, and LoserQueue.cpp.
 *********************************************************************/
#include "CreatureQueue.hpp"
#include <iostream>
using namespace std;

/*
 Description: This function is the default constructor for the CreatureQueue class
 */
CreatureQueue::CreatureQueue()
{
    head = 0;
    tail = 0;
}



/*
 Description: This is the default deconstructor
 */
CreatureQueue::~CreatureQueue()
{
    Creature *temp;
    
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}


/*
 Description: This function will allow the user to add a node to the back of the linked list. This will be used to add character's to the players' teams. It will take a pointer to a creature object and a string representing the alias or nickname of the character. These should be determined and input by the user before this function is called. It will not return anything.
 */
void CreatureQueue::addBack(Creature *creature, string alias)
{
    if(head == 0)
    {
        creature->nickName = alias;
        head = creature;
        head->next = NULL;
        
        return;
    }
    
    if(head != 0 && tail == 0)
    {
        creature->next = NULL;
        creature->nickName = alias;
        tail = creature;
        head->next = tail;
        
        return;
    }
    
    creature->nickName = alias;
    creature->next = NULL;
    tail->next = creature;
    tail = creature;
}



/*
 Description: This function will remove the front of the linked list if the character loses the battle. It will not take any arguments and won't return anything.
 */
void CreatureQueue::removeFront()
{
    if(head == NULL)
    {
        cout << "List is empty" << endl;
        
        return;
    }
    
    if(head == tail)
    {
        Creature *temphead = head;
        head = head->next;
        delete temphead;
        
        head = NULL;
        tail = NULL;
        
        return;
    }
    
    Creature *temp = head;
    head = head->next;
    delete temp;
}



/*
 Description: This function will move the head of the linked list to the back of the lineup if the character wins its battle. It will take no arguments and also won't return anything.
 */
void CreatureQueue::moveToBack()
{
    /*if(head == tail)
    {
        return;
    }
    
    Creature *temp = head;
    head = head->next;
    temp->next = NULL;
    tail->next = temp;
    tail = temp;
    tail->next = NULL;
    delete temp;
     */
}



/*
 Description: This function will print out the contents of the linked list. It won't return anything or take any arguments.
 */
void CreatureQueue::print()
{
    Creature *current = head;
    
    if(head == NULL)
    {
        cout << "List is empty" << endl;
        
        return;
    }
    if(head != NULL && tail == NULL)
    {
        cout << head->nickName << endl;
        return;
    }
    
    while(current != NULL)
    {
        cout << current->nickName << " ";
        current = current->next;
    }
}



/*
 Description: This function will determine if the linked list is empty. This is to be used to determine when the game is over.
 */
bool CreatureQueue::isEmpty()
{
    bool empty;
    
    if(head == NULL)
    {
        empty = true;
    }
    else
    {
        empty = false;
    }
    
    return empty;
}


/*
 Description: This function will simply return a pointer to the head creature of a list to be used in the fight function()
 */
Creature* CreatureQueue::returnHead()
{
    Creature *temp = head;
    return temp;
}
