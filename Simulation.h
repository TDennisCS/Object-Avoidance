#include <iostream> 
#include <stdlib.h>
#include "Agent.h"

using namespace std; 

class Simulation
{
private:
    Agent a; // agent that is used in the simulation
    Board b; // board that the agent is moving thru
    vector <vector <char>> display_vector;

    void Display();

public:
    
    void Menu(); // Displays the Menu for the sim
    void Run(); // Runs the simluation. 
    void Restart(); // Restarts the simluation. 
    void FinalDisplay(); // Display the final location of the agent. 
    void FirstDisplay();  // Displays the first location of the agent. 
};

