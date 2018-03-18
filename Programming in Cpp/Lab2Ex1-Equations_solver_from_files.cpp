//Artur Szydlowski_E04_cw2_1

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

string oblicz(float a, float b, float c) { // liczy rownanie i zwraca odpowiedz
    stringstream odps;
    string odp;

    if (a==0) {if (b!=0) odps << "Jest to rownanie liniowe o rozwiazaniu: x=" << -c/b << endl;
    else if (c==0) odps << "Jest to rownanie tozsamosciowe." << endl;
    else odps << "Rownanie jest sprzeczne - nie ma rozwiazania." << endl;}

    else {float delta=b*b-4*a*c;
    odps << "Delta rownania wynosi " << delta;
    if (delta>0) odps << " i ma dwa rozwiazania: x=" << (-b+sqrt(delta))*0.5/a << " lub x=" << (-b-sqrt(delta))*0.5/a << endl;
    else if (delta==0) odps << " i ma jedno rozwiazanie: x=" << -b*0.5/a << endl;
    else odps << " i nie ma rozwiazan." << endl;}

    getline(odps, odp);
    return odp;
}

float stf(string *a, float b=0) { // string to float lub float to string
    stringstream ss;
    if (*a!="0") {ss << *a; ss >> b;} else {ss << b; ss >> *a;}
    return b;
}

float sgn(bool b) { // ustawia znak na ujemny lub dodatni w zaleznosci od warunku
    return (b)? 1 : -1;
}

main()
{
    ifstream we("we.txt");
    ofstream wy("wy.txt");
    string r1, r2="0"; // bierzacy rejestr oraz rejestr pobranej wartosci liczbowej
    float a=0, b=0, c=0; // wspolczynniki rownania
    bool zn=true, m=false; // strona rownania (lewa T, prawa F) i znak minus

    if (we.good()) {
    while (!we.eof()) {
        r1="";
        we >> r1; // wczytuje dane z pliku

        if (r1=="x^2") a+=stf(&r2)*sgn(zn), r2="0"; // warunki przeksztalcajace rownanie do postaci Ax^2+Bx+C=0
        else switch (r1[0]) {
            case 'x': b+=stf(&r2)*sgn(zn), r2="0"; break;
            case '-': if (r1.size()==1) m=true; else {stf(&r2,stf(&r1)*sgn(m)); m=false; break;}
            case ';':
            case '+': c+=stf(&r2)*sgn(zn), r2="0"; break;
            case '=': c+=stf(&r2)*sgn(zn), r2="0"; zn=!zn; break;
            default: stf(&r2,stf(&r1)*sgn(m)); m=false;
        }

        if (r1!=";") {wy << r1; cout << r1;} // wypisuje rownanie
        else { // oblicza wynik rownania i wypisuje rozwiazanie
            wy << endl << oblicz(a,b,c) << endl << endl;
            cout << endl << oblicz(a,b,c) << endl << endl;
            a=0, b=0, c=0, zn=true, m=false;
        }
    }
    }
    else cout << "Blad wczytywania pliku.";
    we.close(); wy.close();
    return 0;
}
