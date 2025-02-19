#include <bits/stdc++.h>
using namespace std;

// Recursive approach to generate subsequences
void generateSubsequencesRecursive(string str, string currentSubsequence,
                                   int index, vector<string> &result) {
  if (index >= str.length()) {
    result.push_back(
        currentSubsequence); // Add the current subsequence to the
                             // result . if we reached the base case
                             // means we have our ans generated
    return;
  }

  /*
   * these approach uses the concept that for each character in the string we
   * have two operations either to include it or not .
   */

  // Include the current character
  generateSubsequencesRecursive(str, currentSubsequence + str[index], index + 1,
                                result);

  // Exclude the current character
  generateSubsequencesRecursive(str, currentSubsequence, index + 1, result);
}

// Bitmasking approach to generate subsequences
void binarySubSequences(string &str) {
  // Iterate through numbers from 0 to 2^n
  for (int num = 0; num < pow(2, str.length());
       num++) { // same as (1 << n) , this is fast than pow function

    int currentNum = num;

    string subsequence;

    int charIndex = 0;

    // Extract characters based on binary representation of currentNum
    // so what we do here is we use the bit position as the index of the
    // character in the string charIndex help us do that
    while (currentNum) {

      int bit = (currentNum & 1); // gets the last bit

      // if bit is set include the chaar at that index in the output
      if (bit) {
        subsequence.push_back(str[charIndex]);
      }
      charIndex++;
      currentNum >>= 1; // remove the bit and search for the bit at left
    }
    cout << subsequence << endl; // Print the generated subsequence
  }
}

int main() {
  string str;
  cin >> str; // Taking input for the string

  vector<string> result;

  // Using recursive approach
  generateSubsequencesRecursive(str, "", 0, result);

  // Printing results
  for (auto it : result) {
    cout << "> " << it << endl;
  }

  // Using bitmasking/bit manipulation approach
  binarySubSequences(str);
}

/*
 * There are two approaches for generating subsequences of a string.
 *
 * 1. Recursive Approach:
 *    This approach uses recursion to generate all possible subsequences of the
 * input string. The function `generateSubsequencesRecursive` takes four
 * parameters:
 *      - `str` - The input string.
 *      - `currentSubsequence` - The current subsequence being generated.
 *      - `index` - The current index in the input string.
 *      - `result` - A vector to store the generated subsequences.
 *    The base case of the recursion is when `index` is greater than or equal to
 * the length of the input string. At this point, we add the current
 * `currentSubsequence` to the `result` vector. The function is then called
 * twice recursively - once including the current character and once excluding
 * it.
 *
 * 2. Bitmasking/Bit Manipulation Approach:
 *    This approach uses binary representation and bitwise operations to
 * generate subsequences. It iterates through all numbers from 0 to 2^n (where n
 * is the length of the input string). The binary representation of these
 * numbers is used to determine which characters to include in the subsequence.
 *    The function `generateSubsequencesBinary` takes the input string `str`.
 *    It iterates through all possible combinations using bitwise operations.
 *    For each combination, it extracts the characters that correspond to set
 * bits in the binary representation of the number.
 */

/*
 * Time Complexity (Recursive Approach): O(2^n), where n is the length of the
 * input string.
 *
 * Space Complexity (Recursive Approach): O(n), as at most the whole string will
 * be the answer
 */

/*
 * Time Complexity (Bitmasking Approach): O(2^n * n), where n is the length of
 * the input string. '*n' cause we are traversing the bits too.
 *
 * Space Complexity (Bitmasking Approach):  O(n), as at most the whole string
 * will be the answer
 */
