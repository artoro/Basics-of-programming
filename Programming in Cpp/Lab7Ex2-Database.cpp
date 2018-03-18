//Artur Szydlowski_E04_cw6_3

#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
using namespace std;

int main ()
{
    ifstream dane("imiona.txt");
    if(!dane.good()) return 1;

    string imie; map <string,int> imiona;
    while(!dane.eof()) {
        string imie;
        dane >> imie;
        if(imiona.count(imie)) imiona[imie]+=1; else imiona[imie]=1;
    }

    map <string,int>::iterator i=imiona.begin();
    cout << "   | Imie" << setw(15) << "Ilosc\n";
    for(int j=0;j<25;j++) (j==3)? cout<<'+' : cout<<'-'; cout << endl;
    for (int j=1; i!=imiona.end(); j++,i++) cout << setw(2) << j << ".| " << i->first << setw(16 - i->first.length()) << i->second << endl;
    dane.close();
    imiona.clear();
    return 0;
}
