#include <iostream>
using namespace std;

// Function to maximize the number of cuts
int maximizeTheCuts(int n, int x, int y, int z) {
  // Base case: If the length is zero, no cuts can be made
  if (n == 0) {
    return 0;
  }
  // Base case: If the length is negative, it's not possible to make a cut
  if (n < 0) {
    return -1;
  }

  // Option 1: Make a cut of length x and recursively maximize the cuts in the
  // remaining piece
  int option1 = 1 + maximizeTheCuts(n - x, x, y, z);

  // Option 2: Make a cut of length y and recursively maximize the cuts in the
  // remaining piece
  int option2 = 1 + maximizeTheCuts(n - y, x, y, z);

  // Option 3: Make a cut of length z and recursively maximize the cuts in the
  // remaining piece
  int option3 = 1 + maximizeTheCuts(n - z, x, y, z);

  // Return the maximum of the three options
  return max(option1, max(option2, option3));
}

int main() {
  int n = 10; // Length of the rod
  int x = 1;  // Length of cut option 1
  int y = 2;  // Length of cut option 2
  int z = 3;  // Length of cut option 3

  int result = maximizeTheCuts(n, x, y, z);
  cout << "Maximum number of cuts possible: " << result << endl;

  return 0;
}

/*

    this code is based on the explore all options/ans approache ,
    where you go through every possible ans to find the correct one

Time Complexity:

    The time complexity of this code is exponential, O(3^n), because for each
length n, there are three recursive calls (corresponding to the three options:
x, y,z).

Space Complexity:

    The space complexity is O(n) due to the recursive calls, as there can be at
most n levels in the recursion stack.

this has a better solution but it's of dp so it'll be added in the dp folder

*/
