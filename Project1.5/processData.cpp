#ifndef __PROCESSDATA_H__
#define __PROCESSDATA_H__

#include <iostream> 
#include <string>
#include "NanoTimer.h"
#include <unistd.h>
#include <list>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/syscall.h>


using namespace std; 


class processData 
{ 

/*
Input: repetitions, default value is 1, unless -rN is specified in the command line arguments
Output: average time, which is total time divided by total repetitions
Description: creates as many processes as specified by the input parameter
*/
public:string createProcess(int repetitions){
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
            // CLIView view = new CLIView();
            // view.printProcessFailed();
        }

        // if pid of fork() is 0 then fork is a child!
        if (pid == 0)
        {
        
            cout<< "\n"<< "Hello From Child Process(PID = "<< getpid() << ")" << "\n";
           
            // Exits current child process
            exit(0);
           
            

        }
        sleep(1);

    } 

    // get rid of the exited processes from the system 
    while(wait(&run)>=0); 

    // return total summation of times divided by total repetitions
    sleep(1);
    return to_string(total/repetitions);

}
/*
Input: pointer to integer value of pthread 
Output: none
Description: Outputs, a child thread message, and deltes the current pointer, to perseve
space....
*/
static void *createThreadsString(void *args){
    int id = *(int*)args;
    pid_t tid = syscall(SYS_gettid);
//    pid_t pid = syscall(SYS_getpid);
    cout << "\n"<< "Hello from the child thread (TID = " << tid << ")";
//    cout << "\n"<< "Hello from the child thread (PID = " << pid << ")";

    delete (int*)args;
}

/*
Input: repetitions, default value is 0, if -rN is specifeid, N value is taken
Output: average time, which is total time divided by total repetitions
Description: creates as many threads as specified by the input parameter
*/
public:string createThreads(int repetitions){
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
       sleep(1);
    }
    
    // return total summation of times divided by total repetitions
  
    return to_string(total/repetitions);
    

}




};

#endif