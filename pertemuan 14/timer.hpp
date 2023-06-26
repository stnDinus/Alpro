#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

/**
 * Hitung waktu yang dibutuhkan untuk menjalankan sebuah "scope" (antara "{" dan "}")
 *
 * saat constructor dipanggil (saat sebuah instansi terinisialisasi pada sebuah
 * "scope"):
 * - mulai awal timer
 *
 * saat destructor dipanggil (saat instansi Timer akan meninggalkan "scope" inisialisasi)
 * - mulai akhir timer
 * - outputkan selisih akhir - awal
*/
struct Timer {
  int start, end;

  Timer() {
    start = high_resolution_clock::now().time_since_epoch().count();
  }

  ~Timer() {
    end = high_resolution_clock::now().time_since_epoch().count();
    const auto duration = end - start;
    cout << endl << "Took\t: " << duration << endl;
  }
};

