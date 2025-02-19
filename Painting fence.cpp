
#include <iostream>
using namespace std;

// Function to calculate the number of ways to paint the fence
int countWaysToPaintFence(int posts, int colors) {

  // if there is only one post then we can paint it with all the colors
  if (posts == 1) {
    return colors;
  }

  /* if we have k colors then we can paint posts in two ways
   *    1. same colors :- then we can paint them in k ways
   *    2. different colors :- then we can paint first post with k colors but
   * for second we have k-1 colors since we want different colors for both of
   * them we can't use same colors (k)
   */
  if (posts == 2) {
    return colors + (colors * (colors - 1));
  }

  /*
   * solve one case :-
   *    There are two ways to paint the last two post
   *
   *  1. paint last two posts with same color
   *    - since the last two posts need to be of same colors ,
   *    and total colors are k then only k-1 colors remain for
   *    rest so for remaining n-2 posts we do => (k-1) * f(n-2)
   *
   *  2. paint last two posts with different colors
   *    - since we need to paint only one last post ,
   *    we take one color from colors to paint it and recursively search
   *    for next n-1 posts . => (k-1) * f(n-1)
   *
   *  ==> since we need to find total ways we add both and after simplifying the
   * equation we get the formula >>>> (k-1) * (f(n-1) * f(n-2)) ;
   *
   */
  int ways = (colors - 1) * (countWaysToPaintFence(posts - 1, colors) +
                             countWaysToPaintFence(posts - 2, colors));

  return ways;
}

int main() {
  int numPosts, numColors;

  cin >> numPosts >> numColors;

  cout << countWaysToPaintFence(numPosts, numColors);
}

/**
 * Time Complexity: O(2^n)
 *   - This is because we are making two recursive calls in every call.
 * Space Complexity: O(n)
 *   - This is due to the recursion stack. It can be optimized to O(1) using an
 * iterative approach.
 */
