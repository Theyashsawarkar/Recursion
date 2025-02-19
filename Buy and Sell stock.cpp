#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

/*
 * in both the approaches the intution is simple we cheak two things every day ,
   if price is lower than last lower price if so we update the lower price
   we also cheak for the profit , we cheak can we sell the stock today ,
   if the profit is gretter than last profit then we update the maxProfit
*/

// Recursive approach
void findMaxProfitRecursive(vector<int> &prices, int index, int &minPrice,
                            int &maxProfit) {
  // Base case: If we reach the end of the prices vector
  if (index == prices.size()) {
    return;
  }

  // Update minimum price encountered so far
  if (prices[index] < minPrice) {
    minPrice = prices[index];
  }

  // Calculate profit if we sell today
  int todayProfit = prices[index] - minPrice;

  // Update maximum profit if today's profit is greater
  if (maxProfit < todayProfit) {
    maxProfit = todayProfit;
  }

  // Recursive call for the next day
  findMaxProfitRecursive(prices, index + 1, minPrice, maxProfit);
}

int maxProfitRecursive(vector<int> &prices) {
  int maxProfit = 0; // Initialize maxProfit to 0
  int minPrice = INT_MAX;

  // Start the recursive process to find maximum profit
  findMaxProfitRecursive(prices, 0, minPrice, maxProfit);

  return maxProfit;
}

// Iterative approach
int maxProfitIterative(vector<int> &prices) {
  int maxProfit = 0; // Initialize maxProfit to 0
  int minPrice = INT_MAX;

  for (int i = 0; i < prices.size(); i++) {
    // Update minimum price encountered so far
    if (prices[i] < minPrice) {
      minPrice = prices[i];
    }

    // Calculate profit if we sell today
    int todayProfit = prices[i] - minPrice;

    // Update maximum profit if today's profit is greater
    if (maxProfit < todayProfit) {
      maxProfit = todayProfit;
    }
  }

  return maxProfit;
}

int main() {
  vector<int> prices = {7, 1, 5, 3, 6, 4};

  // Using recursive approach
  int resultRecursive = maxProfitRecursive(prices);
  cout << "Maximum Profit (Recursive): " << resultRecursive << endl;

  // Using iterative approach
  int resultIterative = maxProfitIterative(prices);
  cout << "Maximum Profit (Iterative): " << resultIterative << endl;

  return 0;
}

/*
    Time Complexity (Recursive Approach):
    - The function 'findMaxProfitRecursive' is called recursively, and it
   iterates through the prices vector. In the worst case, it visits each element
   once.
    - Therefore, the time complexity is O(n), where 'n' is the size of the
   prices vector.

    Space Complexity (Recursive Approach):
    - The space complexity is O(n) due to the function call stack during
   recursion.

    Time Complexity (Iterative Approach):
    - The loop iterates through the prices vector once. Therefore, the time
   complexity is O(n), where 'n' is the size of the prices vector.

    Space Complexity (Iterative Approach):
    - The space complexity is O(1) as no additional data structures are used,
   and the function call stack is the only significant use of memory.
*/
