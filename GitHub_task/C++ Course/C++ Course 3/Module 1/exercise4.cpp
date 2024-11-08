#include <iostream>
#include <vector>
using namespace std;

//add code below this line
bool IsPalindrome(const string& str) {
  int left = 0;
  int right = str.length() - 1;

  while (left < right) {
    if (str[left] != str[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}


//add code above this line

int main(int argc, char** argv) {
  string x = argv[1];
  cout << boolalpha << IsPalindrome(x) << endl;
}