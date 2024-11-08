#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
  
  double input;
  double total = 0;
  double avg = 0;
  vector<double> numList;  // Initializes an empty vector
  
  cout << "Enter double or int to add to total, else find total average:" << endl;
  while (cin >> input) {
    // Add input into vector
    numList.push_back(input);
    
    // Prompt for the next input
    cout << "Enter double or int to add to total, else find total average:" << endl;
  }
  
  // Iterate through vector, add elements to total, then calculate average
  for (double num : numList) {
    total += num;
  }
  
  if (!numList.empty()) {
    avg = total / numList.size();
  }

  cout << avg << endl;
  
  return 0;
}
