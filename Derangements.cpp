
#include <bits/stdc++.h>
using namespace std;

// Function to calculate derangements
int derangements(int n) {
  if (n == 1) {
    return 0; // Base case: There is no derangement of one element.
  }

  if (n == 2) {
    return 1; // Base case: There is one derangement of two elements.
  }

  // The formula for derangements
  int ans = (n - 1) * (derangements(n - 2) + derangements(n - 1));

  return ans;
}

int main(int argc, char *argv[]) {
  int n;

  cout << "Enter the value of n: ";
  cin >> n;

  // Calculate and print the number of derangements
  int numDerangements = derangements(n);
  cout << "Number of derangements for " << n
       << " elements: " << numDerangements;

  return 0;
}

/*
 * The derangement formula explained:
 *
 * When you fix one element, there are two possibilities:
 *
 * 1. The element it is swapped with comes to its position:
 *    - In this case, you essentially have n-2 elements left to be deranged.
 *      This is why you recursively call derangements(n - 2).
 *
 * 2. The element it is swapped with goes to any random position:
 *    - In this case, you have n-1 elements left to be deranged.
 *      So, you recursively call derangements(n - 1).
 *
 * and since this can be done with any element in range n-1 we multiply it with
 * it .
 */

/*
 * Time Complexity Analysis:
 *   - The time complexity of this recursive solution is O(2^n). This is
 *      because the function makes two recursive calls in each step,
 *      leading to an exponential number of calls.
 *
 * Space Complexity Analysis:
 *   - The space complexity is O(n) due to the recursive call stack, where n
 *      is the input number n.
 *
 * This solution is not efficient for large values of n and can be optimized
 * using dynamic programming.
 */
