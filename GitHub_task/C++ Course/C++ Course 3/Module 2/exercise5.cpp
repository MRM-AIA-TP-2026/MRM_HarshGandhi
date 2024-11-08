#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//add function definitions below this line
int GetMax(const vector<int>& nums) {
    if (nums.size() == 1) {
        return nums[0]; // base case: if the vector has only one element, return that element
    }
    vector<int> new_vector(nums.begin() + 1, nums.end()); // create a vector with all elements except the first
    return max(nums[0], GetMax(new_vector)); // return the max between the first element and the max of the rest
}


//add function definitions above this line

int main(int argc, char** argv) {
  vector<int> nums;
  for (int i = 1; i < argc; i++) {
    nums.push_back(stoi(argv[i]));
  }
  cout << GetMax(nums) << endl;
  return 0;
}
