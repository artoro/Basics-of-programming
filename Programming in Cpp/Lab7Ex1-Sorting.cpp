//Artur Szydlowski_E04_cw6_2

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class dane {vector <string> plik;
  public:
    dane(string nazwapliku) {
        if(nazwapliku.find(".txt")==string::npos) nazwapliku+=".txt";
        ifstream we; we.open(nazwapliku.c_str());
        if(we.good()) {
            while(!we.eof()) {string wiersz; getline(we,wiersz); plik.push_back(wiersz);}
            we.close();
        } else {cout << "\nBLAD PLIKU!\n"; plik.push_back("BLAD PLIKU!");}
    }
    ~dane() {plik.clear();}

    void wypisz() {for(int i=0; i<plik.size(); i++) cout << plik[i] << endl;}

    void sortuj() {
        string a; bool zm;
        do {zm=false; for(int i=0; i<plik.size()-1; i++)
            if(plik[i].size()>plik[i+1].size()) a=plik[i+1], plik[i+1]=plik[i], plik[i]=a, zm=true;
        } while(zm);
    }

    void najkrotszy() {
        int dlugosc=plik[0].size(), wers=0;
        for(int i=1; i<plik.size(); i++) if(dlugosc>plik[i].size()) dlugosc=plik[i].size(), wers=i;
        cout << "\nNajkrotszy jest wers " << wers+1 << " o dlugosci " << dlugosc << " znakow i tresci:\n\""
            << plik[wers] << '"' << endl;
    }
};

int main ()
{
    dane txt("WE");

    txt.wypisz();
    cout << "-----------------------------------------------------\n";
    txt.najkrotszy();
    txt.sortuj();
    cout << "\nPO SORTOWANIU WIERSZY:\n";
    txt.wypisz();
    return 0;
}
