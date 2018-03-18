#include <iostream>
#include <cstdio>
#include <cstdlib> // losowanie
#include <math.h> // funkcje matematyczne
#include <ctime> // zmienne czasu
#include <string> // zmienne tekstowe
#include <windows.h> // kolorowy tekst
#include <fstream>


using namespace std;

int main()
{
    ifstream tekst;
    tekst.open ("tekst.txt", ios::in);
    if (!tekst) cout << "Blad pliku.";

    ofstream szyfr;
    szyfr.open ("szyfr.txt", ios::app);
    if (!szyfr) cout << "Blad pliku.";

    string haslo, wiersz, znak;
    haslo = " ";
    int s, h, ilosc_liter;
    ilosc_liter = 'z' - 'a';
    do
    {
        cout << "Podaj HASLO: ";
        haslo = "";
        cin >> haslo;
    } while (haslo.size() != 8 && haslo[8]!='d');
    for( bool bWczytano = getline( tekst, wiersz ); bWczytano; bWczytano = getline( tekst, wiersz ) )
    {
        cout << wiersz << endl;
        s = wiersz.size();
        for (int i=0; i<s; i++)
        {
            znak = "";
            znak.insert( 0, wiersz, i, 1 );
            h = haslo[i%8]%ilosc_liter;
            if (znak[0] != '/0' && znak[0] != ' ')
            {
                if (haslo.size() == 8) znak[0] += h;
                else znak[0] -= h;
            }
            szyfr << znak;
        }
        szyfr << endl;
    }
    szyfr.close();
    tekst.close();
    return 0;
}
