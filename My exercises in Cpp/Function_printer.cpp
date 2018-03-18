#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float function (float x) // fuction f(x)
{
    return 14*sin(x/3)/x*3;
}

int main()
{
    const int x=77, y=33;
    char graph[x][y];
    int fx, fy;
    for (int i=0; i<x; i++) // setup
        for (int j=0; j<y; j++)
        {
            if (i==x/2 && j==y/2) graph[x/2][y/2]='+';
            else if (j==y/2 && i==x-1) graph[x-1][y/2]='>';
            else if (j==y/2) graph[i][y/2]='-';
            else if (i==x/2 && j==0) graph[x/2][0]='^';
            else if (i==x/2) graph[x/2][j]='|';
            else graph[i][j]=' ';
        }

    for (int i=0; i<x; i++) // generates graph
    {
        fx=i-x/2, fy=y/2;
        fy=round(fy-function((float)fx));
        if (fy>=0 && fy<y)
        {
            char z;
            float m=function((float)fx-0.3), n=function((float)fx+0.3), o=function(fx);
            if (m>n) z=(char)92;
            else if (m<n) z='/';
            else if (m>o && n>o) z='V';
            else if (m<o && n<o) z='^';
            else z='-';
            graph[i][fy]=z;
        }
    }

    for (int j=0; j<y; j++) // shows graph
    {
        for (int i=0; i<x; i++) printf("%c", graph[i][j]);
        printf("\n");
    }
    return 0;
}
