//Artur Szydlowski_E04_cw2_2

#include <iostream>
#include <fstream>
using namespace std;

main ()
{
    ifstream we("tekst.txt");
    ofstream wy("tekst-D.txt");
    string wyraz;
    if (we.good()) {
        while (!we.eof()) {
            wyraz="";
            we >> wyraz;
            wyraz[0]=toupper(wyraz[0]);
            wy << wyraz << " ";
        }
        cout << "GOTOWE!";
    } else cout << "Blad wczytywania pliku.";
    we.close(); wy.close();
    return 0;
}
