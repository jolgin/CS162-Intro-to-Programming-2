/*********************************************************************
 ** Program name: Langton's Ant
 ** Author: John Olgin
 ** Date: 4/15/17
 ** Description: This program will ultimately run a simulation of Langton's Ant. As the ant moves (according to the color of the current box) the program will print out the 2D Array for the user to see. The user will be prompted to start or exit the program, input the number of rows/columns, specify starting position if they choose to do so, and choose how many steps they want the program to iterate through. In order to run this program, main.cpp, menuFunction.cpp, menuFunction.hpp, inputValidation.cpp, inputValidation.hpp, Ant.cpp, and Ant.hpp need to be in the same folder and compiled together.
 *********************************************************************/


#ifndef Ant_hpp
#define Ant_hpp

#include <stdio.h>

/*
 Description: The ant class will represent an instance of the ant that moves across the board depending on the direction and color of the cell it enters (Using the rules for Langton's Ant). This class will have member functions and variables that are used to retrieve, store and update information about the ant, such as the ant's current row and column position, the direction it is facing, and the color of the box the ant is entering. Each of these conditions must be updated every time the ant moves to a new cell so it knows what to do next. For example, if the ant moves right into the row 2, column 4 cell and it's black, the setter function setDirection() and direction char variable should be used to update the direction to east. Next, the setCurrentRow() function, setCurrentColumn() function, currentRow integer variable, and currentColumn integer variable should be used to update the ant's new position. Finally, the setBoxColor() function and currentBoxColor char variable should be used to update to black (#) to communicate to the ant that it's in a black square. The corresponding get functions will retrieve what information was last stored in each variable. There will also be a default constructor to initialize all the ant's variables, and a function to actually create the board the ant will be moving on.  
*/
class Ant
{
    
private:
    char currentBoxColor;
    char direction;
    int currentRow, currentColumn;
    
    
public:
    Ant(int row, int column);
    void createBoard(char **new2DArray, int rows, int columns);
    
    void setCurrentRow(int currentRow);
    int getCurrentRow();
    
    void setCurrentColumn(int currentColumn);
    int getCurrentColumn();
    
    void setDirection(char CurrentDirection);
    char getDirection();
    
    void setBoxColor(char currentColor);
    char getBoxColor();
};
#endif /* Ant_hpp */
