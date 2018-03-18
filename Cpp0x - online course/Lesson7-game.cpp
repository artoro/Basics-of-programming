#include <iostream>
#include <cstdlib>
#include <ctime>

int wylosuj (int a, int b)
{
    return rand()%(b-a+1) + a;
}

int sprawdz (int a, int b, int k)
{
    if ( (k<a && a<b) || (b<a && a<k) )
        return 0;
    else
        return 1;
}

//... tu Twój kod

int main()
{
    srand( time( NULL ) );
    std::cout << "Podaj zakres losowanych liczb oraz liczbe losowan. [od - do - los]\n";
    int start;
    std::cin >> start;
    int stop;
    std::cin >> stop;
    int ile;
    std::cin >> ile;
    int maks = ile;
    int sukces = 0;
    std::cout << "Losowanie.\n";
    int i;
    for ( i=1 ; i<=1 ; i++ )
    {
        ile = maks;
        sukces = 0;
        do
        {
            int a = wylosuj (start, stop);
            int b = wylosuj (start, stop);
            int k = wylosuj (start, stop);
            sukces = sukces + sprawdz(a, b, k);
            ile--;
        } while( ile > 0 );
        std::cout << "Prawdopodobienstwo wynioslo: " << (100*sukces)/maks << "," << (100*sukces)%maks * 100 / maks << " % \n";
    }
    return 0;
}
