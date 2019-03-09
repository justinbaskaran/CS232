#ifndef __COMMONVIEW_H__
#define __COMMONVIEW_H__


#include <iostream> 
#include <string>
#include <list>
#include <unistd.h>
#include <pthread.h>


using namespace std; 

 // "Parent" View class that will be inherited by Children (MenuView and CommandLineView)
class commonView{

   
    public:void printAverageProcesses(string process) 
    {
        cout << "\n" <<  "Create Process Average Time taken: " << process << "\n";  
    }

   
    public:void printAverageThreads(string average) 
    {
        cout << "\n" <<  "Create Thread Average Time taken: " << average << "\n"; 
    }

};

#endif


 