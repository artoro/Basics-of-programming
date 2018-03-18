//Artur Szydlowski_E04_cw6_1

#include <iostream>
#include <cmath>
using namespace std;

class wektor {public: float x, y;
    wektor(float X, float Y) : x(X), y(Y) {};
    float operator! () {return sqrt(x*x+y*y);} //dlugosc wektora
    float operator* (const wektor &W) {return x*W.x + y*W.y;} //iloczyn skalarny dwoch wektorow
};

wektor operator* (const wektor &W, float k) {return wektor(W.x*k,W.y*k);} //iloczyn wektora przez liczbe skalarna
wektor operator* (float k, const wektor &W) {return W*k;}
ostream& operator<< (ostream &S, const wektor &W) {S<<'['<<W.x<<','<<W.y<<']'; return S;}

int main()
{
    wektor W1(1,2), W2(4,3);
    cout << "Utworzono dwa wektory: " << W1 << " o dlugosci " << !W1
        << " i wektor " << W2 << " o dlugosci " << !W2 << ".\n\nDzialania: " << endl
        << W1 << "*2 = " << W1*2 << endl
        << "3*" << W2 << " = " << 3*W2 << endl
        << W1 << "*" << W2 << " = " << W1*W2 << endl;
    return 0;
}
