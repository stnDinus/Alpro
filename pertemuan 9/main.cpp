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
  // isi "seed" pengacakan dengan waktu sekarang
  srand(std::chrono::steady_clock::now().time_since_epoch().count());

  // insialisasi a dan b dengan nilai acak -
  // antara argumen(parameter fungsi main) kedua dan ketiga -
  // jika ada argumen yang kurang,
  // default nilai minimal ke 0 atau maksimal ke 10 [[
  int a = (argc >= 2 ? std::stoi(argv[1]) : 1) + (rand() % ((argc >= 3 ? std::stoi(argv[2]) : 10) - (argc >= 2 ? std::stoi(argv[1]) : 1) + 1));
  int b = (argc >= 2 ? std::stoi(argv[1]) : 1) + (rand() % ((argc >= 3 ? std::stoi(argv[2]) : 10) - (argc >= 2 ? std::stoi(argv[1]) : 1) + 1));
  std::cout << "a = " << a << "\nb = " << b << std::endl;
  // ]]

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

