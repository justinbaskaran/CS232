#ifndef __CLIVIEWCONTROLLER_H__
#define __CLIVIEWCONTROLLER_H__

#include <iostream> 
#include <string>
#include <list>
#include "processData.cpp"
#include <unistd.h>
#include <pthread.h>
#include "CLIView.cpp"
#include "parseCLI.h"


using namespace std; 


class CLIController : public parseCLI{
    





   public:void executeCLI() 
    {
        //cout << "Number Repetitions: " << parseCLI::repetitions;
        if (parseCLI::repetitions > 1)
        {  
            
            /*
                Deals when you have the -p/-process switches with the -rN when N is greater then one
                returns to the view the average time 
            */
            if (parseCLI::process) {
          
                CLIView cp;
                processData pd;

                cp.printAverageProcesses(pd.createProcess(parseCLI::repetitions));
   
            }
            /*
                Deals when you have the -t/-thread switches with the -rN when N is greater then one
                returns to the view the average time 
            */
            if (parseCLI::thread) {
                CLIView cp;
                processData pd;

                cp.printAverageThreads(pd.createThreads(parseCLI::repetitions));
   
            }

            
        } else {
            /*
                Deals when you have the -p/-process switches with the -rN when N is equal to one or no N present
                returns to the view the average time 
            */
            if (parseCLI::process) {
       
                CLIView cp;
                processData pd;

                cp.printAverageProcesses(pd.createProcess(1));

                    
            }
            /*
                Deals when you have the -t/-thread switches with the -rN when N is equal to one or no N present
                returns to the view the average time 
            */
            if (parseCLI::thread) {
                CLIView cp;
                processData pd;

                cp.printAverageThreads(pd.createThreads(1));
            }
        }
    }

 
};


#endif


    
