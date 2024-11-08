#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  
  int a = stoi(argv[1]);
  int b = stoi(argv[2]);
  
  if (a > b) {
    int c = b;
    b = a;
    a = c;
  }
  
  //add code below this line
  int s = 0;
  for(int i = a ; i<b+1 ; i++){
    s += i;
  }
  cout<<s<<endl;

  //add code above this line
  
  return 0;
  
}
