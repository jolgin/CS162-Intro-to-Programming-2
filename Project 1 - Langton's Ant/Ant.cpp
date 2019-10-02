/*********************************************************************
 ** Program name: Langton's Ant
 ** Author: John Olgin
 ** Date: 4/15/17
 ** Description: This program will ultimately run a simulation of Langton's Ant. As the ant moves (according to the color of the current box) the program will print out the 2D Array for the user to see. The user will be prompted to start or exit the program, input the number of rows/columns, specify starting position if they choose to do so, and choose how many steps they want the program to iterate through. In order to run this program, main.cpp, menuFunction.cpp, menuFunction.hpp, inputValidation.cpp, inputValidation.hpp, Ant.cpp, and Ant.hpp need to be in the same folder and compiled together.
 *********************************************************************/


#include "Ant.hpp"


/*
 Description: This is the default constructor for the Ant class. It will set the ant's initial box color, direction, row position, and column position. It will take two integers as arguments, one for the row position and one for the column position. Both must initially be determined by the user in the main function before this function is called. This function has no return type.
*/
Ant::Ant(int rowPosition, int columnPosition)
{
    setBoxColor(' ');
    setDirection('W');
    setCurrentRow(rowPosition);
    setCurrentColumn(columnPosition);
}



/*
 Description: This function will initially fill the 2D array using space characters to represent white boxes. It will take 3 arguments, a 2D array of characters, an integer representing the number of rows, and an integer representing the number of columns. The 2d array must be created using dynamic memory allocation in the main function before this function as called. The integers for number of rows and columns also need to initially be determined by the user in the main function before this function is called. It will not return anything.
 */
void Ant::createBoard(char **newMatrix, int numberOfRows, int numberOfColumns)
{
    for(int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            newMatrix[i][j] = ' ';
        }
    }
}



/*
 Description: This function will set the ant's current box color. It will take a character as an argument to represent a white square ( ) or a black square (#). It will not return anything.
 */
void Ant::setBoxColor(char boxColor)
{
    currentBoxColor = boxColor;
}



/*
 Description: This function will return the a char to represent the current color of the box the ant is in
 */
char Ant::getBoxColor()
{
    return currentBoxColor;
}



/*
 Description: This function will set the ant's current direction. It will take a character as an argument to represent north (N), east (E), south (S), and west (W). It will not return anything.
 */
void Ant::setDirection(char currentDirection)
{
    direction = currentDirection;
}



/*
 Description: This function will return a character that represents the ant's current direction.
 */
char Ant::getDirection()
{
    return direction;
}



/*
 Description: This function will set the ant's current row position. It will take an integer argument that represents the specific row the ant is in. It will not return anything.
 */
void Ant::setCurrentRow(int rowCurrent)
{
    currentRow = rowCurrent;
}



/*
 Description: This will return the ant's current row position as an integer.
 */
int Ant::getCurrentRow()
{
    return currentRow;
}



/*
 Description: This function will set the ant's current column position. It will take an integer argument that represents the specific column the ant is in. It will not return anything.
 */
void Ant::setCurrentColumn(int columnCurrent)
{
    currentColumn = columnCurrent;
}



/*
 Description: This will return the ant's current column position as an integer.
 */
int Ant::getCurrentColumn()
{
    return currentColumn;
}


