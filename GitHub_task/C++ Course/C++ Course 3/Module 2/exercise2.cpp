#include <iostream>
#include <vector>
using namespace std;

//add function definitions below this line
int ListSum(const vector<int>& nums) {
    if (nums.empty()) {
        return 0; // base case: if the vector is empty, return 0
    }
    vector<int> new_vector(nums.begin() + 1, nums.end()); // create a vector with the elements after the first one
    return nums[0] + ListSum(new_vector); // add the first element to the sum of the rest
}


//add function definitions above this line

int main(int argc, char** argv) {
  vector<int> nums;
  for (int i = 1; i < argc; i++) {
    nums.push_back(stoi(argv[i]));
  }
  cout << ListSum(nums) << endl;
  return 0;
}
