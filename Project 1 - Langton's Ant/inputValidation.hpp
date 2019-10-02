/*********************************************************************
 ** Program name: Dice War
 ** Author: John Olgin
 ** Date: 4/24/17
 ** Description: This program will allow two people to play a game of war using dice. There will be a Game class that has two classes within it--Die class and LoadedDie class--and uses them to play the game. The user will be prompted to choose the players' types (loaded or regular) and sizes of die. The user will also choose how many rounds the game lasts. The Game class will iterate through the rounds and compare the players' rolls, ultimately displaying a winner. Die.cpp, Die.hpp, LoadedDie.cpp, LoadedDie.hpp, Game.cpp, Game.hpp, inputValidation.cpp, inputValidation.hpp, and main.cpp need to be in the same directory and compiled together for this program to run correctly.
 *********************************************************************/


#ifndef inputValidation_hpp
#define inputValidation_hpp

#include <stdio.h>

int roundsAndSidesInputVal(int roundsOrSides);

char dieTypeInputVal(char dieType);

int menuChoiceInputVal(int choice);

#endif 
