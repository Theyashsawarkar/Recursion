
#include <iostream>
#include <string>
using namespace std;

bool solve(string &s, string &p, int sIdx, int pIdx) {
  // Base case: if both strings are exhausted, it's a match
  if (sIdx == s.length() && pIdx == p.length()) {
    return true;
  }

  // If the pattern is exhausted but there are still characters in the string,
  // check if remaining characters are all '*'
  // cause we could equate them to "" /  null / empty string
  if (s.length() == sIdx && pIdx < p.length()) {
    while (pIdx < p.length()) {
      if (p[pIdx] != '*') {
        return false;
      }
      pIdx++;
    }
    return true;
  }

  // If characters at current indices match or pattern has '?', move to next
  // characters
  if (s[sIdx] == p[pIdx] || p[pIdx] == '?') {
    return solve(s, p, sIdx + 1, pIdx + 1);
  }

  // If current pattern character is '*', we have two options:
  // 1. Move ahead in the string and keep pattern same
  // 2. Move ahead in the pattern and keep string same
  if (p[pIdx] == '*') {
    bool option1 = solve(s, p, sIdx + 1, pIdx);
    bool option2 = solve(s, p, sIdx, pIdx + 1);
    return option1 ||
           option2; // if either one is true it's possible to match them
  }

  // s[sIdx] != p[pIdx]  , so we return false directly
  return false;
}

bool isMatch(string s, string p) {
  int sIdx = 0;
  int pIdx = 0;

  return solve(s, p, sIdx, pIdx);
}

int main() {
  string s;
  string p;

  cin >> s >> p;

  // Check if s matches the pattern p
  bool result = isMatch(s, p);

  // Output the result
  cout << "Does '" << s << "' match the pattern '" << p << "'? ";
  cout << (result ? "Yes" : "No") << endl;

  return 0;
}

/*
Example Input:
s = "adceb"
p = "*a*b"

Example Output:
Does 'adceb' match the pattern '*a*b'? Yes
*/

/* Time Complexity: O(2^(max(s, p)))
   - In the worst case, the function explores all possible combinations of
   matches, resulting in exponential time complexity.
   - The recursive nature of the algorithm leads to this exponential growth.
*/

/* Space Complexity: O(p)
   - The space complexity of the recursive call stack can grow up to the length
     of the pattern 'p', which leads to a space complexity of O(p) in the
     worst case.
   - This is because the depth of the recursion is determined by the length of
   'p'.
*/
