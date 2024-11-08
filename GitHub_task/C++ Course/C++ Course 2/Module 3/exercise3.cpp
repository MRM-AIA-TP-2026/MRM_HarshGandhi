#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  
  string original = (argv[1]);
  string modified;
  char ch;
  
  //add code below this line
  int size = original.size();
  for(int i=0 ; i<size ; i++){
    if(isupper(original[i])){
      modified.push_back('u');
    }else if(islower(original[i])){
      modified.push_back('l');
    }else{
      modified.push_back('-');
    }
  }
  cout << original <<endl;
  cout<<modified<<endl;


  //add code above this line
  
  return 0;
  
}