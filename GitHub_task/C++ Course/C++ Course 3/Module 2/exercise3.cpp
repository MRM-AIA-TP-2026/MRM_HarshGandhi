#include <iostream>
using namespace std;

//add function definitions below this line
int BunnyEars(int a){
  if(a==0){
    return 0;
  }else{
    return BunnyEars(a-1) + 2;
  }
}


//add function definitions above this line

int main(int argc, char** argv) {
  cout << BunnyEars(stoi(argv[1])) << endl;
  return 0;
}
