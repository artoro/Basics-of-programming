#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;
    int c;
    cout << "Podaj liczbe a: ";
    cin >> a;
    cout << "Wczytano? " << cin.good() << endl;
        cin.clear();
        cin.sync();

    cout << "Podaj liczbe b: ";
    cin >> b;
    cout << "Wczytano? " << cin.good() << endl;
        cin.clear();
        cin.sync();

    cout << "Podaj liczbe c: ";
    cin >> c;
    cout << "Wczytano? " << cin.good();
        cin.clear();
        cin.sync();
    return 0;
}
