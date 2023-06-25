// Latihan 3

#include <iostream>
#include <cmath>

using namespace std;

struct Persegi {
    int panjang, lebar, luas;
    Persegi (int panjang, int lebar) {
        this->panjang = panjang;
        this->lebar = lebar;
        this->luas = panjang * lebar;
    }
};

struct Lingkaran {
    int radius;
    float luas;
    Lingkaran (int radius) {
        this->radius = radius;
        this->luas = M_PI * pow(radius, 2);
    };
};

struct Kerucut {
    int radius, tinggi;
    float volume;
    Kerucut (int radius, int tinggi) {
        this->radius = radius;
        this->tinggi = tinggi;
        this->volume = 1.0 / 3.0 * M_PI * pow(float(radius), 2.0) * float(tinggi);
    };
};

struct Bola {
    int radius;
    float volume;
    Bola (int radius) {
        this->radius = radius;
        this->volume = 4.0 / 3.0 * M_PI * pow(float(radius), 3);
    }
};

int main()
{
    typedef struct Persegi TypePersegi;
    TypePersegi persegi = Persegi(3, 4);

    typedef struct Lingkaran TypeLingkaran;
    TypeLingkaran lingkaran = Lingkaran(2);

    typedef struct Kerucut TypeKerucut;
    TypeKerucut kerucut = Kerucut(2, 10);

    typedef struct Bola TypeBola;
    TypeBola bola = Bola(2);

    cout << "Luas persegi | panjang: " << persegi.panjang << ", lebar: " << persegi.lebar << " = " << persegi.luas << endl;
    cout << "Luas lingkaran | radius: " << lingkaran.radius << " = " << lingkaran.luas << endl;
    cout << "Voume kerucut | radius: " << kerucut.radius << ", tinggi: " << kerucut.tinggi << " = " << kerucut.volume << endl;
    cout << "Volume bola | radius: " << bola.radius << " = " << bola.volume << endl;
    return 0;
}
