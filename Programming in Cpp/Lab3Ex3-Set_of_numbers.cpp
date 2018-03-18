//Artur Szydlowski_E04_cw3_3

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

float suma (float *tab, int n, bool tekst=false)
{
    float s=0;
    for (int i=0; i<n; i++) s= s+tab[i];
    if (tekst) cout << "\nSuma liczb wynosi: ";
    return s;
}

float sr_arytm (float *tab, int n, bool tekst=false)
{
    if (tekst) cout << "\nSrednia arytmetyczna liczb wynosi: ";
    return suma(tab, n)/n;
}

float sr_geom (float *tab, int n, bool tekst=false)
{
    float il=1;
    if (tekst) cout << "\nSrednia geometryczna liczb wynosi: ";
    for (int i=0; i<n; i++) il=il*tab[i];
    return pow(il, 1.0/n);
}

float mediana (float *tab, int n, bool tekst=false)
{
    int zm=1;
    float a=0, *tab1 = new float [n];
    for (int i=0; i<n; i++) tab1[i]=tab[i];
    //sortowanie
    if (n>1) while (zm>0) {
        zm=0;
        for (int i=0; i<n-1; i++)
            if (tab1[i]>tab1[i+1]) a=tab1[i], tab1[i]=tab1[i+1], tab1[i+1]=a, zm++;
    }
    // liczenie mediany
    if (n%2==0) a=(tab1[(n/2)-1]+tab1[(n/2)])/2;
    else a=tab1[(n/2)];
    delete [] tab1;

    if (tekst) cout << "\nMediana wynosi: ";
    return a;
}

int main ()
{
    ifstream we("we.txt");
    if (we.good())
    {
        stringstream dane;
        float (*F)(float*, int, bool), *tab, liczba;
        int i=0;

        while (!we.eof()) {we >> liczba; dane << liczba << " "; i++;}
        tab = new float [i];
        for (int j=0; j<i; j++) dane >> tab[j];

        cout << "Dany jest zbior liczb:\n{" << tab[0];
        if(i>1) for (int j=1; j<i; j++) cout << ", " << tab[j];
        cout << "}\n";

        F=suma; cout << F(tab, i, 1);
        F=sr_arytm; cout << F(tab, i, 1);
        F=sr_geom; cout << F(tab, i, 1);
        F=mediana; cout << F(tab, i, 1);

        delete [] tab;
        we.close();
    } else cout << "Blad wczytywania pliku!";
    return 0;
}
