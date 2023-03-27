#include<iostream>
#include<array>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>



using namespace std; 

struct Position
{
    int x; // the column value 
    int y; // the row value 
};

struct Grid
{
    array<array<char, 17>, 15> grid; // the grid 
};

class Board
{
private:
    Grid current_board;  // current board in this instance. 
    char obstacle_symbol = 'x'; // symbol used for obstacles. 
    vector<Position> obs_list; // list of the positions of all the obstacles on the board.

    void GenerateObstacle();
    void PlaceObstacle(); // adds a random 'x' value to each row on the board. 
    void ClearGrid(); //clears all the values in current_board and replaces them with ' '. 

    
public:
    Board();
    Grid GetGrid(); //returns a copy of the grid
    void ResetGrid(); // resets the grid 


};

