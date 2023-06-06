#include <array>
#include <iostream>
#include <chrono>

void insertionSwap (int arr[], int i) {
  // basis
  if (i == 0) return;

  if (arr[i - 1] > arr[i]) {
    std::swap(arr[i - 1], arr[i]);
  }

  // recurse
  insertionSwap(arr, i - 1);
}

void insertionSort (int arr[], int n, int lindex = 0) {
  // basis
  if (lindex == n) return;

  // for (int i = lindex; i > 0; i--) {
  //   if (arr[i - 1] > arr[i]) {
  //     std::swap(arr[i], arr[i - 1]);
  //   }
  // }
  insertionSwap(arr, lindex);

  // recurse
  insertionSort(arr, n, lindex + 1);
}

int main () {
  const int n = 10;
  int arr[n];

  // init
  for (int i = 0; i < n; i++) {
    srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    arr[i] = rand() % 100;
    std::cout << arr[i] << ", ";
  }
  std::cout << std::endl;

  insertionSort(arr, n);

  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << ", ";
  }

  return 0;
}
