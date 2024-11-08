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

    string line;
    vector<string> southernCities;

    // Skip the header line
    getline(file, line);

    // Process each line of data
    while (getline(file, line)) {
        stringstream ss(line);
        string city, country, latitudeStr, longitudeStr;
        double latitude;

        // Parse the comma-separated values
        getline(ss, city, ',');
        getline(ss, country, ',');
        getline(ss, latitudeStr, ',');
        getline(ss, longitudeStr, ',');

        // Convert latitude to a double
        latitude = stod(latitudeStr);

        // Check if the latitude is in the Southern Hemisphere
        if (latitude < 0) {
            southernCities.push_back(city);
        }
    }

    file.close();

    // Output the cities in the Southern Hemisphere
    cout << "The following cities are in the Southern Hemisphere: ";
    for (size_t i = 0; i < southernCities.size(); i++) {
        cout << southernCities[i];
        if (i < southernCities.size() - 1) {
            cout << ", ";
        }
    }
    cout << "." << endl;


  //add code above this line
  
  return 0;
  
}
