#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(short x, short y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(hStdout, c);
}
class point;

class line { string px;
public:
	void show() { cout << px; }
	bool linia() { return px.find(" ") == string::npos; }
    void setl(int szerokosc) { px=""; px+=(char)219; for(;szerokosc>0;szerokosc--) px+=" "; px+=(char)219; px+='\n'; }
	void setl() { setl(px.length()-3); }
    bool setpx(int x) { if(x>0 && x<px.length()-1) if(px[x]==' ') { px[x]=(char)219; return true; } return false; }
	bool operator[] (int x) { if (px[x] == ' ') return false; else return true;	} //sprawdza zawartosc pola
};

class window { line endline, *win; int y;
public:
    window(int szerokosc, int wysokosc) : y(wysokosc) {
        win = new line[y]; for(int i=0; i<y; i++) win[i].setl(szerokosc);
        endline.setl(szerokosc); for(int i=1; endline.setpx(i); i++);
    }
    ~window() { delete [] win; }
	void show() { gotoxy(0, 0); for (int i = y - 1; i >= 0; i--) win[i].show(); endline.show(); }
	bool kolizja(int X, int Y) { if (Y == -1) return true; else return win[Y][X]; }
	bool kolizja(const point &P);
	bool setpx(int X, int Y) { if (Y >= 0 && Y < y) return win[Y].setpx(X); return false; }
	bool linia() {
		for (int i = 0; i < y; i++)
			if (win[i].linia()) {
				for (; i < y - 1; i++) win[i] = win[i + 1];
				win[y - 1].setl();
				return true;
			}
		return false;
	}
};

class point {
public:
	int x, y; bool stan; static int szerokosc, wysokosc;
	point() : x(szerokosc / 2), y(wysokosc - 1), stan(true) {}
	point(int X, int Y) : x(X), y(Y), stan(true) {}
	bool move(window &win, char klaw = 80) {
		if (klaw == 80 && y >= 0) { if (win.kolizja(x, y - 1)) stan = false; else { y--; return true; } }
		else if (stan) {
			if (klaw == 75 && x > 1) { if (!win.kolizja(x - 1, y)) { x--; return true; } }
			else if (klaw == 77 && x < szerokosc) { if (!win.kolizja(x + 1, y)) { x++; return true; } }
		}
		return false;
	}
	void show() { gotoxy(x, wysokosc-y-1); cout << 'X'; }
	void hide() { gotoxy(x, wysokosc-y-1); cout << ' '; }
	point& operator= (const point &P) { x = P.x, y = P.y; return *this; }
};
bool window::kolizja(const point &P) { return kolizja(P.x, P.y); }

class brick { point P1, P2, P3, P4; int ksztalt;
public:
	brick(int i, point P=point()) : P1(P), ksztalt(i%15) {
		switch (ksztalt) {
		case 0: P2 = point(P1.x + 1, P1.y), P3 = point(P1.x, P1.y - 1), P4 = point(P1.x + 1, P1.y - 1); break; //kwadrat
		case 1: P2 = P1, P1 = point(P1.x, P1.y - 1), P3 = point(P1.x, P1.y - 1), P4 = point(P1.x, P1.y - 2); break; //pionowa linia
		case 2: P2 = point(P1.x - 1, P1.y), P3 = point(P1.x + 1, P1.y), P4 = point(P1.x + 2, P1.y); break; //pozioma linia
		case 3: P2 = point(P1.x - 1, P1.y - 1), P3 = point(P1.x, P1.y - 1), P4 = point(P1.x + 1, P1.y - 1); break; //piramida
		case 4: P2 = point(P1.x, P1.y - 1), P3 = point(P1.x + 1, P1.y - 1), P4 = point(P1.x, P1.y - 2); break; //piramida 2
		case 5: P2 = point(P1.x - 1, P1.y), P3 = point(P1.x + 1, P1.y), P4 = point(P1.x, P1.y - 1); break; //piramida 3
		case 6: P2 = point(P1.x, P1.y - 1), P3 = point(P1.x - 1, P1.y - 1), P4 = point(P1.x, P1.y - 2); break; //piramida 4
		case 7: P2 = point(P1.x + 1, P1.y), P3 = point(P1.x, P1.y - 1), P4 = point(P1.x - 1, P1.y - 1); break; //s
		case 8: P2 = point(P1.x, P1.y - 1), P3 = point(P1.x + 1, P1.y - 1), P4 = point(P1.x + 1, P1.y - 2); break; //s 2
		case 9: P2 = point(P1.x - 1, P1.y), P3 = point(P1.x, P1.y - 1), P4 = point(P1.x + 1, P1.y - 1); break; //z
		case 10: P2 = point(P1.x, P1.y - 1), P3 = point(P1.x - 1, P1.y - 1), P4 = point(P1.x - 1, P1.y - 2); break; //z 2
		case 11: P2 = point(P1.x, P1.y - 1), P3 = point(P1.x, P1.y - 2), P4 = point(P1.x + 1, P1.y - 2); break; //L
		case 12: P1 = point(P1.x, P1.y - 1), P2 = point(P1.x - 1, P1.y), P3 = point(P1.x + 1, P1.y), P4 = point(P1.x + 1, P1.y + 1); break; //L 2
		case 13: P2 = point(P1.x - 1, P1.y), P3 = point(P1.x, P1.y - 1), P4 = point(P1.x, P1.y - 2); break; //L 3
		case 14: P2 = point(P1.x - 1, P1.y), P3 = point(P1.x - 1, P1.y - 1), P4 = point(P1.x + 1, P1.y); break; //L 4
		}
	}
	void move(window &win, char klaw = 80) {
		if (klaw == 72) {
			const int nr[] = { 0,2,1,4,5,6,3,8,7,10,9,12,13,14,11 };
			brick kopia(nr[ksztalt], P1);
			if (!kolizja(win, kopia)) *this = kopia;
		}
		else {
			brick kopia(*this);
			if (!(P1.move(win, klaw) && P2.move(win, klaw) && P3.move(win, klaw) && P4.move(win, klaw))) *this = kopia;
		}
	}
	void show() { P1.show(); P2.show(); P3.show(); P4.show(); }
	void hide() { P1.hide(); P2.hide(); P3.hide(); P4.hide(); }
	void stan(bool b) { P1.stan = b; }
	bool stan() { return P1.stan && P2.stan && P3.stan && P4.stan; }
	bool kolizja(window &win, const brick &B) { 
		return win.kolizja(B.P1) || win.kolizja(B.P2) || win.kolizja(B.P3) || win.kolizja(B.P4);
	}
	bool setpx(window &plansza) {
		return plansza.setpx(P1.x, P1.y) && plansza.setpx(P2.x, P2.y) && plansza.setpx(P3.x, P3.y) && plansza.setpx(P4.x, P4.y);
	}
};

int point::szerokosc = 10, point::wysokosc = 20, szybkosc = 6;

int main()
{
    window plansza(point::szerokosc,point::wysokosc);
	srand(time(NULL));
	char klaw=' ';
	int i = 0, punkty=0;
	while(klaw!=27) {
		plansza.show();

		for (brick B(rand()); B.stan();) {
			B.hide();
			while (_kbhit()) {
				klaw = _getch();
				if (klaw == 27) { B.stan(false); break; }
				else if (klaw == 224) klaw = _getch();
				B.move(plansza, klaw);
			}
			if (i % 2 == 0) B.move(plansza);
			B.show();
			if (!B.stan()) if (!B.setpx(plansza)) klaw = 27;
				else while (plansza.linia()) punkty++;
			Sleep(500/szybkosc);
			i++;
		}
    }
    return punkty;
}
