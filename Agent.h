#include <iostream>
#include <vector>
#include "Board.h"

using namespace std;



class Agent
{
private:
    vector <Position> path; // all the movements that the agent took. 
    Board *current_board; // A pointer to the board instance. 
    Position current_location; // the location of the agent on the board. 
    char symbol; // the graphic used on the board. 
    
    Position Up(); // Moves the agent up and adds  'u' to direction  
    Position Down(); // Moves the agent down and adds 'd' to direction
    Position Left(); // Moves the agent to the left and adds 'l' to direction
    Position Right(); // Moves the agent to the right and adds 'r' to direction
    bool LegalMove(Position new_location); // checks for an obstacle 
    vector<bool> Look(); // checks board for possible movements 
    void Leap (Position new_location); // moves the agent and updates the current_location
    Position Locate(); // gives the current location of the agent
    Position Backtrack(); // moves the agent to a previous location.
     // changes the symbol used for agent.  
    
    


public:
    Agent(char new_symbol, Board* new_board); // constructor that grabs the symbol used for the agent. 
    void Move();
    bool Progress();
    void Reset(Board* new_board);
    Position Start();
    Position Finish();
    char ShowSymbol(); // shows the symbol for agent. 
    void ChangeSymbol(char new_symbol);
    
};

// 0 - up, 1 - right, 2 - down, 3 - left