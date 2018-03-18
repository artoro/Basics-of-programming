//Artur Szydlowski_E04_cw4_2

#include <iostream>
#include <cmath>
using namespace std;

class punkt {float x, y;
  public:
    punkt() : x(0), y(0) {}
    punkt(float xx, float yy) : x(xx), y(yy) {}
    void ustawxy(float xx, float yy) {x=xx,y=yy;}
    void wypisz(string nazwa="P") {cout << nazwa << " = (" << x << ";" << y << ")\n";}
    float odleglosc(const punkt &P2) {return sqrt(pow(x-P2.x,2)+pow(y-P2.y,2));}
    void przesun(float xx, float yy) {x+=xx, y+=yy;}
    punkt obroc(float kat_alfa) {
        kat_alfa=kat_alfa*M_PI/180;
        punkt P(x*cos(kat_alfa)-y*sin(kat_alfa), x*sin(kat_alfa)+y*cos(kat_alfa));
        return P;
    }
};

class okrag {punkt S; float R;
  public:
    okrag(float Sx, float Sy, float r) : R(r) {S.ustawxy(Sx, Sy);}
    okrag(punkt SO, float r) : R(r) {S=SO;}
    void wypisz(string nazwa="O") {cout << "Srodek okregu " << nazwa << " o promieniu " << R << " znajduje sie w punkcie "; S.wypisz("S");}
    float pole() {return M_PI*R*R;}
    int kolizja(okrag O2) {
        float d=S.odleglosc(O2.S);
        if (abs(R-O2.R)<d && d<R+O2.R) return 2;
        if (d==abs(R-O2.R) || d==R+O2.R) return 1;
        return 0;
    }
};

int main ()
{
    punkt P(6,1);
    okrag O1(0,0,8), O2(P,4);
    O1.wypisz("O1");
    O2.wypisz("O2");
    cout << "Pole okregu O1 wynosi " << O1.pole() << endl;
    cout << "Pole okregu O2 wynosi " << O2.pole() << endl;
    cout << "Okregi O1 i O2 ";
    switch (O1.kolizja(O2)) {
        case 2: cout << "maja 2 punkty wspolne.\n"; break;
        case 1: cout << "maja 1 punkt wspolny.\n"; break;
        default: cout << "nie maja punktow wspolnych.\n";
    }
    return 0;
}
