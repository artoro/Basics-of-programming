#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib> // losowanie
#include <ctime> // zmienne czasu
#include <string> // zmienne tekstowe
#include <math.h>
#include <windows.h> // kolory

using namespace std;

int przejscie (int pozycja)
{
    int kierunek = rand()%3;
    if (pozycja%10==0) kierunek = 1+rand()%4; // nie moze byc 0
    if (pozycja%10==9) kierunek = rand()%4-3; // nie moze byc 1
    switch (kierunek)
    {
        case 0: return -1; break;
        case 1: return 1; break;
        default: return 10; break;
    }
}

int dekoder (int b)
{
    switch (b)
    {
    case 4: return -1; break;
    case 6: return 1; break;
    case 2: return -10; break;
    case 8: return 10; break;
    default: return 0; break;
    }
}

int nastepny (int b)
{
    if (b==4) return 8;
    if (b==8) return 6;
    if (b==6) return 2;
    if (b==2) return 4;
    return 4;
}

int odleglosc (int pozycja, int cel)
{
    int dane[5];
    dane[0] = pozycja%10; //x pozycji
    dane[1] = pozycja/10; // y pozycji
    dane[2] = cel%10; // x celu
    dane[3] = cel/10; // y celu
    dane[4] = pow(dane[0]-dane[2], 2) + pow(dane[1]-dane[3], 2);
    return dane[4];
}

int cstart=5, cnapoczatku=0, cszukaj=1, cnieszukaj=-10, j=200, lr;

int main()
{
    lr=100;
    ofstream dane;
    dane.open ("dane.txt", ios::app);
    if (!dane) cout << "Blad pliku.";

    HANDLE uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(clock()+time(NULL));
    int pozycja = rand()%10, a = 0;
    cout << "Aby rozpoczac wcisnij enter.";
    cin.get();
// GENEROWANIE MAPY
    int mapa[100];
    for (int i=0; i<=99; i++) mapa[i]=7;
    for (int i=10; i<=89; i++) mapa[i]=0;
    do
    {
        pozycja = pozycja+przejscie(pozycja);
        mapa [pozycja] = 7;
    }while (pozycja < 90);
    for (int i=0; i<=30; i++) mapa[rand()%80+10]=7;

// GRA
    pozycja = rand()%10;
    if (mapa[pozycja+20]==7) pozycja = rand()%10;
    mapa[pozycja]--;
    int pamiec[7], pustepola [50];
    for (int i=0; i<=49; i++) pustepola[i]=-1;
    int b = -1, c = 0, d = 1000, cel = 95;
    int czas = 0, liczbaruchow = 0;
    do
    {
// WYSWIETLANIE MAPY
        system( "cls" );
        for (int y=90; y>=0; cout << endl, y=y-10) for (int x=0; x<=9; x++)
        {
            if (mapa[y+x]==6) SetConsoleTextAttribute(uchwyt, FOREGROUND_RED | FOREGROUND_INTENSITY );
            if (mapa[y+x]==7) SetConsoleTextAttribute(uchwyt, 8);
            cout << mapa[y+x];
            SetConsoleTextAttribute(uchwyt, 7);
        }
        if (pozycja >= 90) c=10;
// SZTUCZNA INTELIGENCJA
// ROZPOZNANIE TERENU
        if (c<3) czas=cnapoczatku;
        if (c==0 && pozycja>0)
        {
            if (mapa[pozycja+10]==7 && mapa[pozycja+20]==7) a=8, c=2;
            else a=4;
        }
        if (c==0 && pozycja==0) c=1;
        if (c==1 && pozycja<=9)
        {
            if (mapa[pozycja+10]==7 && mapa[pozycja+20]==7) a=8, c=2;
            else a=6;
        }
// ROZPOCZECIE PODROZY
        if (c==3)
        {
            if (mapa[pozycja+10]==7 && b!=2 && (mapa[pozycja+20]==7 || mapa[pozycja+9]==7 || mapa[pozycja+11]==7)) a=8;
            if (a==5)
            {
                for (int i=0; i<=6; i++) pamiec[i]=5;
                if ((mapa[pozycja+9]==7) && (mapa[pozycja-1]==7) && (pozycja%10!=0)) pamiec[0]=4;
                if ((mapa[pozycja-1]==7) && ((pozycja%10)!=0)) pamiec[1]=4;
                if (mapa[pozycja+11]==7 && mapa[pozycja+1]==7 && pozycja%10!=9) pamiec[2]=6;
                if (mapa[pozycja+1]==7 && pozycja%10!=9) pamiec[3]=6;
                if (mapa[pozycja+10]==7) pamiec[4]=8;
                if (mapa[pozycja-10]==7 && pozycja/10!=0) pamiec[5]=2;
                if (mapa[pozycja+dekoder(b)]==7 && (pozycja%10)!=0 && (pozycja%10)!=9 && b!=2) pamiec[6]=b;
                if (mapa[pozycja-10]==7 && b==2) pamiec[6]=b;
                do a=pamiec[rand()%7]; while(a==5 || a==0);
                for (int i=0; i<50 || pustepola[i]==-1; i++) if (pustepola[i]==100+mapa[pozycja+dekoder(a)])
                {
                    do a=pamiec[rand()%7]; while(a==5 || a==0);
                    i=50;
                }
            }
        }
// SZUKANIE PUSTYCH POL
        for (int i = 0; i<=4; i++)
        {
            if (mapa[pozycja+dekoder(b)]==7)
            {
                if ((pozycja%10!=0 && b!=4) || (pozycja%10!=9 && b!=6) || (pozycja/10!=0 && b!=2) || (pozycja/10!=9 && b!=8))
                {
                    int e = pozycja+dekoder(b);
                    for (int i=0; e>=0 && i<=49; i++) if (pustepola[i]==e || pustepola[i]%100==e) e=-1;
                    if (e!=-1) for (int i=0; e>=0 && i<=49; i++)
                        if (pustepola[i]==-1) pustepola[i]=e, e=-1, czas--;
                }
            }
            b=nastepny(b);
        }
        czas++;
        for (int i=0; i<=49; i++)
        {
            if (pozycja==pustepola[i]) pustepola[i]=pustepola[i]+100, i=50;
            if (pustepola[i]==-1 || pustepola[i]%100==pozycja) i=50, czas=czas+2;
        }
// SZUKANIE CELU POSREDNIEGO
    for (int i=49; i>=0 && czas>=cstart; i--) if(pustepola[i]>=0 && pustepola[i]/100==0)
    {
        cel = pustepola[i];
        if (c!=5) c=5, czas = cszukaj; else c=3, czas = cnieszukaj;
    }
// JAZDA DO CELU NAJKROTSZA DROGA
        if (c==5 && pozycja!=cel)
        {
            czas--;
            for (int i = 0; i<=4; i++)
            {
                if (mapa[pozycja+dekoder(b)]==7 && odleglosc(pozycja+dekoder(b), cel) < d )
                {
                    if (!((pozycja%10==0 && b==4) || (pozycja%10==9 && b==6) || (pozycja/10==0 && b==2) || (pozycja/10==9 && b==8)))
                        d=odleglosc(pozycja+dekoder(b), cel), a=b;
                }
                b=nastepny(b);
            }
        }
        if (c==5 && pozycja == cel) c=3;
// STEROWANIE ROBOTEM
        if (a==2) czas++;
        cout << "a " << a << " b " << b << " c " << c << "   czas " << czas;
        b=a;
        d = clock()+CLOCKS_PER_SEC/5;
        while(d>clock());
        mapa[pozycja]++;
        switch (a)
        {
        case 4:
            pozycja--;
            break;
        case 6:
            pozycja++;
            break;
        case 8:
            pozycja = pozycja+10;
            break;
        case 2:
            pozycja = pozycja-10;
            break;
        default:
            break;
        }
        mapa[pozycja]--, liczbaruchow++;
        a=5;
        if (c==2) c=3;
// KONIEC PALIWA
        if (liczbaruchow>lr)
        {
            c=0;
            cout << "KONIEC PALIWA!";
            if (dane) dane << "\tXXX\tXXX" << endl;
            system("PAUSE");
            d=1;
            mapa[pozycja]++;
            pozycja = rand()%10;
            mapa[pozycja]--;
            liczbaruchow=0;
            for (int i=0; i<=49; i++) pustepola[i]=-1;
        }
    }while(c < 6);
    d=1;
    for (int i=0; i<=49 && pustepola[i]>=0; i++) if(pustepola[i]>99) d++;
    if (dane) dane << liczbaruchow << "\t" << d << endl;
    cout << "\nLiczba ruchow: " << liczbaruchow << "\t Ilosc zajetych pol: " << d << endl;
    dane.close();
    cin >> c;
    if (c==0) main();
    return 0;
}
