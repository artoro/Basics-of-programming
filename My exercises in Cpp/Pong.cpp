#define _WIN32_WINNT 0x0500
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
HWND hwnd = GetConsoleWindow();
const short rx=60, py=3, ry=40;
short szybkosc;

void gotoxy(unsigned short xx, unsigned short yy)
{
    COORD c={xx,yy};
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void kolor(int x) {SetConsoleTextAttribute(hStdout,x);}


class paletka {short y, r, up, down;
 public: short x, wynik;
    paletka(short X, short UP, short DOWN) : x(X), y(py+(ry-6-py)/2), r(6), up(UP), down(DOWN), wynik(0) {
        for(int i=0; i<r; i++) {gotoxy(x,y+i); cout<<(char)179;} // "|"
    };
    bool odbicie(short pilka) {if(pilka>=y && pilka<=y+r) return true; return false;}
    void ruch(int klaw) {
        if(klaw==up && y>py) {gotoxy(x,y+r); cout<<' '; y--; gotoxy(x,y); cout<<(char)179;} // "|"
        else if(klaw==down && y+r<ry) {gotoxy(x,y); cout<<' '; y++; gotoxy(x,y+r); cout<<(char)179;} // "|"
    }
};

class pilka {short x, y, vx, vy;
 public:
    pilka() : x(rx/2), y(py-2+rand()%5+(ry-py)/2), vx(1-(rand()%2)*2), vy(1-(rand()%2)*2) {gotoxy(x,y); cout<<'O';}; // (char)254
    ~pilka() {gotoxy(x,y); cout<<' ';}
    short ruch(paletka &p1, paletka &p2) {
        gotoxy(x,y); cout<<' ';
        if(x==0) {if(p1.odbicie(y)) {cout<<(char)8<<(char)179; vx*=-1; if(szybkosc>30) szybkosc-=5;} else return -1;} // "|"
        if(x==rx) {if(p2.odbicie(y)) {cout<<(char)8<<(char)179; vx*=-1; if(szybkosc>30) szybkosc-=5;} else return 1;} // "|"
        if(y==py || y==ry) vy*=-1;
        x+=vx, y+=vy; gotoxy(x,y); cout<<'O'; // (char)254
        return 0;
    }
};


int main()
{
    RECT r; GetWindowRect(hwnd, &r);
    MoveWindow(hwnd, r.left, r.top, 540, 400, TRUE);
    system("Color F0");
    srand(time(NULL));

    short klaw=1, koniec=0;
    kolor(241); cout<<endl<<"Gracz 1: 0";
    kolor(244); cout<<setw(rx-10)<<"Gracz 2: 0"<<endl;
    kolor(240); for(int i=0; i<=rx; i++) cout<<(char)205; // "="
    gotoxy(0,ry+1); for(int i=0; i<=rx; i++) cout<<(char)205; // "="
    paletka paletka1(0,119,115), paletka2(rx,72,80);

    gotoxy(rx/2-7,1); cout<<"GOTOWY DO GRY?";
    if(getch()==27) klaw=0; else klaw=1;
    gotoxy(rx/2-7,1); cout<<"              ";

while (klaw!=0) {
    pilka P; szybkosc=200;
    while (klaw!=27)
    {
        klaw=1;
        while(kbhit()) {
            klaw=getch();
            if(klaw==224) klaw=getch();
            paletka1.ruch(klaw); paletka2.ruch(klaw);
            paletka1.ruch(klaw); paletka2.ruch(klaw);
        }
        koniec=P.ruch(paletka1,paletka2);
        if(koniec!=0) {
            if(koniec==-1) {paletka2.wynik++; gotoxy(rx-1,1); cout<<paletka2.wynik;}
            else {paletka1.wynik++; gotoxy(9,1); cout<<paletka1.wynik;} klaw=27;
        }
        if(szybkosc>100) szybkosc-=20;
        Sleep(szybkosc);
    }
    gotoxy(rx/2-6,1); cout<<"KONTYNUOWAC?";
    Sleep(1000);
    if(getch()==27) klaw=0; else klaw=1;
    gotoxy(rx/2-6,1); cout<<"            ";
}
    if(paletka1.wynik==paletka2.wynik) {gotoxy(rx/2-4,1); kolor(242); cout<<"REMIS!!!";}
    else if(paletka1.wynik>paletka2.wynik) {gotoxy(rx/2-7,1); kolor(249); cout<<"WYGRAL GRACZ 1!";}
    else {gotoxy(rx/2-7,1); kolor(252); cout<<"WYGRAL GRACZ 2!";}
    gotoxy(0,ry);
    system("PAUSE");
    system("cls"); system("Color 08"); MoveWindow(hwnd, r.left, r.top, r.right, r.bottom, TRUE);
    return 0;
}
