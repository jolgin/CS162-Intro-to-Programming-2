/*********************************************************************
 ** Program name: Team Fight Simulation
 ** Author: John Olgin
 ** Date: 5/28/17
 ** Description: This program will be a battle simulation between two teams of creatures. The players will be able to choose from 5 characters to fill their team. The characters will battle until one team is out of players and then a score will be tallied to decide who the winner is. The losing character in each battle will be removed from the team, and the winner will go to the back of the queue of the player's team. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, inputValidation.cpp, CreatureQueue.cpp, CreatureQueue.hpp, Tournament.hpp, Tournament.cpp, LoserNode.cpp, LoserNode.hpp, LoserQueue.hpp, and LoserQueue.cpp.
 *********************************************************************/

#include "LoserQueue.hpp"

/*
 Description: This function is the default constructor for the LoserQueue class.
 */
LoserQueue::LoserQueue()
{
    head = NULL;
    tail = NULL;
}


/*
 Description: This function is the destructor for the LoserQueue class.
 */
LoserQueue::~LoserQueue()
{
    LoserNode *temp;
    
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}


/*
 Description: This function will add a node to the front of the linked list. It will not return anything, but it will take a pointer to a LoserNode object and a string representing the nick name or alias of the creature. These must be determined before this function is called.
 */
void LoserQueue::addFront(LoserNode *node, string alias)
{
    if(head == 0)
    {
        node->next = head;
        node->name = alias;
        head = node;
        head->next = NULL;
        
        return;
    }
    
    if(head != NULL && tail == NULL)
    {
        LoserNode *temp = head;
        tail = temp;
        node->next = tail;
        node->name = alias;
        head = node;
        tail->next = NULL;
        
        return;
    }
    
    node->next = head;
    node->name = alias;
    head = node;
}


/*
 Description: This function will print out the the linked list. It won't return anything or take any arguments.
 */
void LoserQueue::print()
{
    LoserNode *current = head;
    
    if(head == NULL)
    {
        cout << "List is empty" << endl;
        
        return;
    }
    if(head != NULL && tail == NULL)
    {
        cout << head->name << endl;
        
        return;
    }
    
    while(current != NULL)
    {
        cout << current->name << " ";
        current = current->next;
    }
    
    cout << endl;
}
