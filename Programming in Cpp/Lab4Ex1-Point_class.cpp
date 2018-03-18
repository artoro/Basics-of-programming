//Artur Szydlowski_E04_cw4_1

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

int main()
{
    punkt P1, P2(4,5);
    P1.ustawxy(1,1);
    P1.wypisz("P1");
    P2.wypisz("P2");
    cout << "Odleglosc punktu P1 od punktu P2 wynosi " << P1.odleglosc(P2) << endl;
    P1.przesun(-1,12);
    cout << "Po przesunieciu punktu P1 o wektor [-1,12] ";
    P1.wypisz("P1");
    cout << "Po obroceniu punktu P1 wzgledem poczatku ukladu wspolrzednych o kat 45 stopni, mialby on wspolrzedne: ";
    (P1.obroc(45)).wypisz();
    return 0;
}
