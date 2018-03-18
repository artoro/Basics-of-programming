#include <iostream>

using namespace std;

int main()
{
    long long a;
    long long b;
    cout << "Podaj liczbe a: " << endl;
    cin >> a;
    cout << "Czy wczytano? " << cin.good() << endl << "Podaj liczbe b: ";
    cin.clear();
    cin.sync();
    cin >> b;
    cout << "Czy wczytano? " << cin.good() << endl << endl;
    cin.sync();
    cin.clear();
    cout << "a + b = " << a+b << endl << "a - b = " << a-b << endl << "a * b = " << a*b << endl << "a / b = " << a/b << endl;

    return 0;
}
