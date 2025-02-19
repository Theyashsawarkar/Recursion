
#include <iostream>
#include <vector>
using namespace std;

// Function to recursively find the size of the largest square
int findLargestSquare(vector<vector<char>> &matrix, int row, int col, int i,
                      int j, int &maxSquareSize) {
  // Base case: if out of bounds, return 0
  if (i >= row || j >= col) {
    return 0;
  }

  // Recursively find the largest squares in right, diagonal, and down
  // directions

  // right
  int right = findLargestSquare(matrix, row, col, i, j + 1, maxSquareSize);

  // diagonal
  int diagonal =
      findLargestSquare(matrix, row, col, i + 1, j + 1, maxSquareSize);

  // down
  int down = findLargestSquare(matrix, row, col, i + 1, j, maxSquareSize);

  // If the current position contains '1', we can potentially form a square
  if (matrix[i][j] == '1') {
    // Find the minimum of the sizes of squares in all three directions
    // We find min to get the size of the square in which m[i][j] comes
    // Example: right -> 3 , diagonal -> 2 , down -> 1 then
    // [i,j]  1 1 1
    //  1     1 1 1
    //  0     1 1 1
    // as you can see min (down in this case) gives us the
    // size of the square we stand in .
    // we add one to indicate the the box containig one
    // itself is one square
    int currentSquareSize = 1 + min(right, min(diagonal, down));

    // Update the maximum square size found so far
    // This is our answer
    maxSquareSize = max(maxSquareSize, currentSquareSize);

    return currentSquareSize;
  }
  return 0; // If current position contains '0', return 0
            // as it can't form the square
}

int maximalSquare(vector<vector<char>> &matrix) {
  int row = matrix.size();
  int col = matrix[0].size();

  int i = 0;
  int j = 0;

  int maxSquareSize = 0;

  // Start finding the largest square from the top-left corner
  findLargestSquare(matrix, row, col, i, j, maxSquareSize);

  int maxSquareArea =
      maxSquareSize * maxSquareSize; // Calculate the area of the largest square

  return maxSquareArea;
}

int main() {
  // Example Usage
  vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                 {'1', '0', '1', '1', '1'},
                                 {'1', '1', '1', '1', '1'},
                                 {'1', '0', '0', '1', '0'}};

  int maxArea = maximalSquare(matrix);
  cout << "The area of the largest square of 1's is: " << maxArea << endl;

  return 0;
}

/*
Time Complexity: O(3^n)
- we are doing three calls to cheak for possible squares in three directions

Space Complexity:
- The space complexity of this code is O(m*n) due to the recursive calls.
*/
