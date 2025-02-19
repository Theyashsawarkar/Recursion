#include <iostream>
#include <vector>
using namespace std;

// Function to recursively find the maximum amount that can be robbed starting
// from a given index
int maxRobbedAmount(vector<int> &houses, int currentIndex) {

  // Base case: if we reach the end of the array, return 0 (no more houses to
  // rob)
  if (currentIndex >= houses.size()) {
    return 0;
  }

  // Option 1: Rob the current house and skip the next house
  int option1 =
      houses[currentIndex] + maxRobbedAmount(houses, currentIndex + 2);

  // Option 2: Skip the current house and move to the next one
  int option2 = maxRobbedAmount(houses, currentIndex + 1);

  // Return the maximum of the two options
  return max(option1, option2);
}

// Function to initiate the robbery and return the maximum amount that can be
// robbed
int robHouses(vector<int> &houses) { return maxRobbedAmount(houses, 0); }

int main() {
  vector<int> houses = {3, 2, 7, 10}; // Example input

  int maxAmount = robHouses(houses);

  cout << "Maximum amount that can be robbed: " << maxAmount << endl;

  return 0;
}

/*
    Time Complexity Explanation:
    - The time complexity of this solution is O(2^n), where n is the number of
   houses. This is because for each house, there are two options: rob it or skip
   it.

    Space Complexity Explanation:
    - The space complexity is O(n) due to the recursive call stack, where n is
   the number of houses.
*/
