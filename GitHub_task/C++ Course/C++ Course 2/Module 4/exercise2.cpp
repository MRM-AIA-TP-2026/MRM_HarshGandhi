#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {

////////// DO NOT EDIT! //////////
  string path = argv[1];        //
//////////////////////////////////  
  
  //add code below this line
    ifstream file(path);
    if (!file.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    vector<int> columnSums(4, 0);  // To store sums of each column
    int rowCount = 0;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string value;
        int colIndex = 0;

        while (getline(ss, value, ',')) {
            if (colIndex < 4) {  // Only process up to 4 columns
                columnSums[colIndex] += stoi(value);
                colIndex++;
            }
        }
        rowCount++;
    }

    file.close();

    // Calculate and print averages
    for (int i = 0; i < 4; i++) {
        cout << columnSums[i] / rowCount << " ";
    }
    cout << endl;


  //add code above this line
  
  return 0;
  
}
