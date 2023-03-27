#include "Agent.h"

Agent::Agent(char new_symbol, Board* new_board)
{
    symbol = new_symbol;
    current_board = new_board;
    current_location.x = 0;
    current_location.y = 0;
}


Position Agent::Up()
{
    Position up_move;
        up_move.y = current_location.y + 1;
        up_move.x = current_location.x;  
    return up_move;
}

Position Agent::Down()
{
    Position temp_move;
        temp_move.y = current_location.y - 1;
        temp_move.x = current_location.x;  
    return temp_move;
}

Position Agent::Left()
{
    Position temp_move;
        temp_move.y = current_location.y;
        temp_move.x = current_location.x - 1;  
    return temp_move;
}

Position Agent::Right()
{
    Position temp_move;
        temp_move.y = current_location.y;
        temp_move.x = current_location.x + 1;  
    return temp_move;
}

bool Agent::LegalMove(Position new_location)
{
    bool legal;
    Grid temp_board = current_board->GetGrid();
    char loc = temp_board.grid[new_location.y][new_location.x];
    if (loc !=' ')
    {
        legal = true;
    }
    return legal;
}

vector<bool> Agent::Look()
{
   vector <bool> possible_moves;
   vector <Position> possible_positions;

   possible_positions[0] = Up();
   possible_positions[1] = Right();
   possible_positions[2] = Down();
   possible_positions[3] = Left();

   for(int i = 0; i < 4; i++)
   {
        possible_moves[i]=LegalMove(possible_positions[i]);
   }

    return possible_moves;
}

void Agent::Leap(Position new_location)
{
    current_location = new_location;
    path.push_back(new_location);
}

Position Agent::Locate()
{
    Position loc;
    loc = current_location;
    return loc;

}

Position Agent::Backtrack()
{
    Position backwards_movement;

    backwards_movement = path.back();

    return backwards_movement;
}

char Agent::ShowSymbol()
{
    char current_symbol;
    current_symbol = symbol;
    return current_symbol; 
}

void Agent::ChangeSymbol(char new_symbol)
{
    symbol = new_symbol;

}

void Agent::Move()
{
    srand(time(NULL));
    vector<Position> current_path = path;
    vector<Position> possible_positions;
    possible_positions[0] = Up();
    possible_positions[1] = Right();
    possible_positions[2] = Down();
    possible_positions[3] = Left();
    vector<bool> possible_moves = Look();
    bool loop_condition = true;
    int choice;
    Grid temp_grid = current_board->GetGrid();
    int grid_max_y = temp_grid.grid.size();
    int grid_max_x = temp_grid.grid[0].size();

    if (current_location.y == 0)
    {
        possible_moves[2] = false;
    }
    
    if (current_location.x == 0)
    {
        possible_moves[3] = false;
    }

    if (current_location.x == grid_max_x)
    {
        possible_moves[1] = false;
    }
    


    do
    {
        choice = rand() % 4; //picks a number between 0 - 3
        if (possible_moves[choice] == true) // checks if its a legal move 
        {
            loop_condition = false; 
        }
    } while (loop_condition);
    
    Leap(possible_positions[choice]);


    

}

bool Agent::Progress()
{
    bool at_end = false;
    Position loc = current_location;
    int y_max = current_board->GetGrid().grid.size();
    if(loc.y == y_max)
    {
        at_end = true; 
  
    }
    return at_end;
}

void Agent::Reset(Board *new_board)
{
    
    current_board = new_board;
    path.clear();
    current_location.x = 0;
    current_location.y = 0;

}

Position Agent::Start()
{
    Position starting_position;
    starting_position = path.front();
    return starting_position; 
    
}

Position Agent::Finish()
{
    Position Finish_position;
    Finish_position = path.back();
    return; 
}
