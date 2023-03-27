#include "Board.h"

void Board::GenerateObstacle()
{
    srand(time(NULL));
    Position obs_loc;
    
    int x_size = current_board.grid[0].size();
    int y_size = current_board.grid.size();
    
    for(int i = 0; i < y_size; i++)
    {
        obs_loc.y = i; 
        obs_loc.x = rand() % x_size;

        obs_list.push_back(obs_loc);
    }


}

void Board::PlaceObstacle()
{
    int obs_size = obs_list.size();

    for (int i = 0; i < obs_size; i++)
    {
        Position obs = obs_list[i];
        current_board.grid[obs.y][obs.x] = obstacle_symbol;

    }
}

void Board::ClearGrid()
{
    int x_size = current_board.grid[0].size();
    int y_size = current_board.grid.size();

    for (int i = 0; i < y_size; i++)
    {
        for(int j = 0; j < x_size; j++)
        {
            current_board.grid[i][j] = ' ';
        }
    }
}

Board::Board()
{
    ClearGrid();
    GenerateObstacle();
    PlaceObstacle();
}

Grid Board::GetGrid()
{
    Grid temp_board = current_board;

    return temp_board;
}

void Board::ResetGrid()
{
    ClearGrid();
    obs_list.clear();
    GenerateObstacle();
    PlaceObstacle();
}
