//Artur Szydlowski_E04_cw2_3

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <conio.h>
using namespace std;

void ramka (string s, int i=0) {
    if (s!="") {cout << s << endl; i=s.length();} else cout << endl;
    for (i; i>0; i--) cout << '-';
    cout << endl;
    return;
}

main ()
{
    stringstream tekst;
    string zdanie;
    int exit=0, wiersze=1, slowa=0, znakiczarne=0, spacje=0;
    bool przerwa=true;

    do {
        if (exit) (exit!=13)? tekst << endl << (char)exit : tekst << endl << endl;
        system ("cls");
        ramka("Wpisz tekst ponizej. Aby zakonczyc edycje nacisnij Enter, a pozniej Esc.");
        cout << tekst.str();
        getline(cin, zdanie);
        tekst << zdanie;
        cout << "\t\t[Jesli chcesz zakonczyc wcisnij teraz ESC]\r";
        exit=getch();
    } while (exit!=27);

    zdanie=tekst.str(), exit=zdanie.length();

    for (int i=0; i<exit; i++)
        switch (zdanie[i]) {
            case '\n': wiersze++, przerwa=true; break;
            case ' ': spacje++, przerwa=true; break;
            default: if ((int)zdanie[i]>32) {znakiczarne++; if (przerwa) slowa++, przerwa=false;} else przerwa=true;
        }

    ramka("",72);
    cout << "\nLiczba wierszy: " << wiersze
        << "\nIlosc slow: " << slowa
        << "\nZnaki czarne: " << znakiczarne
        << "\nSpacje: " << spacje << endl;
    return 0;
}
