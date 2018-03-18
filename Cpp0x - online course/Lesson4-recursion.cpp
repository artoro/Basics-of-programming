#include <iostream>

using namespace std;
long long silnia(int n)
{
   if (n<1) return 1;
   else return (n * silnia(n-1));
}

int main()
{
    int x = 0;
    int a = 1;
    cout << "Podaj numer silni!" << endl;
    cin >> x;
    a = cin.good();
    cout << "Wczytano?" << endl;
    if (a=1 and x>=0) cout << "Tak" << endl << "Silnia z " << x << " = " << silnia(x) << endl;
    if (a=0 or x<0) cout << "NIE! BLEDNA LICZBA!!!" << endl;
    return 0;
}
