#include <algorithm>
#include <iostream>
#include <chrono>
#include <random>

using namespace std;

bool cekGanjil(int i) {
  return !(i % 2 == 0);
}

void cetakGenapTerkecil(int array[], int n) {
  int tempIndex = -1;
  int temp;

  for (int i = 0; i < n; i++) {
    // jika bilangan pada index i genap
    if (!cekGanjil(array[i])) {
      // simpan bilangan genap ke jika belum ada
      if (tempIndex == -1) {
        tempIndex = i;
        temp = array[tempIndex];
      }
      // bandingkan bilangan genap terkecil
      if (array[i] < temp) {
        tempIndex = i;
        temp = array[tempIndex];
      }
    }
  }

  // cetak jika ada bilangan ganjil terkecil
  if (!cekGanjil(temp) && tempIndex != -1) {
    cout << "Bilangan genap terkecil: " << temp << ", dengan index: " << tempIndex;
  } else {
    cout << "Tidak ada bilangan genap";
  }
  cout << endl;
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void bubbleSort (int array[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (array[j] < array[j + 1]) {
        swap(array[j], array[j + 1]);
      }
    }
  }
}

void quickSort (int array[], int start_index, int end_index) {
  if (start_index < end_index) {
    // menggunakan titik acuan (pivot) elemen terakhir
    int pivot = array[end_index];

    // perbaiki index pivot [[
    int pivot_index = start_index - 1; // index pivot awal
    for (int i = start_index; i < end_index; i++) {
      if (array[i] < pivot) {
        pivot_index++;
        swap(array[i], array[pivot_index]);
      }
    }
    swap(array[++pivot_index], array[end_index]);
    // ]]

    // recurse fungsi quickSort
    quickSort(array, start_index, pivot_index - 1); // dari elemen awal hingga sebelum pivot
    quickSort(array, pivot_index + 1, end_index); // dari elemen setelah pivot hingga akhir
  }
}

int main() {
  const int n = 5;
  int array[n];
  cout << "Array awal: ";
  for (int i = 0; i < n; i++) {
    srand(std::chrono::steady_clock::now().time_since_epoch().count());
    array[i] = rand() % 100;
    cout << array[i] << ", ";
  }
  cout << endl;

  cetakGenapTerkecil(array, n);

  bubbleSort(array, n);

  cout << "Array terurut (bubble sort): ";
  for (int i = 0; i < n; i++) {
    cout << array[i] << ", ";
  }
  cout << endl;

  cout << endl;
  int array2[n];
  cout << "Array2 awal: ";
  for (int i = 0; i < n; i++) {
    srand(std::chrono::steady_clock::now().time_since_epoch().count());
    array2[i] = rand() % 100;
    cout << array2[i] << ", ";
  }
  cout << endl;

  quickSort(array2, 0, n - 1);

  cout << "Array2 terurut (quick sort): ";
  for (int i = 0; i < n; i++) {
    cout << array2[i] << ", ";
  }
  cout << endl;
  return 0;
}

