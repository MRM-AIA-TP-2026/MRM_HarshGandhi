#include <iostream>
using namespace std;

int main() {
  
  //add code below this line
    for (int i = 1; i <= 5; i++) {          // Outer loop for each line
        for (int j = 5; j > i; j--) {        // Inner loop for dots
            cout << ".";                     // Print dot
        }
        cout << i << endl;                   // Print the number and move to the next line
    }


  //add code above this line
  
  return 0;
  
}
