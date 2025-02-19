
#include <iostream>
#include <string>

using namespace std;

// This function recursively adds two strings, str1 and str2, starting from
// indices p1 and p2 respectively, with a carry value and stores the result in
// 'ans'
void solve(string &str1, string &str2, int p1, int p2, int carry, string &ans) {

  // Base case: both strings have been processed
  if (p1 < 0 && p2 < 0) {

    // If there's a carry left after processing both strings, add it to the
    // result
    if (carry != 0) {
      ans.push_back(carry + '0');
    }
    return;
  }

  // Convert characters to integers, or use 0 if index is out of bounds
  int num1 = p1 < 0 ? 0 : str1[p1] - '0';
  int num2 = p2 < 0 ? 0 : str2[p2] - '0';

  int sum = num1 + num2 + carry; // Calculate sum

  int digit = sum % 10; // Calculate the current digit of the result

  ans.push_back(
      digit +
      '0'); // Append the digit to the result , caution here as if not +'0' then
            // it leads to the addition of some random ascii characters
  carry = sum / 10; // Calculate the carry for the next iteration

  // Recursive call to process the next digits
  solve(str1, str2, p1 - 1, p2 - 1, carry, ans);
}

// This function adds two strings and returns the result
string addStrings(string num1, string num2) {
  string ans = ""; // Initialize an empty string for the result

  solve(num1, num2, num1.size() - 1, num2.size() - 1, 0, ans);

  reverse(ans.begin(), ans.end()); // Reverse the string to get the final result

  return ans; // Return the final result
}

int main() {
  string num1 = "123";
  string num2 = "456";

  // Test Input
  cout << "Input: num1 = " << num1 << ", num2 = " << num2 << endl;

  string result = addStrings(num1, num2);

  // Test Output
  cout << "Output: " << result << endl;

  return 0;
}

// Time Complexity: O(n), where n is the maximum length of the input strings
// Space Complexity: O(n), as we are using a string 'ans' to store the result
