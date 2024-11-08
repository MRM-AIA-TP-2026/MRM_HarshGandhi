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

    string name, profession, line;
    int age, maxAge = -1;
    string oldestPerson;

    // Read each line from the file
    while (getline(file, line)) {
        stringstream ss(line);
        string currentName, currentProfession;
        int currentAge;

        // Parse the line assuming it's tab-delimited
        if (getline(ss, currentName, '\t') && ss >> currentAge && getline(ss, currentProfession, '\t')) {
            if (currentAge > maxAge) {
                maxAge = currentAge;
                oldestPerson = currentName;
            }
        }
    }

    file.close();

    // Print the name of the oldest person
    cout << "The oldest person is "<< oldestPerson << endl;


  //add code above this line
  
  return 0;
  
}
