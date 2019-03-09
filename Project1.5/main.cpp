#include <iostream> 
#include <string>
#include <unistd.h>
#include "MenuController.cpp"

#include "CLIController.cpp"

#include "NanoTimer.h"



/*
Input: argc, argument count, total amount of arguments
       argv, argument variables, list of arguments
Output: 0
Description: The main function will process the command line switches, and send the correct repetetion count
            signals to the correct methods..
*/

using namespace std; 




int main(int argc, char* argv[]) 
{  
    for (int i = 0; i < argc; i++)  {
        string example = argv[i];
        if (example == "-cl"){
            CLIController controller;
            controller.paseCommands(argc,argv);
            controller.executeCLI();
            return 0;
        } 
    }
    MenuController controller;
    controller.getFlags();
    return 0; 
};

