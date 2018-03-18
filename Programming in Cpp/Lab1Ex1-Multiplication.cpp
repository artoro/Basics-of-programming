//Artur Szydlowski_E04_cw1_1

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

main()
{
    int m, n, w;
    do {
        cout << "Podaj wielkosc tabliczki mnozenia.\nliczba wierszy = ";
        cin >> m;
        cout << "liczba kolumn = ";
        cin >> n;
        if (m<1 || n<1) cout << "Podales bledny rozmiar";
    } while(m<1 || n<1);

    string num=to_string(m*n);
    w=num.length()+1;
    for (m; m>0; m--) {
        for (int i=1; i<=n; i++) cout << setw(w) << m*i;
        cout << endl;
    }
    return 0;
}
