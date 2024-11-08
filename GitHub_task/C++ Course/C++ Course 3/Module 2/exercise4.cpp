#include <iostream>
using namespace std;

//add function definitions below this line
string ReverseString(const string& str) {
    if (str.empty()) {
        return ""; // base case: if the string is empty, return an empty string
    }
    // take the last character and add it to the reversed result of the remaining substring
    return str.back() + ReverseString(str.substr(0, str.size() - 1));
}


//add function definitions above this line

int main(int argc, char** argv) {
  cout << ReverseString(argv[1]) << endl;
  return 0;
}
