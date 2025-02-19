
#include <iostream>
#include <string>
using namespace std;

/* the best approach for this question is itirative  */

// Recursive function to remove occurrences of 'part' in 'str'
void solve(string &str, string &part) {
  // Find the first occurrence of 'part' in 'str'
  int found = str.find(part);

  // If 'part' is found
  if (found != string::npos) {
    // Remove 'part' from 'str'
    str =
        str.substr(0, found) + str.substr(found + part.length(), str.length());
  } else {
    // If 'part' is not found, return
    return;
  }

  // Continue recursively searching for 'part'
  solve(str, part);
}

// Function to remove all occurrences of 'part' in 's'
string removeOccurrences(string s, string part) {
  // Start the recursive process
  solve(s, part);

  // Return the modified string
  return s;
}

int main() {
  string s = "abcbdcabcbcadcbabc";
  string part = "cb";
  string result = removeOccurrences(s, part);
  cout << result << endl;
  return 0;
}

/*
    Time Complexity:
    - The function 'solve' uses the 'find' function which has a time complexity
   of O(n*m) in the worst case, where 'n' is the length of 'str' and 'm' is the
   length of 'part'.
    - The recursive calls in 'solve' iterate over 'str' and perform substring
   operations, which can be considered O(n).
    - Overall, the time complexity is O(n * m) in the worst case.

    Space Complexity:
    - The space complexity is O(n) due to the recursive calls on 'str' which
   creates new substrings.
    - Additionally, space is used for the function call stack during recursion.
*/
