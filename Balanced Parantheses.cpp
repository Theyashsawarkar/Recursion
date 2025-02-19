
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// TODO: dry run and understand the logic and the approach
// https://www.naukri.com/code360/problems/return-parentheses_920446?leftPanelTabValue=SOLUTION

// Recursive function to generate balanced parentheses.
void solve(vector<string> &ans, string output, int opening, int closing) {
  // If we are left with 0 opening and closing braces.
  if (opening == 0 && closing == 0) {
    // Push the entire string into the vector.
    ans.push_back(output);
    return;
  }

  // If we have opening brackets, we can insert the '(' in every case.
  if (opening != 0) {
    solve(ans, output + '(', opening - 1, closing);
  }

  /*
      If the number of closing brackets is greater than the number of opening
     brackets, it means we have used more opening brackets than closing
     brackets.
  */
  if (closing > opening) {
    solve(ans, output + ')', opening, closing - 1);
  }

  return;
}

// Function to generate all combinations of balanced parentheses.
vector<string> balancedParentheses(int n) {
  // Declare a vector of strings to store all the balanced strings.
  vector<string> ans;
  string output = "";

  // Call the recursive function with 'n' pairs of parentheses.
  solve(ans, output, n, n);

  return ans;
}

int main() {
  int n;
  cout << "Enter the number of pairs of parentheses: ";
  cin >> n;

  // Generate all balanced parentheses combinations.
  vector<string> result = balancedParentheses(n);

  cout << "Balanced Parentheses combinations are:" << endl;
  for (const string &s : result) {
    cout << s << endl;
  }

  return 0;
}
