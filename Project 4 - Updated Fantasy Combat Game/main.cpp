/*********************************************************************
 ** Program name: Team Fight Simulation
 ** Author: John Olgin
 ** Date: 5/28/17
 ** Description: This program will be a battle simulation between two teams of creatures. The players will be able to choose from 5 characters to fill their team. The characters will battle until one team is out of players and then a score will be tallied to decide who the winner is. The losing character in each battle will be removed from the team, and the winner will go to the back of the queue of the player's team. To run this program each of the following files need to be in the same directory and compiled together: main.cpp, creature.hpp, creature.cpp, Barbarian.cpp, Barbarian.hpp, BlueMen.hpp, BlueMen.cpp, Medusa.cpp, Medusa.hpp, Vampire.cpp, Vampire.hpp, HarryPotter.hpp, HarryPotter.cpp, menuFunction.cpp, MenuFunction.hpp, inputValidation.hpp, inputValidation.cpp, CreatureQueue.cpp, CreatureQueue.hpp, Tournament.hpp, Tournament.cpp, LoserNode.cpp, LoserNode.hpp, LoserQueue.hpp, and LoserQueue.cpp.
 *********************************************************************/

#include <iostream>
#include "CreatureQueue.hpp"
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Vampire.hpp"
#include "Medusa.hpp"
#include "menuFunction.hpp"
#include "Tournament.hpp"
#include "inputValidation.hpp"
#include "LoserQueue.hpp"
using namespace std;

int main()
{
    int menuChoice, teamSize, creatureChoice, winner, round = 0;
    Tournament game;
    string nickName;
    Creature *p1, *p2;
    menuChoice = menuFunction();
    
    while(menuChoice != 3)
    {
        if(menuChoice == 1)
        {
            cout << "How many characters per team (At least 3 but less than 10)?" << endl;
            cin >> teamSize;
            teamSize = teamSizeValidation(teamSize);
            
            
            cout << "Please fill Player 1's team!" << endl;
            //For player 1
            for(int i = 0; i < teamSize; i++)
            {
                creatureChoice = player1List();
                
                //Create a new object depending on the user's choice for Player 1
                if(creatureChoice == 1)
                {
                    p1 = new Vampire;
                }
                else if(creatureChoice == 2)
                {
                    p1 = new Barbarian;
                }
                else if(creatureChoice == 3)
                {
                    p1 = new BlueMen;
                }
                else if(creatureChoice == 4)
                {
                    p1 = new Medusa;
                }
                else if(creatureChoice == 5)
                {
                    p1 = new HarryPotter;
                }
                
                cin.clear();
                cin.ignore();
                cout << "Please enter this character's nickname: " << endl;
                getline(cin, nickName);
                
                nickName = nameValidation(nickName);
                
                game.fillP1List(p1, nickName);
            }
            
            
            cout << "Now please fill Player 2's team!" << endl;
            //For Player 2
            for(int i = 0; i < teamSize; i++)
            {
                creatureChoice = player2List();
                
                //Create a new object depending on the user's choice for Player 2
                if(creatureChoice == 1)
                {
                    p2 = new Vampire;
                }
                else if(creatureChoice == 2)
                {
                    p2 = new Barbarian;
                }
                else if(creatureChoice == 3)
                {
                    p2 = new BlueMen;
                }
                else if(creatureChoice == 4)
                {
                    p2 = new Medusa;
                }
                else if(creatureChoice == 5)
                {
                    p2 = new HarryPotter;
                }
                
                cin.clear();
                cin.ignore();
                cout << "Please enter this character's nickname: " << endl;
                getline(cin, nickName);
                
                nickName = nameValidation(nickName);
                
                game.fillP2List(p2, nickName);
            }
            
            
            while(game.anyEmptyTeams() != true)
            {
                round++;
                
                cout << "Round " << round << endl << endl;
                winner = game.fight();
                
                
                game.updateScore(winner, p1, p2);
            }
            
        }
        else if(menuChoice == 2)
        {
            game.printLoserList();
        }
        
        game.whoWon();
        menuChoice = menuFunction();
    }
    
    if(menuChoice == 3)
    {
        game.~Tournament();
        
        cout << "Exiting program" << endl;
    }
}
