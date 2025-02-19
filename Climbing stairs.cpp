#include <iostream>

using namespace std;

/* this slution works but it gives tle as it has 2^n time complecity in worse
 * case */

// Function to calculate the number of ways to climb n stairs.
int climbStairs(int n) {

  // Base case: If there are 0 or 1 stairs, there's only one way to climb them
  // no need to move or you can jump once to reach them in one step .
  if (n == 0 || n == 1) {
    return 1;
  }

  // Recursive step: The number of ways to climb n stairs is the sum of the
  // number of ways to climb (n-1) stairs and (n-2) stairs, since you can either
  // take one step or two steps at a time. bsically you can reach n th stair
  // only from n-1 or n-2 th stairs so we cheak for how many ways you can reach
  // their , thus using febonacci series .
  return climbStairs(n - 1) + climbStairs(n - 2);
}

/* below is the itirative approach of fibonacci series , time complecity : O(n)
 */

// Function to calculate the number of ways to climb n stairs using dynamic
// programming.
int climbStairsItirative(int n) {

  // Base case: If there are 0 or 1 stairs, there's only one way to climb them
  // (no need to move).
  if (n == 0 || n == 1) {
    return 1;
  }

  // Initialize variables to keep track of previous and next steps.
  int prev = 0;
  int next = 1;
  int sum = 0;

  // Iterate through the stairs, calculating the number of ways at each step.
  while (n--) {
    sum = prev + next;
    prev = next;
    next = sum;
  }

  return sum;
}

int main() {

  int n;

  cin >> n;

  cout << climbStairs(n) << endl;

  cout << climbStairsItirative(n) << endl;
}
