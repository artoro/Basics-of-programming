//Artur Szydlowski_E04_cw3_2

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
using namespace std;


int suma (int **tab, int n)
{
    int a=0;
    for (int i=0; i<n; i++) a+=tab[i][i];
    return a;
}

void iskalarny (int **tab, int n, int k, int r)
{
    for (int i=0; i<n; i++) {
        cout << "|";
        for (int j=0; j<n; j++) cout << setw(r+k) << tab[i][j]*k;
        cout << " |\n";
    }
}

void kwmacierzy (int **tab, int n, int r)
{
    for (int i=0; i<n; i++) {
        cout << "|";
        for (int j=0; j<n; j++) {
            int a=0;
            for (int x=0; x<n; x++) a+=tab[i][x]*tab[x][j];
            cout << setw(2*r+1) << a;
        }
        cout << " |\n";
    }
}

int main() {
    ifstream we("we.txt");
    stringstream liczby;
    string liczba;
    int n=0, r=0;

    if (we.good()) {
        while (!we.eof()) {
            we >> liczba;
            liczby << liczba << " ";
            if (liczba.length()>r) r=liczba.length();
            n++;
        }

        n=sqrt(n);
        int **tab = new int * [n];
        for (int i=0; i<n; i++) tab[i] = new int [n];

        for (int i=0; i<n; i++) {
            cout << "|";
            for (int j=0; j<n; j++) {liczby >> tab[i][j]; cout << setw(r+1) << tab[i][j];}
            cout << " |\n";
        }

        cout << "\n\nSuma elementow na diagonali wynosi: " << suma(tab,n);

        cout << "\n\nIloczyn macierzy przez liczbe skalarna 2 wynosi:\n";
        iskalarny(tab, n, 2, r);

        cout << "\n\nKwadrat macierzy wynosi:\n";
        kwmacierzy(tab, n, r);

        for (int i=0; i<n; i++) delete [] tab[i];
        delete [] tab;
    } else cout << "Blad wczytywania pliku.";
    we.close();
    return 0;
}
