#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstdlib> // losowanie
#include <ctime> // zmienne czasu
#include <string> // zmienne tekstowe

using namespace std;

double Fibo(unsigned);
double Fibo2(unsigned);
void kostki(unsigned, unsigned []);
void sortowanie1 (int [], int);
void quicksort (int, int, int []);

int c=100;
int tab2[100];

int main()
{
    unsigned funkcja, n, tab[6]={};
    srand(time(NULL));
    cout << "Wybierz funkcje. \n1.) Ciag Fibonacciego. \n2.) Rzuty kostka. \n3.) Sortowanie." << endl;
    cin >> funkcja;
    cout << "\n";
    switch (funkcja)
    {
    case 1: cout << "n= ", cin>>n, cout << Fibo2(n); break;
    case 2:
        cout << "n= ", cin>>n, kostki(n, tab), cout<<endl;
        for(int i=0; i<6; i++) cout<<i+1<<": "<<tab[i]<<"    ";
        cout << "\n\n";
        for(int i=0; i<6; i++) cout<<i+1<<": "<<round((float)tab[i]*10000/n)/100<<"%    ";
        break;
    case 3:
        int czas;
        for (int i=0; i<c; i++) tab2[i]=rand()%100, cout<<tab2[i]<<"  ";
        czas=time(NULL), quicksort(0, c-1, tab2), cout<<"\n\nCZAS: "<<time(NULL)-czas<<endl;
        //for (int i=0; i<c; i++) tab2[i]=rand()%100;
        //czas=time(NULL), sortowanie1(tab2, c), cout<<"\n\nCZAS: "<<time(NULL)-czas<<endl;
        for (int i=0; i<c; i++) cout<<tab2[i]<<"  ";
        break;
    default: break;
    }
    return 0;
}

double Fibo(unsigned n)
{
    if (n<2) return n;
    double a=0, b=1;
    for (unsigned i=2; i<=n; i++) b=a+b, a=b-a;
    return b;
}

double Fibo2(unsigned n)
{
    return (pow((1+sqrt(5))/2, n)-pow((1-sqrt(5))/2, n))/sqrt(5);
}

void kostki(unsigned n, unsigned tab[])
{
    int a;
    for (unsigned i=0; i<n; i++) a=rand()%6, tab[a]++;
    return;
}

void sortowanie1 (int tab2[], int c)
{
    bool sw;
    for (int j=0; j<c; j++)
    {
        sw = true;
        for(int i=0; i<c-j; i++)
        {
            if(i+1<c && tab2[i]>tab2[i+1]) swap(tab2[i], tab2[i+1]), sw=false;
            else if(i==c-j-1 && sw) j=c;
        }
    }
}

void quicksort (int l, int r, int tab[])
{
    int i=l, j=r;
    int temp, x=tab[(l+r)>>1];
    do
    {
        while(tab[i]<x)++i;
        while(tab[j]>x)--j;
        if(i<=j) swap(tab[i],tab[j]), ++i, --j;
    }while (i<j);
    if(l<j) quicksort(l,j, tab2);
    if(i<r) quicksort(i,r, tab2);
}
