
#include <iostream>
#include <vector>
using namespace std;

// Vector of pairs to store number-word mappings
vector<pair<int, string>> numToWordMap = {{1000000000, "Billion"},
                                          {1000000, "Million"},
                                          {1000, "Thousand"},
                                          {100, "Hundred"},
                                          {90, "Ninety"},
                                          {80, "Eighty"},
                                          {70, "Seventy"},
                                          {60, "Sixty"},
                                          {50, "Fifty"},
                                          {40, "Forty"},
                                          {30, "Thirty"},
                                          {20, "Twenty"},
                                          {19, "Nineteen"},
                                          {18, "Eighteen"},
                                          {17, "Seventeen"},
                                          {16, "Sixteen"},
                                          {15, "Fifteen"},
                                          {14, "Fourteen"},
                                          {13, "Thirteen"},
                                          {12, "Twelve"},
                                          {11, "Eleven"},
                                          {10, "Ten"},
                                          {9, "Nine"},
                                          {8, "Eight"},
                                          {7, "Seven"},
                                          {6, "Six"},
                                          {5, "Five"},
                                          {4, "Four"},
                                          {3, "Three"},
                                          {2, "Two"},
                                          {1, "One"}};

// Recursive function to convert a number to words
string numberToWords(int num) {
  // Base case: if num is 0, return "Zero"
  if (num == 0) {
    return "Zero";
  }

  // Iterate through the number-word mappings
  for (auto &mapping : numToWordMap) {
    // If num is greater than or equal to the current mapping's number
    // means we could describe / distribute num related with it .
    if (num >= mapping.first) {
      string highPart = "";

      // If num is greater than or equal to 100, make a recursive call
      // means we could describe / distribute num related with it .
      // * look at bottom for more explaination
      if (num >= 100) {
        highPart =
            numberToWords(num / mapping.first) +
            " "; // Recursively handle the hundreds part ,
                 // for 12345 /1000 = 12   -> highPart = numberToWords(12)
      }

      string currentPart =
          mapping.second; // Get the corresponding string representation

      string lowPart = "";

      // If there's a remainder, recursively handle the remainder part
      if (num % mapping.first != 0) {
        lowPart =
            " " + numberToWords(
                      num % mapping.first); // Recursively handle the remainder
                                            // part , 12345 % 1000 = 345  ->
                                            // lowPart = numberToWords(345)
      }

      // Combine the parts and return
      return highPart + currentPart + lowPart;
    }
  }

  // If num doesn't match any mappings, return an empty string (shouldn't
  // happen)
  return "";
}

int main() {
  int num;
  cout << "Enter a number: ";
  cin >> num;

  cout << "Number in words: " << numberToWords(num) << endl;

  return 0;
}

/*
Example Input:
12345

Example Output:
Number in words: Twelve Thousand Three Hundred Forty Five
*/

/*
 * Time Complexity:
 *   - The function iterates through a constant number of mappings, which is
 * O(1).
 *   - The recursive part of the function has a time complexity of O(log(n)).
 *   - Overall time complexity is determined by the recursive part, so it's
 * O(log(n)).
 *
 * Space Complexity:
 *   - The function uses a constant amount of space for variables, so it's O(1).
 *   - The call stack for recursive calls can grow up to the number of digits in
 *   the input number, which is O(d),
 *     where d is the number of digits in the input number.
 *   - Overall space complexity is O(d), directly related to the size of the
 *   input (number of digits).
 *
 * For an input of 123, the time complexity is indeed approximately log(123)
 * (with base 10), which is roughly 3. This is because you have about 3
 * recursive calls to handle this input.
 *
 * Regarding space complexity, it is determined by the number of digits in the
 * input. In this case, the input 123 has 3 digits, so the space complexity
 * is 3.
 */

/*
 the term "describe" refers to expressing a number in words, while "distribute"
implies breaking down a number into parts (such as thousands, hundreds, etc.).

Let's break this down with an example:

Suppose we have the number 12345. To convert this number to words, we want to
describe it in terms of its components: thousands, hundreds, tens, and ones.

Thousands: 12 (Because 12345 / 1000 = 12)
Hundreds: 3 (Because 12345 % 1000 = 345, and 345 / 100 = 3)
Tens and Ones: 45 (Because 345 % 100 = 45)

So, in this example, we're describing the number 12345 by distributing it into
its respective parts:

Thousands: Twelve
Hundreds: Three
Tens and Ones: Forty-Five

The line you mentioned in the comment emphasizes the concept that we're breaking
down the original number into these meaningful parts, which helps us convert it
into words accurately.

so basically we could only have the highPart only if the number is 100 or above
  cause we have to spell it as one hundred not hundred , the same implies for
all the numbers above it and oposite for the lowerones.
*/
