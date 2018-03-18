#include <iostream>
#include <cstdio>
#include <cstdlib> // zarz¹dzanie aplikacj¹
#include <ctime> // zmienne czasu

using namespace std;

int main ()
{
    srand(time(NULL));
    int tablica[10];
    int wynik[4];
    cout << "Podaj 10 liczb:";
    for (int i = 0; i<=9; i++) cin >> tablica [i];
    int i = 0;
    do
    {
        int los = rand()%10;
        for (int a = 0; a<=9; a++)
        {
            if (tablica[los]==wynik[a])
            {
                a=-1;
                los = rand()%10;
            }
        }
        wynik [i] = tablica [los];
        i++;
    }while (i<=3);
    cout << "Wylosowane liczby: ";
    for (int a = 0; a<=3; a++) cout << wynik [a] << ", ";
    return 0;
}
