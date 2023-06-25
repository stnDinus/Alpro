// Latihan Enum

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// panjang segmen IP
enum TipeIP {
  IPV4 = 4,
  IPV6 = 8,
};

struct IP {
  // attributes
  TipeIP tipe;
  string pemisah;
  vector<int> alamat;

  // constructor
  IP(TipeIP tipe, string alamat) {
    this->tipe = tipe;
    // tentukan pemisah segmen IP sesuai dengan tipe-nya
    this->pemisah = tipe == IPV4 ? "." : "::";

    int startPos = 0;
    int endPos = alamat.find(pemisah, startPos);
    while (endPos != string::npos) {
      endPos = alamat.find(pemisah, startPos);

      try {
        this->alamat.push_back(
            stoi(alamat.substr(startPos, endPos - startPos)));
      } catch (...) {
        cerr << "Peringatan: segment alamat ke-" << alamat.size() + 1
             << " bukan integer valid" << endl;
      }

      startPos = endPos + (tipe == IPV4 ? 1 : 2);
    }
  }

  // methods
  void info() {
    // tentukan nama tipe ip sesuai dengan tipe-nya
    cout << "Tipe\t: " << (this->tipe == IPV4 ? "IPV4" : "IPV6") << endl;
    cout << "Pemisah\t: " << this->pemisah << endl;
    int jmlSegmen = this->alamat.size();
    cout << jmlSegmen << "/" << this->tipe << " buah segmen" << endl;
    for (int i = 0; i < jmlSegmen; i++) {
      cout << "SEGMEN KE-" << i + 1 << "\t: " << this->alamat[i] << endl;
    }
  }
};

int main() {
  // instances
  IP localhostV4 = IP(IPV4, "127.0.0.1");
  IP localhostV6 = IP(IPV6, "::1");

  // print
  localhostV4.info();
  cout << endl;
  localhostV6.info();

  return 0;
}
