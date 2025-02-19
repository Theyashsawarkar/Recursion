#include <bits/stdc++.h>
using namespace std;

// Merge function to combine two sorted subarrays
void merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right,
           long &inversions) {
  int leftIdx = left;
  int rightIdx = mid + 1;
  int k = left;

  // Merge the subarrays while counting inversions
  while (leftIdx <= mid && rightIdx <= right) {
    if (arr[leftIdx] <= arr[rightIdx]) {
      temp[k++] = arr[leftIdx++];
    } else {
      temp[k++] = arr[rightIdx++];
      inversions += mid - leftIdx + 1; // Count inversions
                                       // if i th element is gretter
                                       // than j th element then all the
                                       // elements from i to mid are
                                       // abouve the j since arrays are sorted
    }
  }

  // Copy remaining elements from left subarray
  while (leftIdx <= mid) {
    temp[k++] = arr[leftIdx++];
  }

  // Copy remaining elements from right subarray
  while (rightIdx <= right) {
    temp[k++] = arr[rightIdx++];
  }

  // Copy merged elements back to original array
  while (left <= right) {
    arr[left] = temp[left];
    left++;
  }
}

// Merge Sort function to recursively divide and merge the array
void mergeSort(vector<int> &arr, vector<int> &temp, int left, int right,
               long &inversions) {
  if (left >= right) {
    return;
  }

  int mid = left + (right - left) / 2;

  // Recursively sort the two halves
  mergeSort(arr, temp, left, mid, inversions);
  mergeSort(arr, temp, mid + 1, right, inversions);

  // Merge the two sorted halves
  merge(arr, temp, left, mid, right, inversions);
}

// Function to count inversions in the given array
long countInversions(vector<int> arr) {
  long inversions = 0;
  vector<int> temp(arr.size());

  mergeSort(arr, temp, 0, arr.size() - 1, inversions);

  return inversions;
}

int main() {
  // Example usage
  vector<int> inputArray = {1, 3, 5, 2, 4, 6};
  long result = countInversions(inputArray);
  cout << "Number of inversions: " << result << endl;

  return 0;
}

/*
 * INTUTION :
 *    in mergeSort when the j th element is smaller than the i th element
 *    thats when the inversions happen so we count them up to get out answer .
 *    but since the arrays are sorted if j th element is
 *    smaller than i th element then all the elements from i to
 *    mid are gretter than j th element so we count them all in
 *    the inversions as we will need to invert them to get the array sorted
 */

/*
   Time Complexity:
   - The merge sort algorithm has a time complexity of O(n log n) in all cases.

   Space Complexity:
   - The code uses additional space for the temporary array used in the merge
   process.
   - The space complexity is O(n) due to the recursion depth of the merge sort
   algorithm.
*/
