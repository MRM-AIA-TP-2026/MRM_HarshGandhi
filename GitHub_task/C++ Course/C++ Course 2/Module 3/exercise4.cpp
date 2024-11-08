#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  
  string my_string = (argv[1]);
  
  //add code below this line
   int length = my_string.length();
  
  // Calculate the midpoint for even split
  int midpoint = length / 2;

  // Print the first half
  cout << my_string.substr(0, midpoint) << endl;
  
  // Print the second half (includes extra character if length is odd)
  cout << my_string.substr(midpoint) << endl;


  //add code above this line
  
  return 0;
  
}