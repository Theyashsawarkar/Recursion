
#include <iostream>
#include <vector>

using namespace std;

// Recursive function to find maximum loot
int findMaxLoot(vector<int> &houses, int start, int end) {
  // Base case: If there are no houses, return 0
  if (start > end) {
    return 0;
  }

  // Option 1: Rob current house and skip next house
  int option1 = houses[start] + findMaxLoot(houses, start + 2, end);

  // Option 2: Skip current house
  int option2 = findMaxLoot(houses, start + 1, end);

  return max(option1, option2);
}

// Main function to calculate maximum loot
int calculateMaxLoot(vector<int> &houses) {
  // If there's only one house, return its value
  if (houses.size() == 1) {
    return houses[0];
  }

  // Scenario 1: consider Robing the first house
  int option1 = findMaxLoot(houses, 0, houses.size() - 2);

  // Scenario 2: Don't consider robing the first house
  int option2 = findMaxLoot(houses, 1, houses.size() - 1);

  // Return the maximum loot from the two scenarios
  return max(option1, option2);
}

int main() {
  vector<int> houses = {6, 7, 1, 30, 8, 2, 4};

  // Calculate maximum loot
  int maxLoot = calculateMaxLoot(houses);

  // Output the result
  cout << "Maximum loot: " << maxLoot << endl;

  return 0;
}

/* since the houses are in circle we cant rob last house if we rob the first and
 * vice versa , so we consider both the cases .
 *  1. rob the first house and ignore the last (0 to n-2)
 *  2. rob the last house and ignore the first (1 to n-1)
 */

/*
Time Complexity Analysis:
The recursive approach has an exponential time complexity of O(2^n) due to the
overlapping subproblems. This can be improved using dynamic programming.

Space Complexity Analysis:
The space complexity of the recursive approach is O(n) due to the call stack. In
the dynamic programming solution, it can be reduced to O(1) by using two
variables to keep track of the previous maximum loots.
*/
