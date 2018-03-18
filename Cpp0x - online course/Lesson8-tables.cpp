#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
using namespace std;

void wylosujLiczby(int tablica[], int a, int start, int stop)
{
    srand(time(NULL));
    for (int i=0; i<=(a-1); i++) tablica[i] = rand()%(stop-start+1)+start;
}

void wypiszLiczby(int tablica[], int a)
{
    for (int i=0; i<=(a-1); i++) cout << tablica[i] << ", ";
}

int obliczSume(int tablica[], int a)
{
    int b = 0;
    for (int i=0; i<=(a-1); i++) b = b+tablica[i];
    return b;
}

int main()
{
    int tablica[ 999 ];
    wylosujLiczby( tablica, 9, 4, 10 );
    wypiszLiczby( tablica, 9 );
    int iSuma = obliczSume( tablica, 9 );
    cout << "Suma liczb wynosi: " << iSuma << endl;
    return 0;
}
