/*********************************/





/***********************************/



#include <iostream>
#include "MenuView.cpp"
#include <string>
#include <sstream>
#include <bits/stdc++.h> 
#include "parseCLI.h"
#include <vector>
#include <sstream>

class MenuController : public parseCLI{


    //////////////////////////////////
    // Input: NULL
    // Purpose: gets I/O from menu based view
    // Output: returns the flags parsed to the execute method 
    ////////////////////////////////

    public:void getFlags(){
     
        MenuView mv;
        string test;
        test =  mv.printWelcomeMessage();
       // cout << test;

        std::vector<std::string> v;

        split( test, v, ' ' );

        char* a[v.size()];


        bool processes= false;
        bool threads = false;
        int repetitions = 1;



        for (int i=0;i<v.size();i++)
        {
             /*
                handle the -p/-process flags
            */
            if (v[i] == "-p")
            {
                processes = true;
            } else if (v[i] == "-t")
            {
                threads = true;
            } else if (v[i].find("-r") == 0) {
                 /*
                handle the -rN flag, parse the -rN for the N...
                */
                string example = v[i];
                example.erase(example.begin(),example.begin()+2);
                string rNum = example;
                if (rNum != ""){
                    repetitions = stoi(rNum);
                    
                }
                
            } 

        }
        //cout << "Repetitions: "<<repetitions;
        executeMenu(processes,threads,repetitions);

    }
    ///Input: string1, string 2
    // Purpose: parse a given string by space
    // Output: outputs a vector array of strings 
    size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
    {
        size_t pos = txt.find( ch );
        size_t initialPos = 0;
        strs.clear();

        // Decompose statement
        while( pos != std::string::npos ) {
            strs.push_back( txt.substr( initialPos, pos - initialPos ) );
            initialPos = pos + 1;

            pos = txt.find( ch, initialPos );
        }

        // Add the last one
        strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

        return strs.size();
    }

    // Input: flags for processes, thread, and # of repetitions
    // Purpose: processing flags to executions
    // Output: null, starts fetching of data 
    public:void executeMenu(bool process,bool thread, int repetitions) 
    {

        if (repetitions > 1)
        {  
            
            /*
                Deals when you have the -p/-process switches with the -rN when N is greater then one
                returns to the view the average time 
            */
            if (process) {
          
                MenuView cp;
                processData pd;

                cp.printAverageProcesses(pd.createProcess(repetitions));
   
            }
            /*
                Deals when you have the -t/-thread switches with the -rN when N is greater then one
                returns to the view the average time 
            */
            if (thread) {
                MenuView cp;
                processData pd;

                cp.printAverageThreads(pd.createThreads(repetitions));
   
            }

            
        } else {
            /*
                Deals when you have the -p/-process switches with the -rN when N is equal to one or no N present
                returns to the view the average time 
            */
            if (process) {
       
                MenuView cp;
                processData pd;

                cp.printAverageProcesses(pd.createProcess(1));

                    
            }
            /*
                Deals when you have the -t/-thread switches with the -rN when N is equal to one or no N present
                returns to the view the average time 
            */
            if (thread) {
                MenuView cp;
                processData pd;

                cp.printAverageThreads(pd.createThreads(1));
            }
        }
    }
    
};