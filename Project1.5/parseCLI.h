#ifndef __PARSECLI_H__
#define __PARSECLI_H__

#include <unistd.h>
#include <pthread.h>
#include <iostream> 
#include <string>
#include <list>

using namespace std; 


class parseCLI{

    public:bool rN= false;

    public:bool process = false;

    public:bool thread = false;

    public:int repetitions=1;



    public:void paseCommands(int argc, char* argv[]) 
    { 

        list <string> list;

        for (int i = 0; i < argc; i++)  {
            string example = argv[i];

           // cout << "Arugment: " <<  example;
            list.push_back(example);

            
            /*
                handle the -p/-process flags
            */
            if (example == "-p" || example == "-process") {
                process = true;
                list.pop_back();
            }
            /*
                handle the -t/-thread flags
            */
            if (example == "-t" || example == "-thread") {
                thread = true;
                list.pop_back();
            }
             /*
                handle the -cL flag (already passed)
            */
            if (example == "-cl") {
                list.pop_back();
            }
            /*
                handle the -rN flag, parse the -rN for the N...
            */
            if (example.find("-r") == 0) {
                example.erase(example.begin(),example.begin()+2);
                string rNum = example;
                if (rNum != ""){
                    repetitions = stoi(rNum);
                // cout << "Repetitions: "<<repetitions;
                    list.pop_back();
                }
                
            }
            /*
                handles invalid arguments
            */
            if (argc - i == 1)
            {
                if (list.size() > 1)
                {
                list.pop_front();
                    std::list<string>::iterator it;
                
                    for (it = list.begin(); it!= list.end(); ++it)
                    {
                    
                        cout << "Invalid Argument Detected, ignoring: " << *it << "\n";
                
                    }
                }
            }

        }
      
    }
 



};

#endif
