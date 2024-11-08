#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
  
  vector<string> reverse(0);
  reverse.push_back(argv[1]);
  reverse.push_back(argv[2]);
  reverse.push_back(argv[3]);
  
  //add code below this line

  int n = reverse.size();
  for (int i = 0; i < n / 2; ++i) {
      // Swap elements
      string temp = reverse[i];
      reverse[i] = reverse[n - i - 1];
      reverse[n - i - 1] = temp;
  }


  //add code above this line
  
  for (auto a : reverse) {
    cout << a << endl;
  }
  
  return 0;
  
}