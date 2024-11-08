#include <iostream>
using namespace std;

//add class definitions below this line
class Observation {
public:
    string date;
    double temperature;
    double elevation;
    int penguins;
    double precipitation;

    // Constructor with default precipitation set to 0
    Observation(string d, double temp, double elev, int peng, double precip = 0) 
        : date(d), temperature(temp), elevation(elev), penguins(peng), precipitation(precip) {}
};
   

  
//add class definitions above this line

int main() {

  Observation o("October 26, 2019", -47, 329.4, 3);
  cout << "Today is " << o.date << "." << endl;
  cout << "Temperature: " << o.temperature << endl;
  cout << "Elevation: " << o.elevation << endl;
  cout << o.penguins << " penguins observed with " << o.precipitation << " precipitation." << endl;
  
  return 0;
  
}
