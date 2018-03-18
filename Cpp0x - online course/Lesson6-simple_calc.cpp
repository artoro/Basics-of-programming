#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

long long silnia(int n)
{
   if (n<1) return 1;
   else return (n * silnia(n-1));
}

int main()
{
    int funkcja = 10;
    float a, b, c;

    cout << "\t KALKULATOR 2.0" << "\n\n+(2) -(3) *(6) /(9) ^(8) sqrt(5) !(1) log(4) exit(0)" << endl;
    cout << "\npi(11) e(22) |a+b|(33) sin(44) cos(55) tg(66) ctg(77) mod(88)";

    cout << "\n\n\nLiczba a: ";
    cin >> a;
    while (funkcja > -1)
    {
        cout << "Liczba b: ";
        cin >> b;
        cout << "Dzialanie: ";
        cin >> funkcja;
        cout << "\n\n";

        switch(funkcja)
        {
            case 1:
                c=silnia(a);
                cout << "Silnia z " << a << " = " << c << "\n\n";
                break;
            case 2:
                c=a+b;
                cout << a << " + " << b << " = " << c << "\n\n";
                break;
            case 3:
                c=a-b;
                cout << a << " - " << b << " = " << c << "\n\n";
                break;
            case 4:
                c=log(b)/log(a);
                cout << "log(" << a << ") " << b << " = " << c << "\n\n";
                break;
            case 5:
                c=1/b;
                c=pow(a,c);
                cout << "sqrt" << b << "(" << a << ") = " << c << "\n\n";
                break;
            case 6:
                c=a*b;
                cout << a << " * " << b << " = " << c << "\n\n";
                break;
            case 8:
                c=pow(a,b);
                cout << a << "^" << b << " = " << c << "\n\n";
                break;
            case 9:
                c=a/b;
                cout << a << " / " << b << " = " << c << "\n\n";
                break;
            case 11:
                c=M_PI;
                cout << "pi = " << c << "\n\n";
                break;
            case 22:
                c=M_E;
                cout << "Stala eulera = " << c << "\n\n";
                break;
            case 33:
                c=fabs(a+b);
                cout << "|" << a << " + " << b << "| = " << c << "\n\n";
                break;
            case 44:
                b=a*M_PI/180;
                c=sin(b);
                cout << "sin(" << a << ") = " << c << "\n\n";
                break;
            case 55:
                b=a*M_PI/180;
                c=cos(b);
                cout << "cos(" << a << ") = " << c << "\n\n";
                break;
            case 66:
                b=a*M_PI/180;
                c=tan(b);
                cout << "tg(" << a << ") = " << c << "\n\n";
                break;
            case 77:
                b=a*M_PI/180;
                c=atan(b);
                cout << "ctg(" << a << ") = " << c << "\n\n";
                break;
            case 88:
                c=fmod(a,b);
                cout << a << " mod " << b << " = " << c << "\n\n";
                break;
            default:
                cout << "Wylaczyc? \t 1(TAK) 0(NIE)" << endl;
                cin >> c;
                if (c==0)
                {
                    system("CLS");
                    return main();
                }
                else  return 0;
        }
        a=c;
        cout << "\nLiczba a: " << c << endl;
    }
    return 0;
}
