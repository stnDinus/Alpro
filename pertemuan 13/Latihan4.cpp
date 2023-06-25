// Latihan 4

#include <cstring>
#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
  char nim[15];
  string nama, jurusan;
  int tahunLulus;

  Mahasiswa (string nim, string nama, string jurusan, int tahunLulus) {
    strcpy(this->nim, nim.c_str());
    this->nama = nama;
    this->jurusan = jurusan;
    this->tahunLulus = tahunLulus;
  }
};

int main () {
  // statis
  Mahasiswa himpunanMahasiswa[] = {
    Mahasiswa("A11.2020.0123", "Andi", "Broadcast", 2023),
    Mahasiswa("A11.2010.0123", "Budi", "Sistem Informasi", 2013),
    Mahasiswa("A11.2000.0123", "Ali", "DKV", 2003),
    Mahasiswa("A11.1990.0123", "Siti", "Kesehatan", 1993)
  };

  return 0;
}
