//Artur Szydlowski_E04_cw5_1

#include <iostream>
#include <cmath>
using namespace std;

class figura {public: float a, b;
    figura() {};
    virtual void info() {};
    virtual float pole() {return a*b;}
    virtual float obwod() {return 2*a+2*b;}
};

class prostokat : public figura {
  public:
    prostokat(float aa, float bb) {a=aa, b=bb;}
    virtual void info() {
        cout << "Figura jest prostokatem o bokach " << a << " i " << b
                << ".\nJego pole wynosi " << pole() << " a obwod " << obwod() << ".\n\n";
    }
};

class kwadrat : public figura {
  public:
    kwadrat(float aa) {a=aa, b=aa;}
    virtual void info() {
        cout << "Figura jest kwadratem o boku " << a
            << ".\nJego pole wynosi " << pole() << " a obwod " << obwod() << ".\n\n";
    }
};

class trojkat : public figura {
  public:
    trojkat(float aa, float h) {a=aa, b=h;}
    virtual void info() {
        cout << "Figura jest trojkatem o podstawie " << a << " i wysokosci " << b
            << ".\nJego pole wynosi " << pole() << " a obwod " << obwod() << ".\n\n";
    }
    virtual float pole() {return a*b*0.5;}
    virtual float obwod() {return a+2*sqrt(a*a*0.25+b*b);}
};

class figura_przestrzenna {public: float H; int p;
    virtual float objetosc() {};
};

class graniastoslup : public figura, public figura_przestrzenna {
  public:
    graniastoslup(int podstawa, float aa, float h) {H=h, p=podstawa, a=aa; b=0;}
    graniastoslup(int prostopadloscian, float aa, float bb, float h) {H=h, p=4, a=aa, b=bb;}
    virtual void info() {
        cout << "Bryla jest graniastoslupem o wysokosci " << H << " o podstawie " ;
        if(b==0) cout << p << "-kata foremnego o boku " << a << endl;
        else cout << "prostokata o bokach " << a << " i " << b << endl;
        cout << "Calkowite pole powierzchni jego scian wynosi " << pole() << ", laczna dlugosc krawedzi " << obwod() << ", a objetosc " << objetosc() << "\n\n";
    }
    virtual float pole() {if(b==0) return p*0.5/tan(M_PI/p)*a*a + a*H*p; else return 2*(a*H+a*b+b*H);}
    virtual float obwod() {if(b==0) return 2*p*a + p*H; else return 4*(a+b+H);}
    virtual float objetosc() {if(b==0) return p*0.25/tan(M_PI/p)*a*a*H; else return a*b*H;}
};

class czworoscian : public figura_przestrzenna, trojkat{
  public:
    czworoscian(float aa) : trojkat(a,b) {a=aa, b=aa*sqrt(3)/2, H=aa*sqrt(6)/3;}
    virtual void info() {
        cout << "Bryla jest czworoscianem foremnym o boku " << a << " i objetosci " << objetosc()
                << "\nCalkowite pole powierzchni jego scian wynosi " << pole() << ", a laczna dlugosc krawedzi " << obwod() << endl;
    }
    virtual float objetosc() {return pole()*H/3;}
    virtual float pole() {return trojkat(a,b).pole()*4;}
    virtual float obwod() {return a*6;}
};


int main()
{
    cout << "P.) "; prostokat P(2,3); P.info();
    cout << "K.) "; kwadrat K(1.5); K.info();
    cout << "T.) "; trojkat T(4,2); T.info();
    cout << "G1.) "; graniastoslup G1(6, 2, 4); G1.info();
    cout << "G2.) "; graniastoslup G2(4,1,2,3); G2.info();
    cout << "CZ.) "; czworoscian CZ(1); CZ.info();
    return 0;
}
