#include "sort.hpp"

void bubbleSort(vector<int> *vec) {
  for (int i = 0; i < vec->size(); i++) {
    for (int j = 0; j < vec->size() - i - 1; j++) {
      if ((*vec)[j] > (*vec)[j + 1]) {
        swap((*vec)[j], (*vec)[j + 1]);
      }
    }
  }
}

void insertionSort(vector<int> *vec) {
  for (int i = 0; i < vec->size(); i++) {
    int minIndex = i;
    for (int i2 = i; i2 < vec->size(); i2++) {
      if ((*vec)[i2] < (*vec)[minIndex])
        minIndex = i2;
    }
    swap((*vec)[i], (*vec)[minIndex]);
  }
}

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
