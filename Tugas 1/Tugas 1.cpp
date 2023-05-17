#include <iostream>

using namespace std;

// 1) fungsi penambahan
int penjumlahan (int a, int b) {
  return a + b;
}

// 2) fungsi pengurangan
int pengurangan (int a, int b) {
  return a - b;
}

// 3) fungsi jumlah nilai total sebuah array integer
int penjumlahanArray (int arr[], int panjangArray) {
  int hasil = 0;
  for (int i = 0; i < panjangArray; i++) {
    hasil += arr[i];
  }
  return hasil;
}

// 4) fungsi rata-rata
float rataRata (int jumlah, int panjang) {
  return float(jumlah) / float(panjang);
}

int main (int argc, char *argv[])
{
  int a;
  int b;
  cout << "Masukan nilai 'a' dan 'b':\n";
  cin >> a >> b;

  // 1) penjumlahan
  cout << a << " + " << b << "\t\t= " << penjumlahan(a, b) << endl;
  // 2) pengurangan
  cout << a << " - " << b << "\t\t= " << pengurangan(a, b) << endl;

  cout << "Masukan panjang array: ";
  int panjangArray;
  cin >> panjangArray;
  int array[panjangArray];
  for (int i = 0; i < panjangArray; i++) {
    cout << "Masukan nilai array deret ke-" << i + 1 << ": ";
    cin >> array[i];
  }

  // 3) penjumlahanArray
  int jumlahArray = penjumlahanArray(array, panjangArray);
  cout << "Jumlah array\t= " << jumlahArray << endl;
  // 4) ratarataArray
  cout << "Rata-rata array\t= " << rataRata(jumlahArray, panjangArray) << endl;
  return 0;
}

