/********************************************************************* 
 ** Program name: Fight Simulation
 ** Author: John Olgin
 ** Date: 5/14/17
 ** Description: This program will represent a simulation of a battle betwee two types of creatures selected by two different players. The players' attacka and defense actions are determined by dice rolls. Each creature will have a differnt amount and size of die, a different name, and a different level of strength an armor. Additionally, each creature has a different special ability. The players will battle(roll) until one of them has no more strength left to fight. Each player will be prompted to choose a creature type and the game will start and run through the game until finished. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, and inputValidation.cpp.
 *********************************************************************/

#include <iostream>
#include "menuFunction.hpp"
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "HarryPotter.hpp"
using namespace std;

int main()
{
    Creature *p1, *p2;
    int menuChoice, firstAttacker, p1DeathCount = 0, p2DeathCount = 0;
    
    menuChoice = menuFunction();
    srand((int)time(0));
    
    
    while(menuChoice != 2)
    {
        int p1Type = player1List();
        int p2Type = player2List();
        
        //Create a new object depending on the user's choice for Player 1
        if(p1Type == 1)
        {
            p1 = new Vampire;
        }
        else if(p1Type == 2)
        {
            p1 = new Barbarian;
        }
        else if(p1Type == 3)
        {
            p1 = new BlueMen;
        }
        else if(p1Type == 4)
        {
            p1 = new Medusa;
        }
        else if(p1Type == 5)
        {
            p1 = new HarryPotter;
        }
        
        
        //Create a new object depending on the user's choice for Player 2
        if(p2Type == 1)
        {
            p2 = new Vampire;
        }
        else if(p2Type == 2)
        {
            p2 = new Barbarian;
        }
        else if(p2Type == 3)
        {
            p2 = new BlueMen;
        }
        else if(p2Type == 4)
        {
            p2 = new Medusa;
        }
        else if(p2Type == 5)
        {
            p2 = new HarryPotter;
        }
        
        //Output the players' characters' initial stats
        cout << "Player 1's starting strength is " << p1->getStrength() << " and armor is " << p1->getArmor() << endl;
        cout << "Player 2's starting strength is " << p2->getStrength() << " and armor is " << p2->getArmor() << endl << endl << endl;
        
        //Determine who will attack first
        firstAttacker = rand() % 2 + 1;
        cout << "Player " << firstAttacker << " will attack first." << endl << endl << endl;
        
        
        int roundCount = 0;
        
        //Begin the game loop
        while(p1->getStrength() > 0 && p2->getStrength() > 0)
        {
            int p1Attack, p2Attack, p1Defend, p2Defend, p1NetAttack, p2NetAttack, p1UpdatedStrength, p2UpdatedStrength;
            int p1UpdateArmor, p2UpdateArmor;
            
            cout << "Round " << ++roundCount << endl << endl;

            
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
                    cout << "Player 2 is dead! Player 1 wins with " << p1->getName() << "." << endl << endl << endl;
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
                    cout << "Player 1 is dead! Player 2 wins with " << p2->getName() << "." << endl;
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
                    cout << "Player 1 is dead! Player 2 wins with " << p2->getName() << "." << endl;
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
                    cout << "Player 2 is dead! Player 1 wins with " << p1->getName() << "." << endl << endl << endl;
                    break;
                }
            }
        }

        
        
        menuChoice = menuFunction();
    }
    
    if(menuChoice == 2)
    {
        delete p1;
        delete p2;
        cout << "Bye!" << endl;
    }
}
