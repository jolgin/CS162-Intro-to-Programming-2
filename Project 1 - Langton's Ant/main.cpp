/*********************************************************************
 ** Program name: Langton's Ant
 ** Author: John Olgin
 ** Date: 4/15/17
 ** Description: This program will ultimately run a simulation of Langton's Ant. As the ant moves (according to the color of the current box) the program will print out the 2D Array for the user to see. The user will be prompted to start or exit the program, input the number of rows/columns, specify starting position if they choose to do so, and choose how many steps they want the program to iterate through. In order to run this program, main.cpp, menuFunction.cpp, menuFunction.hpp, inputValidation.cpp, inputValidation.hpp, Ant.cpp, and Ant.hpp need to be in the same folder and compiled together.
 *********************************************************************/


#include <iostream>
#include "menuFunction.hpp"
#include "Ant.hpp"
#include "inputValidation.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int userOption;
    
    //This will call menuFunction to ask the user if they want to start/exit the program.
    userOption = menuFunction();
    
    
    //This will run the program if the user selects 1
    if(userOption == 1)
    {
        int rows, columns;
        int positionStartChoice;
        int rowPosition, columnPosition, userEnteredRowPosition, userEnteredColumnPosition;
        
        
        //Prompt the user for number of rows/columns and call functions for input validation.
        cout << "Please enter the number of rows between 1 and 30, including end values: " << endl;
        cin >> rows;
        
        rows = rowsAndColumnsInVal(rows);
        
        cout << "Please enter the number of columns between 1 and 30, including end values: " << endl;
        cin >> columns;
        
        columns = rowsAndColumnsInVal(columns);
        
        
        
        
        
        
        //Ask the user to choose start position or randomize, input validate as well.
        cout << "Do you want to enter a starting position for the ant? Please enter (1) for yes or (2) for no (If no, it will be random)." << endl;
        cin >> positionStartChoice;
        
        positionStartChoice = positionStartInVal(positionStartChoice);
       
        
        //If user selects (1) yes, prompt the user to enter the row/column for start position and validate input
        if (positionStartChoice == 1)
        {
            cout << "Enter an integer for starting row between 1 and " << rows << "." << endl;
            cin >> userEnteredRowPosition;
            rowPosition = rowPositionInVal(userEnteredRowPosition, rows) - 1;
            
            cout << "Enter an integer for starting column between 1 and " << columns << "." << endl;
            cin >> userEnteredColumnPosition;
            columnPosition = columnPositionInVal(userEnteredColumnPosition, columns) - 1;
            
            cout << "The ant will start at row " << rowPosition+1 << ", column " << columnPosition+1 << ", facing west." << endl;
            cout << "This program assumes the first row and first column in the array are labeled 1." << endl << endl;
        }
        
        //If user selects (2) no, randomize the starting row/column
        else if (positionStartChoice == 2)
        {
            srand((unsigned)time(0));
            rowPosition = (rand()% rows);
            columnPosition = (rand()% columns);
            
            cout << "The ant will start at row " << rowPosition+1 << ", column " << columnPosition+1 << ", facing west." << endl;
            cout << "This program assumes the first row and first column in the array are labeled 1." << endl << endl;
        }
        
        
        
        
        
        
        //Ask user how many steps to run and validate input
        int userStepsSelected;
        cout << "How many steps do you want the ant to take?" << endl;
        cin >> userStepsSelected;
        
        userStepsSelected = numberOfStepsInVal(userStepsSelected);
        cout << endl << endl;
        
        
        
        
        
        //Instantiate a new Ant object
        Ant newLangtonAnt(rowPosition, columnPosition);
        
        
        //Create and dynamically allocate a new 2D array
        char **newMatrix = new char *[rows];
        for (int i = 0; i < rows; i++)
        {
            newMatrix[i] = new char[columns];
        }
        
        
        
        
        //Call function to fill the 2D array and put the ant in starting position
        newLangtonAnt.createBoard(newMatrix, rows, columns);
        newMatrix[rowPosition][columnPosition] = '@';
        
        
        
        
        //Print the 2D array
        for(int counterRow = 0; counterRow < rows; counterRow++)
        {
            for(int counterColumn = 0; counterColumn < columns; counterColumn++)
            {
                cout << newMatrix[counterRow][counterColumn];
                cout << " ";
            }
            
            cout << endl;
        }
        cout << endl;
        
        
        
        int stepsTaken = 0;
        
        while (stepsTaken < userStepsSelected)
        {
            
            /* To prevent the code from becoming too clustered and to maintain readability, only the first if statement will have explanatory comments. Note that the remaining 7 else if statements follow the exact same process. As a whole, the entire if-else if statement will control where the ant goes and the direction it faces. Also, it will control the box color of the ant's former position and set up for the next iteration.
            */
            if (newLangtonAnt.getBoxColor() == '#' && newLangtonAnt.getDirection() == 'N')
            {
                //Make the current position the opposite color
                newMatrix[rowPosition][columnPosition] = ' ';
                
                
                
                //Update the row/column and wrap ant to opposite side of the board if it steps out of bounds
                columnPosition = newLangtonAnt.getCurrentColumn() + 1;
                
                if(columnPosition >= columns)
                {
                    columnPosition = 0;
                }
                
                if(columnPosition < 0)
                {
                    columnPosition = columns - 1;
                }
                
                //Call the set column/row function to set it according to the updated column/row
                newLangtonAnt.setCurrentColumn(columnPosition);
                
                
                
                //Use updated position to update the color that tells the ant where to go in the next iteration
                if (newMatrix[newLangtonAnt.getCurrentRow()][newLangtonAnt.getCurrentColumn()] == ' ')
                {
                    newLangtonAnt.setBoxColor(' ');
                }
                else
                {
                    newLangtonAnt.setBoxColor('#');
                }
                
                
                
                //Update the ant's direction for next iteration
                newLangtonAnt.setDirection('E');
            }
                
                
            else if(newLangtonAnt.getBoxColor() == '#' && newLangtonAnt.getDirection() == 'E')
            {
                newMatrix[rowPosition][columnPosition] = ' ';
                
                
                
                rowPosition = newLangtonAnt.getCurrentRow() - 1;
                
                if(rowPosition >= rows)
                {
                    rowPosition = 0;
                }
                if(rowPosition < 0)
                {
                    rowPosition = rows - 1;
                }
                
                newLangtonAnt.setCurrentRow(rowPosition);
                
                
                
                if (newMatrix[newLangtonAnt.getCurrentRow()][newLangtonAnt.getCurrentColumn()] == ' ')
                {
                    newLangtonAnt.setBoxColor(' ');
                }
                else
                {
                    newLangtonAnt.setBoxColor('#');
                }
                
                
                
                newLangtonAnt.setDirection('S');
            }
                
                
            else if(newLangtonAnt.getBoxColor() == '#' && newLangtonAnt.getDirection() == 'S')
            {
                newMatrix[rowPosition][columnPosition] = ' ';

                
                
                columnPosition = newLangtonAnt.getCurrentColumn() - 1;
                
                if(columnPosition >= columns)
                {
                    columnPosition = 0;
                }
                
                if(columnPosition < 0)
                {
                    columnPosition = columns - 1;
                }
                        
                newLangtonAnt.setCurrentColumn(columnPosition);
                
                
                
                if (newMatrix[newLangtonAnt.getCurrentRow()][newLangtonAnt.getCurrentColumn()] == ' ')
                {
                    newLangtonAnt.setBoxColor(' ');
                }
                else
                {
                    newLangtonAnt.setBoxColor('#');
                }
                
                
                
                newLangtonAnt.setDirection('W');
            }
                
                
            else if(newLangtonAnt.getBoxColor() == '#' && newLangtonAnt.getDirection() == 'W')
            {
                newMatrix[rowPosition][columnPosition] = ' ';

                
                
                rowPosition = newLangtonAnt.getCurrentRow() + 1;
                
                if(rowPosition >= rows)
                {
                    rowPosition = 0;
                }
                if(rowPosition < 0)
                {
                    rowPosition = rows - 1;
                }
                    
                newLangtonAnt.setCurrentRow(rowPosition);
                
                
                
                if (newMatrix[newLangtonAnt.getCurrentRow()][newLangtonAnt.getCurrentColumn()] == ' ')
                {
                    newLangtonAnt.setBoxColor(' ');
                }
                else
                {
                    newLangtonAnt.setBoxColor('#');
                }
                
                
                
                newLangtonAnt.setDirection('N');
            }
            
            
            
            
            else if(newLangtonAnt.getBoxColor() == ' ' && newLangtonAnt.getDirection() == 'N')
            {
                newMatrix[rowPosition][columnPosition] = '#';

                
                
                columnPosition = newLangtonAnt.getCurrentColumn() - 1;
                
                if(columnPosition >= columns)
                {
                    columnPosition = 0;
                }
                
                if(columnPosition < 0)
                {
                    columnPosition = columns - 1;
                }
                    
                newLangtonAnt.setCurrentColumn(columnPosition);
                
                
                
                if (newMatrix[newLangtonAnt.getCurrentRow()][newLangtonAnt.getCurrentColumn()] == ' ')
                {
                    newLangtonAnt.setBoxColor(' ');
                }
                else
                {
                    newLangtonAnt.setBoxColor('#');
                }
                
                
                
                newLangtonAnt.setDirection('W');
            }

            
            else if(newLangtonAnt.getBoxColor() == ' ' && newLangtonAnt.getDirection() == 'W')
            {
                newMatrix[rowPosition][columnPosition] = '#';

            
                
                rowPosition = newLangtonAnt.getCurrentRow() - 1;
                
                if(rowPosition >= rows)
                {
                    rowPosition = 0;
                }
                if(rowPosition < 0)
                {
                    rowPosition = rows - 1;
                }
                    
                newLangtonAnt.setCurrentRow(rowPosition);

                
                
                if (newMatrix[newLangtonAnt.getCurrentRow()][newLangtonAnt.getCurrentColumn()] == ' ')
                {
                    newLangtonAnt.setBoxColor(' ');
                }
                else
                {
                    newLangtonAnt.setBoxColor('#');
                }
                
                
                
                newLangtonAnt.setDirection('S');
            }
            
            
            else if(newLangtonAnt.getBoxColor() == ' ' && newLangtonAnt.getDirection() == 'S')
            {
                newMatrix[rowPosition][columnPosition] = '#';

                
                
                columnPosition = newLangtonAnt.getCurrentColumn() + 1;
                
                if(columnPosition >= columns)
                {
                    columnPosition = 0;
                }
                
                if(columnPosition < 0)
                {
                    columnPosition = columns - 1;
                }
                    
                newLangtonAnt.setCurrentColumn(columnPosition);
                
                
                
                if (newMatrix[newLangtonAnt.getCurrentRow()][newLangtonAnt.getCurrentColumn()] == ' ')
                {
                    newLangtonAnt.setBoxColor(' ');
                }
                else
                {
                    newLangtonAnt.setBoxColor('#');
                }
                
                
                
                newLangtonAnt.setDirection('E');
            }
            
            
            else if(newLangtonAnt.getBoxColor() == ' ' && newLangtonAnt.getDirection() == 'E')
            {
                newMatrix[rowPosition][columnPosition] = '#';

                
                
                rowPosition = newLangtonAnt.getCurrentRow() + 1;
                
                if(rowPosition >= rows)
                {
                    rowPosition = 0;
                }
                if(rowPosition < 0)
                {
                    rowPosition = rows - 1;
                }
                    
                newLangtonAnt.setCurrentRow(rowPosition);
                
                
                
                if (newMatrix[newLangtonAnt.getCurrentRow()][newLangtonAnt.getCurrentColumn()] == ' ')
                {
                    newLangtonAnt.setBoxColor(' ');
                }
                else
                {
                    newLangtonAnt.setBoxColor('#');
                }
                
                
                
                newLangtonAnt.setDirection('N');
            }
            
            
            //This will place the ant in the updated position
            newMatrix[newLangtonAnt.getCurrentRow()][newLangtonAnt.getCurrentColumn()] = '@';

            
            //Print the 2D array
            for(int counterRow = 0; counterRow < rows; counterRow++)
            {
                for(int counterColumn = 0; counterColumn < columns; counterColumn++)
                {
                    cout << newMatrix[counterRow][counterColumn];
                    cout << " ";
                }
                
                cout << endl;
            }
            
            
            stepsTaken++;
            
            cout << endl << endl;
        }
        
        
        //Free up the space from the dynamically allocated 2D array
        for (int i = 0; i < rows; i++)
        {
            delete [] newMatrix[i];
        }
        delete [] newMatrix;
        
    }
    
    //Exit the program if the user chooses two in menuFunction
    else if(userOption == 2)
    {
        cout << "Bye!" << endl;
    }
        
    return 0;
}
        
    
    
    
    
    
    
