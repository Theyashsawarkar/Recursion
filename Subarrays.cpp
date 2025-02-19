#include <iostream>
using namespace std;

// Function to print subarrays
void printSubarrays(int arr[], int n, int start, int end) {
  // Base case: If start is at the last element, no subarray to print
  if (start >= n - 1) {
    return;
  }

  // When end pointer reaches the end of the array, move start to next element
  // to print the next batch of subarrays
  if (end == n) {
    start = start + 1;
    end = start;
  }

  // Print elements from start to end
  for (int i = start; i <= end; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Recursive call with updated end pointer
  printSubarrays(arr, n, start, end + 1);
}

int main() {
  int n;

  // Input the size of the array
  cin >> n;

  int arr[n];

  // Input elements of the array
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // Call function to print all possible subarrays
  printSubarrays(arr, n, 0, 0);
}
/*
Time Complexity Analysis:
  - The function `printSubarrays` is called recursively, exploring all possible
subarrays.
  - The number of subarrays in an n-element array is (n * (n+1)) / 2.
  - Therefore, the time complexity is O(n^2) due to nested loops.

Space Complexity Analysis:
  - The space complexity is O(n) due to the space required to store the input
array of size n.

Overall:
  - The code efficiently prints all possible subarrays of the given input array.
*/
