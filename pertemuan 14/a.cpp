#include "search.hpp"
#include "sort.hpp"
#include "timer.hpp"
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
using namespace std::chrono;

int main() {
  Timer timer;

  cout << "┌─────────┐\n";
  cout << "│ SORTING │\n";
  cout << "└─────────┘\n";

  int n = 10;
  vector<int> iVec;
  cout << "Vector awal\t: ";
  for (int i = 0; i < 10; i++) {
    srand(high_resolution_clock::now().time_since_epoch().count());
    iVec.push_back(rand() % n);
    cout << iVec[i] << ", ";
  }
  cout << "\n";

  cout << "\nBubble Sort\n";
  cout << "Time Complexity\t: O(n^2)\n";
  cout << "Space Complexity: O(1)\n";
  vector<int> bubbleSortIVec = iVec;
  {
    Timer timer;
    bubbleSort(&bubbleSortIVec);
  }

  cout << "\nInsertion Sort\n";
  cout << "Time Complexity\t: O(n^2)\n";
  cout << "Space Complexity: O(1)\n";
  vector<int> insertionSortIVec = iVec;
  {
    Timer timer;
    insertionSort(&insertionSortIVec);
  }

  cout << "\nQuick Sort\n";
  cout << "Time Complexity\t: O(log n)\n";
  cout << "Space Complexity: O(log n)\n";
  {
    Timer timer;
    quickSort(&iVec, 0, n - 1);
  }

  cout << "┌───────────┐\n";
  cout << "│ SEARCHING │\n";
  cout << "└───────────┘\n";

  int lookFor = 4;

  cout << "\nMencari\t: " << lookFor << "\nPada\t: ";
  for (int i : iVec) {
    cout << i << ", ";
  }
  cout << "\n";

  cout << "\nLinear Search\n";
  cout << "Time Complexity\t: O(n)\n";
  cout << "Space Complexity: O(1)\n";
  int linearSearchRet;
  {
    Timer timer;
    linearSearchRet = linearSearch(iVec, lookFor);
  }
  cout << "Hasil Index\t: " << linearSearchRet << "\n";

  cout << "\nBinary Search\n";
  cout << "Time Complexity\t: O(log n)\n";
  cout << "Space Complexity: O(log n)\n";
  int binarySearchRet;
  {
    Timer timer;
    binarySearchRet = binarySearch(iVec, lookFor, iVec.size());
  }
  cout << "Hasil Index\t: " << binarySearchRet << "\n";

  cout << "\nMain\n";
  return 0;
}
