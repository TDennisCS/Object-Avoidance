#include "Simulation.h"


void Simulation::Menu()
{
    system("cls");

    cout << "Run    (1)" << endl;
    cout << "Exit   (0)" << endl;

    cout << "Insert Action: ";
}

void Simulation::Run()
{
    system("cls");

    bool not_done = true;

    do
    {
        if (a.Progress() == false) // agent has not reached the end or is stuck
        {
            a.Move(); // moves agent one space. 

        }
        else // if agent is done then ends loop. 
        {
            not_done = false; // breaks loop.
        }
        
        cout << "running.." << endl; // troubleshooting. 

    } while (not_done); // ends run condition. 
}

void Simulation::Restart() // resets the sim 
{
    b.ResetGrid(); // resets the grid 
    a.Reset(); // resets the agent 
}

void Simulation::FinalDisplay()
{
    Position finish = a.Finish();
    display_vector[finish.y][finish.x] = a.ShowSymbol();
}

void Simulation::FirstDisplay()
{
    Position start = a.Start();
    display_vector[start.y][start.x] = a.ShowSymbol();
}

void Simulation::Display()
{
    Position B1, B2, B3, B4; // boards of the display
    Grid temp_grid = b.GetGrid();
    int grid_max_y = temp_grid.grid.size();
    int grid_max_x = temp_grid.grid[0].size();
    vector <vector <char>> display; 

    //B1
    B1.x = 0;
    B1.y = 0; 

    //B2
    B2.x = grid_max_x + 2;
    B2.y = 0;

    //B3
    B3.x = 0;
    B3.y = grid_max_y + 2;

    //B4 
    B4.x = grid_max_x + 2;
    B4.y = grid_max_y + 2; 

    for(int i = 0; i < (B4.x + 1); i++)
    {
        for(int j = 0; j < (B4.y + 1); j++)
        {
            if (i == 0 || i == B4.x || j == 0 || j == B4.y)
            {
                if (i == 0 && j != 0 && i != B4.x && j != B4.y)
                {
                    display[i][j] = '|';
                }
                else if (i != 0 && j == 0 && i != B4.x && j != B4.y)
                {
                    display[i][j] = '-';
                }
                else if (i != 0 && j != 0 && i == B4.x && j != B4.y)
                {
                    display[i][j] = '|';
                }
                else if (i != 0 && j != 0 && i != B4.x && j == B4.y)
                {
                    display[i][j] = '-';
                }
                else
                {
                    display[i][j] = '-';
                }
            }
            else
            {
                display[i][j] = temp_grid.grid[i-1][j-1];
            }
        }
        
    }

    display_vector = display;

}
