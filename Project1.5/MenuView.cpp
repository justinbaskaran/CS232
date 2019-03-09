#include <iostream>
#include "CLIController.cpp"
#include <string>
#include <sstream>
#include <bits/stdc++.h> 
#include "commonView.h"

using namespace std;

class MenuView: public commonView{

    // Command Line Menu Asks for user input, and does accordingly 
    public:string printWelcomeMessage(){
        string a="";
        cout << "\n" << "Welcome to the Menu Version of this app!";
        cout << "\n" << "Please choose from the following options: (please enter y or n ";
        cout << "\n" << "1.Would you like to spawn a Thread? ";
        string choice1;
        cin >> choice1;
        if(choice1 == "y"){
            a.append("-t ");
        } 



        cout << "\n" << "2.Would you like to spawn a Process? ";
        string choice2;
        cin >> choice2;
        if(choice2 == "y"){
            a.append("-p ");
        }



        cout << "\n" << "How many Times? ";
        string repetitions;
        cin >> repetitions;
        string rN = "-r" + repetitions;
        char *cstr = new char[rN.length() + 1];
        strcpy(cstr, rN.c_str());
        a.append(cstr);
        a.append(" ");
    
        return a;

    }





};

