#pragma once

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
                 int startIndex = 0);
