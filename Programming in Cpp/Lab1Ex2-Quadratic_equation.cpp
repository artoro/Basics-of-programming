//Artur Szydlowski_E04_cw1_2

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

main()
{
    int a, b, c, delta;
    string odp;
    do {
        cout << "Podaj wspolczynniki rownania kwadratowego. (a, b, c)\n";
        cin >> a >> b >> c;
        delta = b*b-4*a*c;
        cout << "Rownanie (" << a << ")x^2 + (" << b << ")x + (" << c << ") = 0";
        if (delta<0) cout << " nie ma pierwiastkow rzeczywistych.\n";
        else if (delta==0) cout << " ma jeden podwojny pierwiastek rowny " << -b*0.5/a << endl;
        else cout << " ma dwa pierwistki rzeczywiste x1=" << (-b-sqrt(delta))*0.5/a << " oraz x2=" << (-b+sqrt(delta))*0.5/a << endl;
        cout << "Czy chcesz obliczyc pierwiastki innego rownania?" << endl;
        cin >> odp;
        for (int i=0; i<odp.length(); i++) odp[i]=tolower(odp[i]);
    } while (odp=="tak");
    return 0;
}
