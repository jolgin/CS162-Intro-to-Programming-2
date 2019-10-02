/*********************************************************************
 ** Program name: Team Fight Simulation
 ** Author: John Olgin
 ** Date: 5/28/17
 ** Description: This program will be a battle simulation between two teams of creatures. The players will be able to choose from 5 characters to fill their team. The characters will battle until one team is out of players and then a score will be tallied to decide who the winner is. The losing character in each battle will be removed from the team, and the winner will go to the back of the queue of the player's team. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, inputValidation.cpp, CreatureQueue.cpp, CreatureQueue.hpp, Tournament.hpp, Tournament.cpp, LoserNode.cpp, LoserNode.hpp, LoserQueue.hpp, and LoserQueue.cpp.
 *********************************************************************/

#include "Tournament.hpp"
#include "menuFunction.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

/*
 Description: This function is the default constructor
 */
Tournament::Tournament()
{
    
}



/*
 Description: This is the default deconstructor
 */
Tournament::~Tournament()
{
    loserList.~LoserQueue();
    player1List.~CreatureQueue();
    player2List.~CreatureQueue();
}



/*
 Description: This function will be used to fill player 1's team lineup. It will take a pointer to a creature and a string representing the creature's nickname. These must be determined in the main function before this function is called.
 */
void Tournament::fillP1List(Creature *newCreature, string nickName)
{
    player1List.addBack(newCreature, nickName);
}



/*
 Description: This function will be used to fill player 1's team lineup. It will take a pointer to a creature and a string representing the creature's nickname. These must be determined in the main function before this function is called.
 */
void Tournament::fillP2List(Creature *newCreature, string nickName)
{
    player2List.addBack(newCreature, nickName);
}



/*
 Description: This function will control the die rolls and the updating of strength and armor points for each character. The code in this function is essentially the same code that was present in Project 3. It will return an integer representing the winner of the fight in that round.
 */
int Tournament::fight()
{
    Creature *p1, *p2;
    int firstAttacker, p1DeathCount = 0, p2DeathCount = 0, winner;
    
    p1 = player1List.returnHead();
    p2 = player2List.returnHead();
    srand((int)time(0));
    
    
    
    //Output the players' characters' initial stats
    cout << "Player 1's starting strength is " << p1->getStrength() << " and armor is " << p1->getArmor() << endl;
    cout << "Player 2's starting strength is " << p2->getStrength() << " and armor is " << p2->getArmor() << endl << endl << endl;
    
    //Determine who will attack first
    firstAttacker = rand() % 2 + 1;
    cout << "Player " << firstAttacker << " will attack first." << endl << endl << endl;
    
    
    //Begin the game loop
    while(p1->getStrength() > 0 && p2->getStrength() > 0)
    {
        int p1Attack, p2Attack, p1Defend, p2Defend, p1NetAttack, p2NetAttack, p1UpdatedStrength, p2UpdatedStrength;
        int p1UpdateArmor, p2UpdateArmor;
        
        
        //This section will allow Player 1 to attack first
        if(firstAttacker == 1)
        {
            //Player one attacks first and player two defends
            p1Attack = p1->attackRoll();
            p2Defend = p2->defenseRoll();
            p1NetAttack = p1Attack - p2Defend;
            
            
            //If player 1's attack < player 2's defense, set the net attack to zero so no damage is done
            if(p1Attack <= p2Defend)
            {
                p1NetAttack = 0;
            }
            
            
            
            //if the attack > than the current armor value then new strength = strength + armor - attack
            if(p1NetAttack >= p2->getArmor())
            {
                p2UpdatedStrength = p2->getStrength() + p2->getArmor() - p1NetAttack;
                p2->setArmor(0);
                p2->setStrength(p2UpdatedStrength);
            }
            //If the attack is less than the armor value then just subtract it from the armor and leave strength alone
            else
            {
                p2UpdateArmor = p2->getArmor() - p1NetAttack;
                p2->setArmor(p2UpdateArmor);
            }
            
            
            
            //Output the attack value and the remaining strength and armor of the defensive player
            cout << "Player 1's net attack is " << p1NetAttack << endl;
            cout << "Player 2's remaining strength is " << p2->getStrength() << " and remaining armor is " << p2->getArmor() << endl << endl;
            
            
            
            //Increment death counter if the player dies
            if(p2->getStrength() <= 0)
            {
                p2DeathCount++;
                p2->specialAbility(p2DeathCount);
            }
            
            
            //Output that player 1 wins and break out of the while loop if strength is 0 or less
            if(p2->getStrength() <= 0)
            {
                cout << "Player 2 is dead with " << p2->getName() << " " << p2->nickName <<"! Player 1 wins with " << p1->getName() << " " << p1->nickName << "!" << endl << endl << endl;
                
                p1->recoverStrength();
                
                string name = p2->nickName;
                LoserNode *l1 = new LoserNode;
                loserList.addFront(l1, name);
                
                player1List.moveToBack();
                player2List.removeFront();
                
                winner = 1;
                break;
            }
            
            
            
            
            
            
            //Player two attacks now
            p2Attack = p2->attackRoll();
            p1Defend = p1->defenseRoll();
            p2NetAttack = p2Attack - p1Defend;
            
            
            if(p2Attack <= p1Defend)
            {
                p2NetAttack = 0;
            }
            
            
            
            if(p2NetAttack >= p1->getArmor())
            {
                p1UpdatedStrength = p1->getStrength() + p1->getArmor() - p2NetAttack;
                p1->setArmor(0);
                p1->setStrength(p1UpdatedStrength);
            }
            else
            {
                p1UpdateArmor = p1->getArmor() - p2NetAttack;
                p1->setArmor(p1UpdateArmor);
            }
            
            
            
            cout << "Player 2's net attack is " << p2NetAttack << endl;
            cout << "Player 1's remaining strength is " << p1->getStrength() << " and remaining armor is " << p1->getArmor()<< endl << endl;
            
            
            
            if(p1->getStrength() <= 0)
            {
                p1DeathCount++;
                p1->specialAbility(p1DeathCount);
            }
            
            
            if(p1->getStrength() <= 0)
            {
                cout << "Player 1 is dead with " << p1->getName() << " " << p1->nickName << "! Player 2 wins with " << p2->getName() << " " << p2->nickName <<  "!" << endl << endl << endl;
                
                p2->recoverStrength();
                
                string name = p1->nickName;
                LoserNode *l1 = new LoserNode;
                loserList.addFront(l1, name);
                
                player2List.moveToBack();
                player1List.removeFront();
                
                winner = 2;
                break;
            }
        }
        
        
        //This section allows Player 2 to attack first
        else if(firstAttacker == 2)
        {
            p2Attack = p2->attackRoll();
            p1Defend = p1->defenseRoll();
            p2NetAttack = p2Attack - p1Defend;
            
            
            if(p2Attack <= p1Defend)
            {
                p2NetAttack = 0;
            }
            
            
            
            if(p2NetAttack >= p1->getArmor())
            {
                p1UpdatedStrength = p1->getStrength() + p1->getArmor() - p2NetAttack;
                p1->setArmor(0);
                p1->setStrength(p1UpdatedStrength);
            }
            else
            {
                p1UpdateArmor = p1->getArmor() - p2NetAttack;
                p1->setArmor(p1UpdateArmor);
            }
            
            
            
            cout << "Player 2's net attack is " << p2NetAttack << endl;
            cout << "Player 1's remaining strength is " << p1->getStrength() << " and remaining armor is " << p1->getArmor()<< endl << endl;
            
            
            
            if(p1->getStrength() <= 0)
            {
                p1DeathCount++;
                p1->specialAbility(p1DeathCount);
            }
            
            
            if(p1->getStrength() <= 0)
            {
                cout << "Player 1 is dead with " << p1->getName() << " " << p1->nickName <<  "! Player 2 wins with " << p2->getName() << " " << p2->nickName << "!" << endl << endl << endl;
                
                p2->recoverStrength();
                
                string name = p1->nickName;
                LoserNode *l1 = new LoserNode;
                loserList.addFront(l1, name);
                
                player2List.moveToBack();
                player1List.removeFront();
                
                winner = 2;
            

                break;
            }
            
            
            
            
            
            
            
            //Player 1 will now attack
            p1Attack = p1->attackRoll();
            p2Defend = p2->defenseRoll();
            p1NetAttack = p1Attack - p2Defend;
            
            
            if(p1Attack <= p2Defend)
            {
                p1NetAttack = 0;
            }
            
            
            
            if(p1NetAttack >= p2->getArmor())
            {
                p2UpdatedStrength = p2->getStrength() + p2->getArmor() - p1NetAttack;
                p2->setArmor(0);
                p2->setStrength(p2UpdatedStrength);
            }
            else
            {
                p2UpdateArmor = p2->getArmor() - p1NetAttack;
                p2->setArmor(p2UpdateArmor);
            }
            
            
            
            cout << "Player 1's net attack is " << p1NetAttack << endl;
            cout << "Player 2's remaining strength is " << p2->getStrength() << " and remaining armor is " << p2->getArmor() << endl << endl;
            
            
            
            if(p2->getStrength() <= 0)
            {
                p2DeathCount++;
                p2->specialAbility(p2DeathCount);
            }
            
            
            if(p2->getStrength() <= 0)
            {
                cout << "Player 2 is dead with " << p2->getName() << " " << p2->nickName << "! Player 1 wins with " << p1->getName() << " " << p1->nickName << "!" << endl << endl << endl;
                
                p1->recoverStrength();
                
                string name = p2->nickName;
                LoserNode *l1 = new LoserNode;
                loserList.addFront(l1, name);
                
                player1List.moveToBack();
                player2List.removeFront();
                
                winner = 1;

                break;
            }
        }
    }
    
    
    return winner;
}



/*
 Description: This function will update the lists (the two teams and the loser list) after each round is over. It will take an integer representing the winner of the round and two creature pointers representing the creatures that fought in the round. It will not return anything.
 */
void Tournament::updateScore(int winner, Creature *p1, Creature *p2)
{
    if(winner == 1)
    {
        //player1List.moveToBack();
        //player2List.removeFront();
        
        p1WinCount = p1WinCount + 2;
        p2WinCount--;
    }
    else if(winner == 2)
    {
        //player2List.moveToBack();
        //player1List.removeFront();
        
        p2WinCount = p2WinCount + 2;
        p1WinCount--;
    }
    
    cout << "Team 1 remaining characters: " << endl;
    player1List.print();
    cout << endl << endl;
    
    cout << "Team 2 remaining characters: " << endl;
    player2List.print();
    cout << endl << endl;
}


/*
 Description: This function will determine if any of the teams are out of players. If they are the function will return true and end the game since one of the players will have lost. It will return a boolean variable that represents whether or not there's an empty team in the game. It will take no arguments.
 */
bool Tournament::anyEmptyTeams()
{
    bool anythingEmpty;
    
    if(player1List.isEmpty() == true || player2List.isEmpty() == true)
    {
        anythingEmpty = true;
    }
    else
    {
        anythingEmpty = false;
    }
    
    return anythingEmpty;
}


/*
 Description: This function will determine who won the entire game. It will compare the win counts of each team to see whose is higher. There are no arguments and nothing will be returned.
 */
void Tournament::whoWon()
{
    if(p1WinCount > p2WinCount)
    {
        cout << "Player 1 has " << p1WinCount << " points and Player 2 has " << p2WinCount << " points, Player 1 wins!" << endl << endl << endl;
    }
    else if(p2WinCount > p1WinCount)
    {
        cout << "Player 1 has " << p1WinCount << " points and Player 2 has " << p2WinCount << " points, Player 2 wins!" << endl << endl << endl;
    }
    else
    {
        cout << "Player 1 has " << p1WinCount << " points and Player 2 has " << p2WinCount << " points, it's a tie!" << endl << endl << endl;
    }
}


/*
 Description: This function will print out the list of losers in the game. It won't take any arguments or return anything.
 */
void Tournament::printLoserList()
{
    loserList.print();
}



/*
 Description: This function will return the head of player 1's team lineup. It will return a pointer to a creature object that represents the head. No arguments will be taken.
 */
Creature* Tournament::returnP1Head()
{
    Creature *temp;
    temp = player1List.returnHead();
    
    return temp;
}



/*
 Description: This function will return the head of player 2's team lineup. It will return a pointer to a creature object that represents the head. No arguments will be taken.
 */
Creature* Tournament::returnP2Head()
{
    Creature *temp;
    temp = player2List.returnHead();
    
    return temp;
}
