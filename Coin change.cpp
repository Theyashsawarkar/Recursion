#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int> &coins, int amount) {
  // Base case: If the amount is 0, then no coins are needed.
  if (amount == 0) {
    return 0;
  }

  // If the amount is negative, it means this combination is not valid.
  if (amount < 0) {
    return INT_MAX;
  }

  int mini = INT_MAX;

  // Loop through each coin in the coins vector.
  for (int i = 0; i < coins.size(); i++) {
    int coin = coins[i];

    // We can only use the current coin if its value is less than or equal to
    // the remaining amount.
    if (coin <= amount) {
      // Recursive call to find the optimal solution for the remaining amount.
      int recAns = solve(coins, amount - coin);

      // If recAns is not INT_MAX (i.e., a valid combination), add 1 to the
      // result.
      if (recAns != INT_MAX) {
        int ans = 1 + recAns;
        mini = min(mini, ans);
      }
    }
  }
  return mini;
}

int coinChange(vector<int> &coins, int amount) {
  // Call the solve function to find the optimal number of coins needed.
  int ans = solve(coins, amount);

  // If ans is still INT_MAX, it means it's not possible to make the amount with
  // the given coins.
  if (ans == INT_MAX)
    return -1;
  else
    return ans;
}

int main() {
  // Example usage
  vector<int> coins = {1, 2, 5};
  int amount = 11;

  int result = coinChange(coins, amount);

  cout << "Minimum number of coins needed: " << result << endl;

  return 0;
}
