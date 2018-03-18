#ifndef ASZGRAPH_H_INCLUDED
#define ASZGRAPH_H_INCLUDED

#define _WIN32_WINNT 0x0500
#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;

void gotoxy(short x, short y);
void kolor(unsigned char kolor);

class piksel {char z; unsigned char k; static char kol; static HANDLE hOut; //HANDLE piksel::hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    friend class obiekt;
    friend class ekran;
    piksel() : z(32), k(7) {};
    void kolorlit();
};

class punkt {unsigned char x, y;
    friend class obiekt;
    punkt(int xx, int yy) : x(xx), y(yy) {};
};

class obiekt {piksel **px; const int sx, sy; int x, y, o;
    char gradientk(float pr); //zwraca wartosc przeslony gradientu
public:
    obiekt(int xx, int yy) : sx(xx), sy(yy), x(xx), y(yy), o(0) {
        px = new piksel * [sx];
        for(int i=0; i<sx; i++) px[i] = new piksel [sy];
    }
    ~obiekt() {for(int i=0; i<sx; i++) delete [] px[i]; delete [] px;}

    void wyswietl(); //wyswietla obiekt w pkt. 0,0
    void wyswietl(short xx, short yy); //wyswietla obiekt w podanym pkt.
//    void info(); //podaje informacje na temat rozmiaru obiektu
//    void info(int xx, int yy); //podaje informacje na temat danego piksela
    void obroc(int kat); //zmienia tryb wyswietlania z xy na yx
    void wpisz(int xx, int yy, string co); //wpisuje tekst na piksele zaczynajac od pozycji (xx,yy)
//    unsigned char kolor(); //koduje wartosc koloru tla i liter
//    void kolortla(unsigned char k); //zmienia kolor tla konsoli
//    void kolorlit(unsigned char k); //zmienia kolor liter konsoli
    void kolorlit(unsigned char k, int xx, int yy, int dlugosc); //zmienia kolor liter na dlugosci n znakow
    void kolorlit(unsigned char k, int x1, int y1, int x2, int y2); //zmienia kolor liter wewnatrz prostokata
    void kolorbox(unsigned char k, bool typ, int x1, int y1, int x2, int y2); //maluje w tle(0) lub na warstwie(1) prostokat
    void rysujlinie(unsigned char k, unsigned char znak, int x1, int y1, int x2, int y2); //rysuje linie miedzy P(x1,y1) a P(x2,y2)
    void rysujbox(unsigned char k, int typ, int x1, int y1, int x2, int y2); //rysuje ramke
    void rysujkolo(unsigned char k, char znak, int x1, int y1, int R); //rysuje kolo
    void rysujokrag(unsigned char k, char znak, int x1, int y1, int R); //rysuje okrag
    void gradient(unsigned char k1, unsigned char k2, int typ, int x1, int y1, int x2, int y2); //tworzy prostokatny gradient kolorow w danej osi
    void kopiuj(obiekt &OB, int x1, int y1); //kopiuje piksele aktualnego obiektu do obiektu OB
    void wklej(obiekt &OB, int x1, int y1); //wkleja piksele obiektu OB do aktualnego obiektu
};

class ekran {obiekt *tymczasowy;
public:
    ekran() {};
    void wpisz(int xx, int yy, string co, unsigned char kol);
    void kolorbox(unsigned char k, bool typ, int x1, int y1, int x2, int y2);
    void rysujlinie(unsigned char k, unsigned char znak, int x1, int y1, int x2, int y2);
/*    void rysujbox(unsigned char k, int typ, int x1, int y1, int x2, int y2);
    void rysujkolo(unsigned char k, char znak, int x1, int y1, int R);
    void rysujokrag(unsigned char k, char znak, int x1, int y1, int R);
    void gradient(unsigned char k1, unsigned char k2, int typ, int x1, int y1, int x2, int y2);
*/
};

#endif // ASZGRAPH_H_INCLUDED
