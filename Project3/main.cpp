#include <iostream> 
#include <string>
#include <list>
#include "Path.h"
#include "Prompt.h"
#include <string>
#include <iterator>
#include <fstream>
#include <sstream>

using namespace std; 


int main()
{
  Prompt pt = Prompt();
  Path ex = Path();

  stringstream ss(pt.get());
  istream_iterator<string> begin(ss);
  istream_iterator<string> end;
  vector<string> vstrings(begin, end);
  for (vector<string>::const_iterator i = vstrings.begin(); i != vstrings.end(); ++i)
    cout << "Item: " << *i << '\n';

  

  int cmd = ex.find(vstrings.at(0));
  cout << "Directory: " << ex.getDirectory(cmd) << "\n";

}
