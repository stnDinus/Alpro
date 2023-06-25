// Latihan 4

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Mahasiswa {
  // attributes
  char nim[14];
  string nama, jurusan;
  int tahunLulus;

  // constructor
  Mahasiswa (string nim, string nama, string jurusan, int tahunLulus) {
    strcpy(this->nim, nim.c_str());
    this->nama = nama;
    this->jurusan = jurusan;
    this->tahunLulus = tahunLulus;
  }

  // methods
  void printSelf () {
    cout << this->nim << "\t" << this->nama << "\t" << this->jurusan << "\t" << this->tahunLulus << endl;
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

  // dinamis
  vector<Mahasiswa> himpunanDinamisMahasiswa = {
    Mahasiswa("A11.2020.0123", "Andi", "Broadcast", 2023),
    Mahasiswa("A11.2010.0123", "Budi", "Sistem Informasi", 2013),
    Mahasiswa("A11.2000.0123", "Ali", "DKV", 2003),
    Mahasiswa("A11.1990.0123", "Siti", "Kesehatan", 1993)
  };

  // output
  cout << "HIMPUNAN STATIS MAHASISWA\n";
  for (Mahasiswa mhs : himpunanMahasiswa) {
    mhs.printSelf();
  }

  cout << "\n";

  cout << "HIMPUNAN DINAMIS MAHASISWA\n";
  for (Mahasiswa mhs : himpunanDinamisMahasiswa) {
    mhs.printSelf();
  }

  return 0;
}
