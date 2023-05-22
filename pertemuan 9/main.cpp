#include <iostream>
#include <chrono>
#include <random>

// FUNGSI - FUNGSI REKURSIF [[
int penjumlahan (int a, int b) {
  if (b == 0) return a;
  return 1 + penjumlahan(a, b-1);
};

int pengurangan (int a, int b) {
  if (b == 0 ) return a;
  return pengurangan(a, b - 1) - 1;
};

int perkalian (int a, int b) {
  if (b == 1) return a;
  return a + perkalian(a, b - 1);
};

// hanya bersifat "rekursif" jika bilangan dapat dibagi bulat
float pembagian (int a, int b, int c = 1) {
  if (c * b == a || c > a) {
    if (a % c == 0) return c;
    // fallback jika bukan bilangan bulat
    return float(a) / b;
  }
  return pembagian(a, b, c + 1);
}

int pangkat (int a, int b) {
  if (b == 1) return a;
  return pangkat(a, b-1) * a;
};
// ]]

int main (int argc, char *argv[]) {
  // nilai default [[
  int min = 0;
  int max = 10;
  bool acak = true;
  int a = 6;
  int b = 3;
  // ]]

  // proses argumen-argumen parameter fungsi main untuk override nilai-nilai default [[
  bool skip = false;
  for (int i = 1; i < argc; i++) {
    if (skip) {
      skip = false;
      continue;
    }
    if (argv[i][0] == '-') {
      switch(argv[i][1]) {
        case 'm': // min
          min = std::stoi(argv[i+1]);
          skip = true;
          break;
        case 'M': // max
          max = std::stoi(argv[i+1]);
          skip = true;
          break;
        case 'a':
          a = std::stoi(argv[i+1]);
          skip = true;
          acak = false;
          break;
        case 'b':
          b = std::stoi(argv[i+1]);
          skip = true;
          acak = false;
          break;
      }
    }
  }
  // ]]


  if (acak) {
    // isi "seed" pengacakan dengan waktu sekarang
    srand(std::chrono::steady_clock::now().time_since_epoch().count());
    // insialisasi a dan b dengan nilai acak antara min dan max
    a = min + (rand() % (min - max + 1));
    b = min + (rand() % (min - max + 1));
  }
  std::cout << "a = " << a << "\nb = " << b << std::endl;

  // PEMANGGILAN DAN PENCETAKAN HASIL FUNGSI [[
  std::cout
    << "Penjumlahan = "
    << penjumlahan(a, b)
    << std::endl;

  std::cout
    << "Pengurangan = "
    << pengurangan(a, b)
    << std::endl;

  std::cout
    << "Perkalian = "
    << perkalian(a, b)
    << std::endl;

  std::cout
    << "Pembagian = "
    << pembagian(a, b)
    << std::endl;

  std::cout
    << "Pangkat = "
    << pangkat(a, b)
    << std::endl;
  // ]]

  return 0;
}

