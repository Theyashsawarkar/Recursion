
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// TODO: dry run and unserstand the logic behind this algorithm
// https://www.naukri.com/code360/problems/different-ways-to-add-parenthesis_1229381?leftPanelTabValue=SOLUTION

// Function to apply an operation (addition, subtraction, multiplication) on two
// integers
int applyOperation(int a, int b, char op) {
  if (op == '-') {
    return a - b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '*') {
    return a * b;
  }
  // Return 0 in case of an invalid operation (though this case should not occur
  // in this problem)
  return 0;
}

// Function to compute all possible results from different ways to group the
// operators in the string
vector<int> diffWaysToCompute(string expression) {
  vector<int> results;              // Vector to store all possible results
  int length = expression.length(); // Length of the input string
  bool hasOperator =
      false; // Flag to check if there are any operators in the expression

  // Iterate through each character in the expression
  for (int i = 0; i < length; i++) {
    // Check if the character is an operator
    if (expression[i] == '*' || expression[i] == '-' || expression[i] == '+') {
      hasOperator = true; // Set the flag to true since we found an operator

      // Recursively calculate results for the left part of the expression
      vector<int> leftResults = diffWaysToCompute(expression.substr(0, i));
      // Recursively calculate results for the right part of the expression
      vector<int> rightResults = diffWaysToCompute(expression.substr(i + 1));

      // Combine results from left and right parts using the current operator
      for (int leftResult : leftResults) {
        for (int rightResult : rightResults) {
          results.push_back(
              applyOperation(leftResult, rightResult, expression[i]));
        }
      }
    }
  }

  // If there are no operators, convert the string to an integer and add to
  // results
  if (!hasOperator) {
    results.push_back(stoi(expression));
  }

  return results;
}

// Main function to test the diffWaysToCompute function
int main() {
  string expression = "2-1-1";
  vector<int> results = diffWaysToCompute(expression);

  cout << "Different ways to compute the expression " << expression
       << " are:" << endl;
  for (int result : results) {
    cout << result << " ";
  }
  cout << endl;

  return 0;
}
