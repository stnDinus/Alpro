#include "timer.hpp"
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
using namespace std::chrono;

void quickSort(vector<int> *vec, int start_index, int end_index) {
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

  int n = 10;
  vector<int> iVec;
  cout << "Vector awal\t: ";
  for (int i = 0; i < 10; i++) {
    srand(high_resolution_clock::now().time_since_epoch().count());
    iVec.push_back(rand() % n);
    cout << iVec[i] << ", ";
  }
  cout << "\n";

  // sorting
  cout << "\nQuick Sort\n";
  {
    Timer timer;
    quickSort(&iVec, 0, n - 1);
  }

  // searching
  int lookFor = 4;

  cout << "\nMencari\t: " << lookFor << "\nPada\t: ";
  for (int i : iVec) {
    cout << i << ", ";
  }
  cout << "\n";

  cout << "\nLinear Search\n";
  int linearSearchRet;
  {
    Timer timer;
    linearSearchRet = linearSearch(iVec, lookFor);
  }
  cout << "Hasil Index\t: " << linearSearchRet << "\n";

  cout << "\nBinary Search\n";
  int binarySearchRet;
  {
    Timer timer;
    binarySearchRet = binarySearch(iVec, lookFor, iVec.size());
  }
  cout << "Hasil Index\t: " << binarySearchRet << "\n";

  cout << "\nMain\n";
  return 0;
}
