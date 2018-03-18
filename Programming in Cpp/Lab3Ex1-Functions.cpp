//Artur Szydlowski_E04_cw3_1

#include <iostream>
#include <cmath>
using namespace std;

float pierw (float x) {
    return sqrt(x);
}

float pierw (float x, float n) {
    return pow(x,1.0/n);
}

int main () {
    cout << "Pierwiastki 2 stopnia liczb od 1 do 5:\n";
    for (int i=1; i<6; i++) cout << pierw(i) << " ; ";
    cout << "\n\nPierwiastki 3 stopnia liczb od 1 do 5:\n";
    for (int i=1; i<6; i++) cout << pierw(i, 3) << " ; ";
    return 0;
}
