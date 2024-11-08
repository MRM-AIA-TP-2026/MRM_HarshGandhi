#include <iostream>
using namespace std;

//add class definitions below this line

class MarbleBag {
  public:
    MarbleBag(int r, int b, int y) {
      red = r;
      blue = b;
      yellow = y;
    }
  void AddRed(int amount) {
      red += amount;
    }

    // Function to add to the blue marble count
    void AddBlue(int amount) {
      blue += amount;
    }

    // Function to add to the yellow marble count
    void AddYellow(int amount) {
      yellow += amount;
    }

    // Function to return the current number of red marbles
    int RedTotal() const {
      return red;
    }

    // Function to return the current number of blue marbles
    int BlueTotal() const {
      return blue;
    }

    // Function to return the current number of yellow marbles
    int YellowTotal() const {
      return yellow;
    }

    // Function to return the total number of marbles
    int BagTotal() const {
      return red + blue + yellow;
    }

  private:
    int red;
    int blue;
    int yellow;
};

//add class definitions above this line   

int main() {
  
  //DO NOT EDIT code below this line
  
  MarbleBag bag(12, 8, 19);
  bag.AddRed(4);
  bag.AddBlue(12);
  bag.AddYellow(-1);
  bag.AddBlue(-3);
  cout << "There are " << bag.RedTotal() << " red marbles." << endl;
  cout << "There are " << bag.BlueTotal() << " blue marbles." << endl;
  cout << "There are " << bag.YellowTotal() << " yellow marbles." << endl;
  cout << "There are " << bag.BagTotal() << " total marbles." << endl;

  //DO NOT EDIT code above this line
  
  return 0;
  
}