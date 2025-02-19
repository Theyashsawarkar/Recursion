
#include <iostream>
#include <vector>

using namespace std;

// TODO: dry run and understand this algorithm
// https://www.naukri.com/code360/problems/tower-of-hanoi_981323?leftPanelTabValue=SOLUTION

// Function to move disks from one rod to another
void moveDisks(int numDisks, int destinationRod, int sourceRod,
               vector<vector<int>> &moves) {
  // If there's only one disk, move it directly from sourceRod to destinationRod
  if (numDisks == 1) {
    moves.push_back({sourceRod, destinationRod});
    return;
  }

  // Calculate the intermediate rod (neither sourceRod nor destinationRod)
  int intermediateRod = 1 ^ 2 ^ 3 ^ destinationRod ^ sourceRod;

  // Move the top numDisks-1 disks to the intermediateRod
  moveDisks(numDisks - 1, intermediateRod, sourceRod, moves);

  // Move the nth disk to the destinationRod
  moves.push_back({sourceRod, destinationRod});

  // Move the numDisks-1 disks from intermediateRod to destinationRod
  moveDisks(numDisks - 1, destinationRod, intermediateRod, moves);
}

// Function to solve the Tower of Hanoi puzzle
vector<vector<int>> towerOfHanoi(int numDisks) {
  // Vector to store the moves
  vector<vector<int>> moves;

  // Initiate the process of moving disks from rod 1 to rod 2
  moveDisks(numDisks, 2, 1, moves);

  // Return the recorded moves
  return moves;
}

int main() {
  int numDisks;
  cout << "Enter the number of disks: ";
  cin >> numDisks;

  // Get the moves required to solve the Tower of Hanoi puzzle
  vector<vector<int>> moves = towerOfHanoi(numDisks);

  // Output the moves
  cout << "Moves required to solve Tower of Hanoi with " << numDisks
       << " disks:" << endl;
  for (const auto &move : moves) {
    cout << "Move disk from rod " << move[0] << " to rod " << move[1] << endl;
  }

  return 0;
}
