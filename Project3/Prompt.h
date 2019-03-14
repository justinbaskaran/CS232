#ifndef __PROMPT_H__
#define __PROMPT_H__


#include <iostream> 
#include <string>
#include <list>
#include <unistd.h>
#include <pthread.h>
#include<bits/stdc++.h>

using namespace std; 

class Prompt{
    string response="";
    public:Prompt() {
        char cwd[256];
        if (getcwd(cwd, sizeof(cwd)) == NULL) {
            perror("getcwd() error");
        }else {
           // printf("current working directory is: %s\n", cwd);
        }

        cout << "\n" << cwd << "$ ";
        getline(cin, response);
      

    }

    public:string get() {
        return response;
    }

};

#endif
