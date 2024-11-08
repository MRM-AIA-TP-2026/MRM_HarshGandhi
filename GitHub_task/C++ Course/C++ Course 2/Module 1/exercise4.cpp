#include <iostream>
#include <cstdlib>  // For atoi
using namespace std;

int main(int argc, char** argv) {
  
  // Read four integers from command-line arguments
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  int c = atoi(argv[3]);
  int d = atoi(argv[4]);
  
  // Initialize the 2D array
  int nums[3][3];
  
  // Add code below this line
  nums[0][0] = a;
  nums[0][1] = b;
  nums[0][2] = a + b;
  
  nums[1][0] = c;
  nums[1][1] = d;
  nums[1][2] = c + d;
  
  nums[2][0] = a + c;
  nums[2][1] = b + d;
  nums[2][2] = (a + b) + (c + d) + (a + c) + (b + d);
  // Add code above this line
  
  // Calculate rows and columns for printing
  int row = sizeof(nums) / sizeof(nums[0]);
  int col = sizeof(nums[0]) / sizeof(int);
  
  // Print the 2D array with the specified format
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (j == 2) {
        cout << nums[i][j] << endl;
      }
      else {
        cout << nums[i][j] << " ";
      }
    }
  }
  
  return 0;
}
