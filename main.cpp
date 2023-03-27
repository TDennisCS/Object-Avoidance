#include "Simulation.h"


int main()
{
    Simulation sim; //creates the simulation.  
    
    bool dont_terminate = true; // breaks the do-while loop by changing to false. 
    
    char user_input; // grabs the user input after the menu is called.

    do // beginning of simulation. 
    {
        sim.Menu(); // asks; 1 for run || 0 for exit
        
        cin >> user_input; // user input grabbed.

        if (user_input == '1') // if 1, runs the sim 
        {
            sim.Run(); // runs the sim
            sim.FirstDisplay(); // displays first location of the agent
            sim.FinalDisplay(); // displays last loc of the agent
            sim.Restart(); // restarts the sim
        }
        else if (user_input == '0') // if 0, exits the sim
        {
            dont_terminate = false; // breaks loop. 
        }
        else // if input is not 1 or 0 then it loops back to the menu. 
        {
            cout << "Invalid Input" << endl; // message
        }

    } while (dont_terminate); // end of simulation  

    return 0; 
}