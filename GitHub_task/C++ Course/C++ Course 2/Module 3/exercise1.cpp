#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  
  string my_string = (argv[1]);
  
  //add code below this line

  int size = my_string.size();
  cout << my_string[0]<<" is the first character and "
   << my_string[size-1]<< " is the last character" << endl;

  //add code above this line
  
  return 0;
  
}