/*
Name: Justin Baskaran
Class: CS 232 Operating System and Networking 
Project 1
Professor: Dr. Adams

callTimer.cpp is a c++ program that lets you create Threads, and create process in for loops...
 To illustrate:

  callTimer -p 
  callTimer -process

should each display the time required to create a process, while

  callTimer -t
  callTimer -thread

should each display the time required to create a thread, and

  callTimer -r100 -p -t
  callTimer -process -r100 -thread
  callTimer -p -thread -r100
  callTimer -r100 -t -process

*/

#include <iostream> 
#include <string>
#include "NanoTimer.h"
#include <unistd.h>
#include <list>
#include <sys/wait.h>
#include <pthread.h>

using namespace std; 

bool rN= false;

bool process = false;

bool thread = false;

int repetitions=1;

/*
Input: repetitions, default value is 1, unless -rN is specified in the command line arguments
Output: average time, which is total time divided by total repetitions
Description: creates as many processes as specified by the input parameter
*/
string createProcess(int repetitions){
    double total=0.000000000000;
    
    // NanoTimer class provided by Dr.Adams, in project specifications
    NanoTimer nt;
  
    int run;
    for (run=0; run<repetitions; run++)
    {  
        // Starts Timer
        nt.start();

        // Fork command sent
        pid_t pid = fork();

        // Stops Timer
        nt.stop();

        // Adds current Timer value to total 
        total = total +  nt.asDouble();

        // Resets Timer 
        nt.reset();

        // If pid value of fork() is greater then 0, then fork failed!
        if (pid <0)
        {
            cout<< "\n" << "fork() failed!" << " )" ;
        }

        // if pid of fork() is 0 then fork is a child!
        if (pid == 0)
        {
            cout<< "\n"<< "Hello From Child Process(PID = "<< getpid() << ")" << "\n";
           // cout << "\n" <<  "Process"<<nt.asDouble() << "\n";
            // times.push_back(nt.asDouble());
            
            // Exits current child process
            exit(0);
            

        }

    } 

    // get rid of the exited processes from the system 
    while(wait(&run)>=0); 

    // return total summation of times divided by total repetitions
    return to_string(total/repetitions);

}
/*
Input: pointer to integer value of pthread 
Output: none
Description: Outputs, a child thread message, and deltes the current pointer, to perseve
space....
*/
void *createThreadsString(void* ptr){
    int id = *(int*)ptr;
    cout << "\n"<< "Hello from the child thread (TID = " << id << ")";
    delete (int*)ptr;
}
/*
Input: repetitions, default value is 0, if -rN is specifeid, N value is taken
Output: average time, which is total time divided by total repetitions
Description: creates as many threads as specified by the input parameter
*/
string createThreads(int repetitions){
    double total=0.00000000;
    int i=0;
    
    //array of pthread_ts
    pthread_t threads[repetitions];
    
    // NanoTimer class provided by Dr.Adams, in project specifications
    NanoTimer nt;
    for(i=0;i<repetitions;i++){
        // Starts Timer
        nt.start();
        
        // Creates Thread &threads[i] and immediately starts createThreadsString
        // with arguments newInt(i)...
        pthread_create(&threads[i], NULL,&createThreadsString,(new int(i)));

        // Ends Timer 
        nt.stop();
        
        // Adds nano timer value to running total
        total = total + nt.asDouble();
        
        // Resets Timer
        nt.reset();

        //joins thread to existing thread (ie one from the array of threads )
        pthread_join(threads[i],NULL);     
    }
    
    // return total summation of times divided by total repetitions
    return to_string(total/repetitions);

}
/*
Input: argc, argument count, total amount of arguments
       argv, argument variables, list of arguments
Output: 0
Description: The main function will process the command line switches, and send the correct repetetion count
            signals to the correct methods..
*/
int main(int argc, char** argv) 
{  
    list <string> list;

    for (int i = 0; i < argc; i++)  {
        string example = argv[i];
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
            handle the -rN flag, parse the -rN for the N...
        */
        if (example.find("-r") == 0) {
            example.erase(example.begin(),example.begin()+2);
            string rN = example;
            if (rN != ""){
                repetitions = stoi(rN);
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
                   
                    cout << "Invalid Argument Detected, ignoring: " 
                    << *it << "\n";
               ;
                }
            }
        }

    }

    if (repetitions > 1)
    {  
        /*
            Deals when you have the -p/-process switches with the -rN when N is greater then one
        */
        if (process) {
            
            string proc = createProcess(repetitions);
             
            cout << "\n" <<  "Create Process Average Time taken: " << proc << "\n";  
        }
        /*
            Deals when you have the -t/-thread switches with the -rN when N is greater then one
        */
        if (thread) {
           string threads = createThreads(repetitions);

           cout << "\n" <<  "Create Thread Average Time taken: " << threads << "\n";  
        }

         
    } else {
        /*
            Deals when you have the -p/-process switches with the -rN when N is equal to one or no N present
        */
        if (process) {
            
            string proc = createProcess(1);
                
            cout << "\n" <<  "Time taken: " << proc<< "\n";  
        }
        /*
            Deals when you have the -t/-thread switches with the -rN when N is equal to one or no N present
        */
        if (thread) {
           string threads =  createThreads(1);

           cout << "\n" <<  "Time taken: " << threads<< "\n";  
        }
    }

    
    return 0; 
} 


