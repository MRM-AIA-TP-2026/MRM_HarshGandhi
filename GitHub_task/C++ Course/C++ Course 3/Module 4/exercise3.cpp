#include <iostream>
using namespace std;

//add class definitions below this line

class Mass {
  public:
    // Constructor
    Mass(double mg, double g, double kg) {
      milligrams = mg;
      grams = g;
      kilograms = kg;
    }
    
    // Method to calculate total weight in grams
    double TotalWeight() const {
      return milligrams / 1000 + grams + kilograms * 1000;
    }
    
    // Method to compare the total weight of two Mass objects
    string CompareWeight(const Mass& other) const {
      double weight1 = TotalWeight();
      double weight2 = other.TotalWeight();
      
      if (weight1 > weight2) {
        return "The first object is heavier.";
      } else if (weight1 < weight2) {
        return "The second object is heavier.";
      } else {
        return "The two objects weight the same.";
      }
    }

  private:
    double milligrams;
    double grams;
    double kilograms;
};

//add class definitions above this line   

int main() {
  
  //DO NOT EDIT the code below

  Mass m1(800, 17, 3);
  Mass m2(730, 38, 2);
  cout << m1.TotalWeight() << endl;
  cout << m2.TotalWeight() << endl;
  cout << m1.CompareWeight(m2) << endl;

  //DO NOT EDIT the code above
  
  return 0;
  
}
