//Artur Szydlowski_E04_cw1_3

#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

using namespace std;

main()
{
    srand(time(NULL));
    int n, pam=3, wdw=5;
    bool w[5]={1,1,1,1,1}; // czy byla: samogloska, spolgoska, cyfra, znak, duza litera - 1 ozn. ze jeszcze nie
    string haslo, sa="aeiouy", sp="bcdfghjklmnpqrstwvxz", zn=".,/-_?!*%#@;&", cf="0123456789"; // 6, 20, 13

    do {
        cout << "Podaj dlugosc hasla (min 4): ";
        cin >> n;
        if (n<4) cout << "Bledna dlugosc.\n";
    } while (n<4);

    while (n>0) {
        int i;
        if (n>wdw) do i=(rand()%6)%4; while (i==pam && i<2); // losuje rodzaj znaku i sprawdza, czy nie jest to druga samogloska lub spolgloska z rzedu
        else do i=rand()%4; while (!w[i]); // zabezpiecza przed niespelnieniem wszystkich wymagan hasla
        switch (i) {
            case 0: haslo+=sa[rand()%6]; break;
            case 1: haslo+=sp[rand()%20]; break;
            case 2: haslo+=cf[rand()%10]; break;
            case 3: haslo+=zn[rand()%13]; break;
        }
        if (w[i]) w[i]=false, wdw--; // sprawdza, czy byl to pierwszy tego rodzaju wylosowany znak
        if (!w[0] && !w[1] && w[4]) {w[4]=false, wdw--; haslo[haslo.length()-1]=toupper(haslo[haslo.length()-1]);} // zabezpiecza, zeby byla conajmniej 1 duza litera
        if (i<2 && rand()%2) {if (w[4]) wdw--; w[4]=false; haslo[haslo.length()-1]=toupper(haslo[haslo.length()-1]);} // losowo powieksza litery
        pam=i, n--;
    }
    cout << "Haslo: " << haslo << endl;
    return 0;
}
