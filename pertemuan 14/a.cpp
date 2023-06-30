#include "timer.hpp"
#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> * vec, int start_index, int end_index) {
  if (start_index < end_index) {
    // menggunakan titik acuan (pivot) elemen terakhir
    int pivot = (*vec)[end_index];

    // perbaiki index pivot [[
    int pivot_index = start_index - 1; // index pivot awal
    for (int i = start_index; i < end_index; i++) {
      if ((*vec)[i] < pivot) {
        swap((*vec)[i], (*vec)[++pivot_index]);
      }
    }
    swap((*vec)[++pivot_index], (*vec)[end_index]);
    // ]]

    // recurse fungsi quickSort
    quickSort(vec, start_index,
              pivot_index - 1); // dari elemen awal hingga sebelum pivot
    quickSort(vec, pivot_index + 1,
              end_index); // dari elemen setelah pivot hingga akhir
  }
}

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
