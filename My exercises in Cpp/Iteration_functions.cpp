#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstdlib> // losowanie
#include <ctime> // zmienne czasu
#include <string> // zmienne tekstowe

using namespace std;

int LiczbyArmstronga ()
{
    int OD, DO, n;
    cout << "Przedzial \nod=", cin>>OD, cout << "do=", cin>>DO, cout << "Potega: ", cin>>n;
    cout << "\n\nLiczby Armstronga z przedzialu od " << OD << " do " << DO << " to: \n";
    for (int i=OD; i<=DO && i<100000; i++)
    {
        int a=i, b=0, tab[5];
        for (int j=0; j<5; tab[j]=0, j++);
        while (a>0 && b<5) tab[b]=a%10, a/=10, b++;
        while (b>=0) a+=pow(tab[b], n), b--;
        if (a==i) cout << i << endl;
    }
    return 0;
}

int TrojkiPitagorejskie ()
{
    int a, b, c, m=0;
    cout << "m=", cin>>m;
    for (m; m>0; m--)
    {
        for (int n=0; n<m; n++)
    {
        a=m*m-n*n;
        if (a>0 && 2*m*n) cout << a << " " << 2*m*n << " " << m*m+n*n << endl;
    }
    }
    return 0;
}

int Prostokat ()
{
    int x, y;
    cout << "x: ", cin>>x, cout << "y: ", cin>>y;
    cout << endl;
    for (int i=y; i>0; i--)
    {
        if (i==1 || i==y) {for (int j=x; j>0; cout<<"X", j--); cout<<endl; }
        else {cout<<"X"; for (int j=x-2; j>0; cout<<" ", j--); cout<<"X"<<endl;}
    }
}

int main()
{
    int funkcja;
    cout << "Wybierz funkcje. \n1.) Liczby Armstronga \n2.) Trojki Pitegoresjkie. \n3.) Prostokat." << endl;
    cin >> funkcja;
    cout << "\n";
    switch (funkcja)
    {
    case 1: LiczbyArmstronga (); break;
    case 2: TrojkiPitagorejskie(); break;
    case 3: Prostokat(); break;
    default: break;
    }
    return 0;
}
