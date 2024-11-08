#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  
  string my_string = (argv[1]);
  
  //add code below this line
  int size = my_string.size();
  for(int i =0 ; i <size ; i++){
    for(int j = 0 ; j < size ; j++){
      cout<< my_string;
    }
    cout << endl;
  }


  //add code above this line
  
  return 0;
  
}