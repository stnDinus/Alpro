#include "timer.hpp"
#include <iostream>
#include <vector>

using namespace std;

template <typename T> int linearSearch(vector<T> vec, T lookFor) {
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] == lookFor) {
      return i;
    }
  }

  return -1;
}

int binarySearch(vector<int> vec, int lookFor, int endIndex,
                 int startIndex = 0) {
  int sliceLength = endIndex - startIndex;
  int midIndex = startIndex + (sliceLength / 2);

  if (sliceLength == 1) {
    if (vec[startIndex] == lookFor) {
      return startIndex;
    } else {
      return -1;
    }
  }

  if (vec[midIndex] <= lookFor) {
    return binarySearch(vec, lookFor, endIndex, midIndex);
  } else {
    return binarySearch(vec, lookFor, midIndex, startIndex);
  }
}

int main() {
  Timer timer;

  vector<int> iVec = {1, 2, 3};

  // searching
  int lookFor = 4;

  {
    Timer timer;
    cout << "Linear Search\t: " << linearSearch(iVec, lookFor) << endl;
  }

  {
    Timer timer;
    cout << "Binary Search\t: " << binarySearch(iVec, lookFor, iVec.size())
         << endl;
  }

  cout << "Main " << endl;
  return 0;
}
