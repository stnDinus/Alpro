#include <array>
#include <chrono>
#include <iostream>

using namespace std;

// Paradigma "Divide & Conquer":
// =============================
// sebuah metode algoritma yang membelah dua sebuah masalah,
// hingga jumlah minimum masalah dapat diproses.

void insertionSwap(int arr[], int i) {
  // basis
  if (i == 0)
    return;

  if (arr[i - 1] > arr[i]) {
    swap(arr[i - 1], arr[i]);
  }

  // recurse
  insertionSwap(arr, i - 1);
}

void insertionSort(int arr[], int n, int lindex = 0) {
  // basis
  if (lindex == n)
    return;

  // for (int i = lindex; i > 0; i--) {
  //   if (arr[i - 1] > arr[i]) {
  //     swap(arr[i], arr[i - 1]);
  //   }
  // }
  insertionSwap(arr, lindex);

  // recurse
  insertionSort(arr, n, lindex + 1);
}

void bubbleSwap(int arr[], int n, int lindex = 0) {
  // basis
  if (lindex == n)
    return;

  if (arr[lindex] > arr[lindex + 1]) {
    swap(arr[lindex], arr[lindex + 1]);
  }

  // recurse
  bubbleSwap(arr, n, lindex + 1);
}

void bubbleSort(int arr[], int n, int lindex = 0) {
  // basis
  if (lindex == n - 1)
    return;

  // for (int i = 0; i < n - lindex - 1; i++) {
  //   if (arr[i] > arr[i + 1]) {
  //     swap(arr[i], arr[i + 1]);
  //   }
  // }
  bubbleSwap(arr, n - lindex - 1);

  // recurse
  bubbleSort(arr, n, lindex + 1);
}

int selectionSwap(int arr[], int n, int minIndex, int lindex = 0) {
  // basis
  if (lindex == n)
    return minIndex;

  if (arr[minIndex] > arr[lindex])
    minIndex = lindex;

  // return recurse
  return selectionSwap(arr, n, minIndex, lindex + 1);
};

void selectionSort(int arr[], int n, int lindex = 0) {
  // basis
  if (lindex == n - 1)
    return;

  int minIndex = selectionSwap(arr, n, lindex, lindex);
  // int minIndex = lindex;
  // for (int i = lindex + 1; i < n; i++) {
  //   if (arr[minIndex] > arr[i]) minIndex = i;
  // }
  swap(arr[minIndex], arr[lindex]);

  // recurse
  selectionSort(arr, n, lindex + 1);
}

int linearSearch(int arr[], int n, int lookFor) {
  // basis
  if (n < 0)
    return -1;

  if (arr[n] == lookFor)
    return n;

  // recurse
  return linearSearch(arr, n - 1, lookFor);
}

// ketentuan: array telah terurut
int binarySearch(int arr[], int lookFor, int startIndex, int endIndex) {
  int sliceLength = endIndex - startIndex;
  int midIndex = startIndex + (sliceLength / 2);

  if (sliceLength == 1) {
    if (arr[startIndex] == lookFor) {
      return startIndex;
    } else {
      return -1;
    }
  }

  if (arr[midIndex] <= lookFor) {
    return binarySearch(arr, lookFor, midIndex, endIndex);
  } else {
    return binarySearch(arr, lookFor, startIndex, midIndex);
  }
}

int main() {
  const int n = 10;
  int arr[n], pilih;

  // init untuk array (random)
  cout << "Array yang digunakan : ";
  for (int i = 0; i < n; i++) {
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    arr[i] = rand() % 100;
    cout << arr[i] << ", ";
  }
  cout << endl;

  do {
    cout << "\n" <<
            "Menu Pilihan" << endl <<
            "===============================\n" <<
            "1. Rekursif Selection Sort\n" <<
            "2. Rekursif Bubble Sort\n" <<
            "3. Rekursif Insertion Sort\n" <<
            "4. Rekursif Linear Search\n" <<
            "5. Rekursif Binary Search\n" <<
            "0. Keluar Program\n" <<
            "===============================\n" <<
            "Masukan pilihan : ";
    cin >> pilih;
    cout << endl;

    if (pilih == 1) {
      selectionSort(arr, n);

      // Untuk menampilkan Hasilnya
      cout << "Hasil Array setelah di proses : ";
      for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
      }
      cout << endl;

    } else if (pilih == 2) {
      bubbleSort(arr, n);

      // Untuk menampilkan Hasilnya
      cout << "Hasil Array setelah di proses : ";
      for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
      }
      cout << endl;

    } else if (pilih == 3) {
      insertionSort(arr, n);

      // Untuk menampilkan Hasilnya
      cout << "Hasil Array setelah di proses : ";
      for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
      }
      cout << endl;

    } else if (pilih == 4) {
      for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
      }
      cout << endl;

      int lookFor;
      cout << "Masukan yang akan di cari: ";
      cin >> lookFor;

      int isFoundIndex = linearSearch(arr, n - 1, lookFor);
      if (isFoundIndex == -1) {
        cout << lookFor << " tidak ditemukan dalam Array";
      } else {
        cout << "Pada indeks ke-" << isFoundIndex;
      }
      cout << endl;
    } else if (pilih == 5) {
      // binarySearch memerlukan array untuk urut terlebih dahulu
      insertionSort(arr, n);

      for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
      }
      cout << endl;

      int lookFor;
      cout << "Masukan yang akan di cari :";
      cin >> lookFor;

      int isFoundIndex = binarySearch(arr, lookFor, 0, n-1);
      if (isFoundIndex == -1) {
        cout << lookFor << " tidak ditemukan dalam Array";
      } else {
        cout << "Pada indeks ke-" << isFoundIndex;
      }
      cout << endl;
    } else if (pilih > 5) {
      cout << "********************************* \n"
              "* Maaf, pilih sesuai menu saja! * \n"
              "*********************************" << endl;
    }
  } while (pilih != 0);

  return 0;
}
