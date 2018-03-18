#include "ASZgraph.h"

void gotoxy(short xx, short yy)
{
  COORD c={xx,yy};
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void piksel::kolorlit() {SetConsoleTextAttribute(hOut, (int)k);}
void kolor(unsigned char kolor) {SetConsoleTextAttribute(GetStdHandle( STD_OUTPUT_HANDLE ), (int)kolor);}

void obiekt::wyswietl() //wyswietla caly obiekt
{
    gotoxy(0,0);
    for(int i=0; i<sy; i++) {
        for(int j=0; j<sx; j++) {if(px[j][i].k!=px[j][i].kol) {px[j][i].kolorlit(); px[j][i].kol=px[j][i].k;} cout << px[j][i].z;}
        cout << endl;
    }
}
void obiekt::wyswietl(short xx, short yy) //wyswietla obiekt w podanym pkt.
{
    for(int i=0; i<sy; i++) {
        gotoxy(xx,yy+i);
        for(int j=0; j<sx; j++) {if(px[j][i].k!=px[j][i].kol) {px[j][i].kolorlit(); px[j][i].kol=px[j][i].k;} cout << px[j][i].z;}
        cout << endl;
    }
}
/*void obiekt::info(); //podaje informacje na temat rozmiaru obiektu
void obiekt::info(int xx, int yy); //podaje informacje na temat danego piksela
void obiekt::obroc(int kat); //zmienia tryb wyswietlania z xy na yx
*/void obiekt::wpisz(int xx, int yy, string co) //wpisuje tekst na piksele zaczynajac od pozycji (xx,yy)
{
    for(unsigned int koniec=0; koniec<co.length();) {
        if(xx>=sx) xx=0, yy++;
        if(xx>=0 && yy>=0 && yy<sy) px[xx][yy].z=co[koniec], xx++, koniec++;
        else koniec=co.length();
    }
}
void ekran::wpisz(int xx, int yy, string co, unsigned char kol) {gotoxy(xx, yy); kolor(kol); cout<<co;}
/*unsigned char obiekt::kolor(); //koduje wartosc koloru tla i liter
void obiekt::kolortla(unsigned char k); //zmienia kolor tla konsoli
void obiekt::kolorlit(unsigned char k); //zmienia kolor liter konsoli
*/void obiekt::kolorlit(unsigned char k, int xx, int yy, int dlugosc) //zmienia kolor liter na dlugosci n znakow
{
    k=k%16;
    while(dlugosc>0){
        if(xx>=sx) xx=0, yy++;
        if(xx>=0 && yy>=0 && yy<sy) px[xx][yy].k=(px[xx][yy].k/16)*16+k, xx++, dlugosc--;
        else dlugosc=0;
    }
}
void obiekt::kolorlit(unsigned char k, int x1, int y1, int x2, int y2) //zmienia kolor liter wewnatrz prostokata
{
    k=k%16;
    if(x1<0) x1=0; if(y1<0) y1=0; if(x2>=sx) x2=sx-1; if(y2>=sy) y2=sy-1;
    for(;y1<=y2;y1++) for(int kursor=x1; kursor<=x2; kursor++) px[kursor][y1].k=(px[kursor][y1].k/16)*16+k;
}
void obiekt::kolorbox(unsigned char k, bool typ, int x1, int y1, int x2, int y2) //maluje w tle(0) lub na warstwie(1) prostokat
{
    if(x1<0) x1=0; if(y1<0) y1=0; if(x2>=sx) x2=sx-1; if(y2>=sy) y2=sy-1;
    for(; y1<=y2; y1++) for(int kursor=x1; kursor<=x2; kursor++){
        if(typ) px[kursor][y1].k=(px[kursor][y1].k/16)*16+k%16, px[kursor][y1].z=219;
        else px[kursor][y1].k=(px[kursor][y1].k%16)+k*16;
    }
}
void ekran::kolorbox(unsigned char k, bool typ, int x1, int y1, int x2, int y2)
{
    tymczasowy=new obiekt(abs(x2-x1)+1,abs(y2-y1)+1); tymczasowy->kolorbox(k,typ,0,0,abs(x2-x1)+1,abs(y2-y1)+1); tymczasowy->wyswietl(x1,y1);
    delete tymczasowy;
}
void obiekt::rysujlinie(unsigned char k, unsigned char znak, int x1, int y1, int x2, int y2) //rysuje linie miedzy P(x1,y1) a P(x2,y2)
{
    if(znak==0) znak=219; k=k%16; x1=x1%sx, y1=y1%sy;
    float a=x2-x1, b=y2-y1; int j;
    if(b==0 && a==0) {px[x1][y1].k=(px[x1][y1].k/16)*16+k, px[x1][y1].z=znak; return;}
    if(b/a>=1 || b/a<=-1) {
        (b>0)? j=1 : j=-1;
        a=a/b, b=float(x1*y2-x2*y1)/b;
        for(;y1!=y2 && y1<sy && y1>=0;y1=y1+j) x1=int(a*y1+b+0.5)%sx, px[x1][y1].k=(px[x1][y1].k/16)*16+k, px[x1][y1].z=znak;
        x1=int(a*y1+b+0.49)%sx, px[x1][y1].k=(px[x1][y1].k/16)*16+k, px[x1][y1].z=znak;
        return;
    }
    (a>0)? j=1 : j=-1;
    a=b/a, b=(y1*x2-y2*x1)/(x2-x1);
    for(;x1!=x2 && x1<sx && x1>=0;x1=x1+j) y1=int(a*x1+b+0.5)%sy, px[x1][y1].k=(px[x1][y1].k/16)*16+k, px[x1][y1].z=znak;
    y1=int(a*x1+b+0.49)%sy, px[x1][y1].k=(px[x1][y1].k/16)*16+k, px[x1][y1].z=znak;
    return;
}
void ekran::rysujlinie(unsigned char k, unsigned char znak, int x1, int y1, int x2, int y2)
{
    if(znak==0) znak=219; k=k%16;
    float a=x2-x1, b=y2-y1; int j;
    kolor(k);
    if(b==0 && a==0) {gotoxy(x1,y1); cout<<znak; return;}
    if(b/a>=1 || b/a<=-1) {
        (b>0)? j=1 : j=-1;
        a=a/b, b=float(x1*y2-x2*y1)/b;
        for(;y1!=y2 && y1>=0;y1=y1+j) {x1=int(a*y1+b+0.5); gotoxy(x1,y1); cout<<znak;}
        x1=int(a*y1+b+0.5); gotoxy(x1,y1); cout<<znak;
        return;
    }
    (a>0)? j=1 : j=-1;
    a=b/a, b=(y1*x2-y2*x1)/(x2-x1);
    for(;x1!=x2 && x1>=0;x1=x1+j) {y1=int(a*x1+b+0.5); gotoxy(x1,y1); cout<<znak;}
    y1=int(a*x1+b+0.5); gotoxy(x1,y1); cout<<znak;
    return;
}
void obiekt::rysujbox(unsigned char k, int typ, int x1, int y1, int x2, int y2) //rysuje ramke
{
    unsigned char bok[8]; switch(typ) {
        case 1: bok[1]=bok[5]=196, bok[3]=bok[7]=179, bok[0]=218, bok[2]=191, bok[4]=217, bok[6]=192; break;
        case 2: bok[1]=bok[5]=205, bok[3]=bok[7]=186, bok[0]=201, bok[2]=187, bok[4]=188, bok[6]=200; break;
        case 12: bok[1]=bok[5]=196, bok[3]=bok[7]=186, bok[0]=bok[2]=bok[4]=bok[6]=254; break;
        case 21: bok[1]=bok[5]=205, bok[3]=bok[7]=179, bok[0]=bok[2]=bok[4]=bok[6]=254; break;
        default: for(int i=0;i<8;i++) bok[i]=219;
    }
    if(x2-x1>1) {rysujlinie(k,bok[1],x1+1,y1,x2-1,y1);  //boki
                rysujlinie(k,bok[5],x1+1,y2,x2-1,y2);}
    if(y2-y1>1) {rysujlinie(k,bok[3],x2,y1+1,x2,y2-1);
                rysujlinie(k,bok[7],x1,y1+1,x1,y2-1);}

    rysujlinie(k,bok[4],x2,y2,x2,y2); //narozniki
    rysujlinie(k,bok[6],x1,y2,x1,y2);
    rysujlinie(k,bok[0],x1,y1,x1,y1);
    rysujlinie(k,bok[2],x2,y1,x2,y1);

}
void obiekt::rysujkolo(unsigned char k, char znak, int x1, int y1, int R) //rysuje okrag
{
    if(znak==0) znak=219;
    for(int i=x1-R;i<=x1+R;i++) {
            int RR=R*R-(i-x1)*(i-x1)+1;
            for(int j=y1-R;j<=y1+R;j++) if((j-y1)*(j-y1)<=RR)
                if(i>=0 && i<sx && j>=0 && j<sy) px[i][j].z=znak, px[i][j].k=(px[i][j].k/16)*16+k;
    }
}
void obiekt::rysujokrag(unsigned char k, char znak, int x1, int y1, int R) //rysuje kolo
{
    int j;
    for(int i=x1-R;i<=x1+R;i++) if(i>=0 && i<sx) {
        j=round(sqrt(R*R-(i-x1)*(i-x1)));
        if(y1-j>=0 && y1-j<sy) px[i][y1-j].k=(px[i][y1-j].k/16)*16+k, px[i][y1-j].z=znak;
        if(y1+j>=0 && y1+j<sy) px[i][y1+j].k=(px[i][y1+j].k/16)*16+k, px[i][y1+j].z=znak;
    }
    for(int i=y1-R;i<=y1+R;i++) if(i>=0 && i<sy) {
        j=round(sqrt(R*R-(i-y1)*(i-y1)));
        if(x1-j>=0 && x1-j<sx) px[x1-j][i].k=(px[x1-j][i].k/16)*16+k, px[x1-j][i].z=znak;
        if(x1+j>=0 && x1+j<sx) px[x1+j][i].k=(px[x1+j][i].k/16)*16+k, px[x1+j][i].z=znak;
    }
}
void obiekt::gradient(unsigned char k1, unsigned char k2, int typ, int x1, int y1, int x2, int y2) //tworzy prostokatny gradient kolorow w danej osi
{
    int ox=abs(x1-x2), oy=abs(y1-y2), wektor;
    obiekt obszar(ox, oy);
    switch(typ/10){
        case 2: k1=k2;
        case 1: kopiuj(obszar,x1,y1); break;
        default: obszar.kolorbox(k2,false,0,0,ox,oy);
    }
    switch(typ%10){
        //case 1: wektor=ox; if(wektor<5) wektor=5;
                //for(int i=wektor; i>=0; i-=wektor/5) obszar.; break;
        case 0: wektor=round(sqrt(ox*ox+oy*oy))/2; if(wektor<10) wektor=10;
                for(int i=wektor; i>=0; i-=wektor/10) obszar.rysujkolo(k1,gradientk(1-float(i)/wektor),ox/2,oy/2,i); break;
        default: wektor=round(sqrt(ox*ox+oy*oy)); for(int i=0;i<wektor;i++) obszar.rysujokrag(k1,gradientk(1-float(i)/wektor),ox/2,oy/2,i);
    }
    wklej(obszar,x1,y1);
}
char obiekt::gradientk(float pr) //zwraca wartosc przeslony gradientu
{
    if(pr<0.2) return 32; if(pr<0.4) return 176; if(pr<0.6) return 177; if(pr<0.8) return 178; return 219;
}
void obiekt::kopiuj(obiekt &OB, int x1, int y1) //kopiuje piksele obiektu OB do aktualnego obiektu
{
    for(int i=0; i+x1<sx && i<OB.sx; i++) for(int j=0; j+y1<sy && j<OB.sy; j++) OB.px[i][j]=px[i+x1][j+y1];
}
void obiekt::wklej(obiekt &OB, int x1, int y1) //wkleja piksele obiektu OB do aktualnego obiektu
{
    for(int i=0; i+x1<sx && i<OB.sx; i++) for(int j=0; j+y1<sy && j<OB.sy; j++) px[i+x1][j+y1]=OB.px[i][j];
}
