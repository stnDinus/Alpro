#include <iostream>
#include <vector>
#include "timer.hpp"

using namespace std;

template <typename T>
int linearSearch (vector<T> vec, T lookFor) {
  Timer timer;
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] == lookFor) {
      return i;
    }
  }

  return -1;
}

int main () {
  Timer timer;

  vector<int> iVec = {1, 2, 3};

  int lookFor = 4;
  int foundIndex = linearSearch(iVec, lookFor);
  cout << "Linear Search: \t" << foundIndex << endl;

  cout << endl << "Main " << endl;
  return 0;
}
