// Latihan 5

#include <iostream>
#include <string>

using namespace std;

struct Sepeda {
  string  merk, type;
  int tahun, harga;
};

int main () {
  Sepeda sepeda = Sepeda{"Polygon", "BMX", 2013, 2000000};
  Sepeda * pSepeda = &sepeda;

  pSepeda->type = "Sepeda Gunung";

  cout << pSepeda->type << endl;

  return 0;
}
