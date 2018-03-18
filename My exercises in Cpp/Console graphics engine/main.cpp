#include "ASZgraph.h"
#include <conio.h>

HANDLE piksel::hOut = GetStdHandle( STD_OUTPUT_HANDLE );
HWND hwnd = GetConsoleWindow();
char piksel::kol=7;

int main()
{
    int a,b;
    cout<<"Podaj wielkosc obrazu:";
    cin>>a>>b;
    obiekt obraz(a,b), menu(100,7);

    RECT r; GetWindowRect(hwnd, &r);
    MoveWindow(hwnd, r.left, r.top, a*8+32, b*8+144, TRUE);

    obraz.gradient(14,12,0,0,0,a-1,b-1);
    obraz.kolorbox(15,0,10,10,30,40);
    obraz.kolorbox(7,1,70,20,80,30);
    obraz.rysujlinie(0,'/',0,20,50,0);
    obraz.rysujokrag(3,'*',20,20,8);
    obraz.wpisz(11,38,"HELLO WORLD!");
    obraz.kolorlit(240,11,38,22,38);
    obraz.wyswietl();

    menu.rysujbox(8,1,3,3,5,5); menu.rysujbox(7,2,1,1,3,3);
    menu.rysujkolo(1,0,2,2,0); menu.rysujkolo(2,0,4,4,0);
    for(int i=0; i<16; i++) {menu.rysujbox(7,21,8+i*3,1,11+i*3,5); menu.kolorbox(i,0,9+i*3,2,10+i*3,4);}
    menu.wpisz(60,1,"PEDZEL   LINIA   PROSTOKAT   KOLO");
    menu.kolorlit(14,60,1,6); menu.rysujbox(8,2,60,2,65,2);
    menu.wpisz(60,4,"Rozmiar: 1 [+][-]");
    menu.wyswietl(0,b+1);
    system("PAUSE");
    system("cls");
    MoveWindow(hwnd, r.left, r.top, r.right, r.bottom, TRUE);
    return 0;
}
