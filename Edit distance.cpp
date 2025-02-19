
#include <iostream>
#include <string>

using namespace std;

int calculateEditDistance(string &str1, string &str2, int pos1, int pos2) {
  // Base cases: If either of the strings is empty, the edit distance
  // is the length of the other string
  if (pos1 >= str1.length()) {
    return str2.length() - pos2;
  }

  if (pos2 >= str2.length()) {
    return str1.length() - pos1;
  }

  int distance = 0;

  if (str1[pos1] == str2[pos2]) {
    // If characters at current position are equal, no operation needed
    distance = 0 + calculateEditDistance(str1, str2, pos1 + 1, pos2 + 1);
  } else {
    // Calculate the cost of insertion, deletion, and substitution operations

    // Insertion
    int option1 = 1 + calculateEditDistance(str1, str2, pos1 + 1, pos2);

    // Deletion
    int option2 = 1 + calculateEditDistance(str1, str2, pos1, pos2 + 1);

    // Substitution
    int option3 = 1 + calculateEditDistance(str1, str2, pos1 + 1, pos2 + 1);

    // Choose the minimum cost among the three options
    distance = min(option1, min(option2, option3));
  }

  return distance;
}

int minDistance(string word1, string word2) {
  int pos1 = 0;
  int pos2 = 0;

  return calculateEditDistance(word1, word2, pos1, pos2);
}

int main() {
  string word1 = "kitten";
  string word2 = "sitting";

  int distance = minDistance(word1, word2);
  cout << "Minimum Edit Distance: " << distance << endl;

  return 0;
}

/*
 * NOTE :- don't forget to do +1 in each of the below step as 1 operation is
 * being performed there . did mistake here before !
 *
 * Insertion : calculateEditDistance(str1, str2, pos1 + 1, pos2)
 *    - imagin we insert char at pos1 before the pos2 in word2 ,
 *      now as they match we increase the pos1 to search for next.
 *
 * Deletion : calculateEditDistance(str1, str2, pos1, pos2 + 1)
 *    - imagin you deleted the char at pos2 in word2 now to cheak the next char
 *      we increase the pos2
 *
 * Substitution :  calculateEditDistance(str1, str2, pos1 + 1, pos2 + 1)
 *    - imagin you added the char at pos1 in word1 at the pos2 in word2
 *      now as they match we increase both pos1 and pos2 to cheak further
 */

/*
 * Time complexity : O(3^n)
 *    - we'll make 3 recursive calls in every call in worst case
 *
 * Space complexity : O(n)
 *    - recusrsive call stack
 */
