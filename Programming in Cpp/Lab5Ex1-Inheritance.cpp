//Artur Szydlowski_E04_cw5_2

#include <iostream>
#include <cmath>
using namespace std;

class dana {public: float x;
    dana() {};
    dana(dana &D) : x(D.x) {};
    virtual bool isvalid(float we) {
        if(cin.good() && !cin.fail()) {cin.clear(); cin.sync(); return false;}
        cout << " BLAD!\n"; cin.clear(); cin.sync(); return true;
    };
    virtual void wypisz() {cout << "Dana ma wartosc " << x;};
    float get() {return x;};
};

class odcinek : public dana {
  public:
    odcinek() {float we=0; do {cout << "Podaj dlugosc odcinka "; cin>>we;} while (isvalid(we)); x=we;}
    virtual bool isvaild(float we) {
        if(cin.good() && !cin.fail() && we>0) {cin.clear(); cin.sync(); return false;}
        cout << " BLAD!\n"; cin.clear(); cin.sync(); return true;
    }
    virtual void wypisz() {cout << "Dlugosc odcinka wynosi " << x << endl;}
};

class kat : public dana {
  public:
    kat() {float we=-1; do {cout << "Podaj wartosc kata w stopniach "; cin>>we;} while (isvalid(we)); x=we;}
    virtual bool isvalid(float we) {
        if(cin.good() && !cin.fail() && we>=0 && we<=360) {cin.clear(); cin.sync(); return false;}
        cout << " BLAD!\n"; cin.clear(); cin.sync(); return true;
    }
    virtual void wypisz() {cout << "Miara kata wynosi " << x << " stopni" << endl;}
};

int main ()
{
    odcinek d;
    d.wypisz();
    cout << "Funkcja get() zwraca dlugosc odcinka " << d.get() << "\n\n";

    kat k1, k2(k1);
    k1.wypisz();
    cout << "Funkcja get() zwraca miare kata rowna " << k1.get() << endl;
    cout << "Drugi kat skopiowany zostal konstruktorem kopiujacym i wynosi " << k2.get() << endl;
    return 0;
}
