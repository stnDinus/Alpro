#include "search.hpp"

int binarySearch(vector<int> vec, int lookFor, int endIndex, int startIndex) {
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
