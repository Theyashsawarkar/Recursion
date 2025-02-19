
#include <iostream>

using namespace std;

// DRY run and understand this approach
// https://www.naukri.com/code360/problems/finding-binary-in-decimal_975489?leftPanelTabValue=SOLUTION

// Helper function to recursively count numbers that consist only of digits '1'
// and '0'.
long helper(long n, long count) {

  // Base case:
  // If 'count' becomes greater than the given number 'n',
  // stop the recursion as we are only interested in numbers <= 'n'.
  if (count > n) {
    return 0;
  }

  // Recursive case:
  // 1. Call the helper function for the number formed by appending '0' to
  // 'count'.
  //    This means multiplying 'count' by 10 (i.e., count * 10).
  // 2. Call the helper function for the number formed by appending '1' to
  // 'count'.
  //    This means multiplying 'count' by 10 and adding 1 (i.e., count * 10 +
  //    1).
  // 3. Add 1 to the result to count the current 'count' number itself.
  // Combine the result of both recursive calls and return the final count.
  return helper(n, count * 10) + helper(n, count * 10 + 1) + 1;
}

// Main function to count the binary-like numbers <= 'n'.
long countOfNumbers(long n) {
  // Start the recursion with the smallest binary-like number, which is 1.
  return helper(n, 1);
}

int main() {
  // Input: The number 'n'.
  long n;
  cout << "Enter a number: ";
  cin >> n;

  // Output: The count of numbers consisting only of '1' and '0' digits
  //         that are less than or equal to 'n'.
  cout << "Count of numbers with only 1s and 0s less than or equal to " << n
       << ": " << countOfNumbers(n) << endl;

  return 0;
}
