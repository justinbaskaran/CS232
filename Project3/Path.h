#ifndef __PATH_H__
#define __PATH_H__


#include <iostream> 
#include <string>
#include <list>
#include <vector>
#include <dirent.h>


using namespace std; 

class Path{
    vector <string> dir = vector <string> ();

    public:Path() {
        string PATH = getenv("PATH");
        int previous = 0;
        int index = PATH.find(":");
         while( index != string::npos )
        {
            dir.push_back( PATH.substr(previous, index-previous));
            previous=index+1;
            index = PATH.find( ":", previous );
        }
        dir.push_back( PATH.substr(previous) );

        // for (vector<string>::const_iterator i = dir.begin(); i != dir.end(); ++i)
        //     cout << *i << '\n';
    }

    public:int find(const string& program) {
        struct dirent* direntp;
        for (int i =0; i < dir.size(); i++)
        {
            string directory = dir.at(i);
            const char * c = directory.c_str();
            DIR* dirp = opendir(c);
            if (dirp != NULL)
            {
                while ((direntp = readdir( dirp )) != NULL ) {
                if( direntp == NULL ) break;
                
                string targetFile(direntp->d_name);
                cout << "Files Listed: " << targetFile << "\n";
                cout << "Paramter: " << program << "\n";

                if (targetFile == program)
                {
             
                    return i;
                }
                
               // cout << direntp->d_name  << "\n";
                
                
                }
                closedir( dirp ); 
            }
           
                
            
        }
        return -1;
    }
    public:string getDirectory(int i) {
        return dir.at(i);
    }

};

#endif
