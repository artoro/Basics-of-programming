#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace sf;
using namespace std;

//USTAWIENIA
const int GRACZY = 3, TICK = 60, X = 922, Y = 573, px = 8; Vector2i delta(60,68), gsize(792,440);
const int mx = gsize.x / px, my = gsize.y / px;
//const int TICK = 60, X = 1360, Y = 768; int px = 8; Vector2i delta;

class Map {
	string *map; RenderTexture win; Sprite bg, bon, layer;
public: 
	Map(const Texture &background, const Texture &bonus) {
		win.create(X, Y); win.clear(Color::Transparent); win.setSmooth(true);
		bg.setTexture(background); bon.setTexture(bonus); bon.setOrigin(13, 28); layer.setTexture(win.getTexture());
		layer.scale(1, -1); layer.setPosition(0, Y);
		map = new string[mx];
		for (int i = 0; i < mx; i++) map[i].resize(my);
		clear();
	}
	~Map() { for (int i = 0; i < mx; i++) map[i].clear(); delete[] map; }
	void clear() { for (int i = 0; i < mx; i++) for (int j = 0; j < my; j++) map[i][j] = 0; win.clear(Color::Transparent); }
	void clear(int NR) { for (int i = 0; i < mx; i++) for (int j = 0; j < my; j++) if(map[i][j] == NR) map[i][j] = 0; }
	void set(int NR, Vector2i poz) {
		poz.x = (poz.x - delta.x + 0.5) / px, poz.y = (poz.y - delta.y + 0.5) / px;
		map[poz.x][poz.y] = NR;
	}
	void newBonus() {
		for (int i = 2 + rand() % (mx - 4), j = 2 + rand() % (my - 4); true; i = 2 + rand() % (mx - 4), j = 2 + rand() % (mx - 4))
			if (map[i][j] == 0) {
				int bonus = -(1 + rand() % 2);
				map[i][j] = bonus;
				CircleShape C(4); C.setPosition(delta.x + i*px, delta.y + j*px);
				if (bonus == -1) C.setFillColor(Color(53,144,204));
				else C.setFillColor(Color(255, 64, 96));
				win.draw(C);
				C.setRadius(3); C.setFillColor(Color(32, 19, 39, 200)); win.draw(C);
				return;
			}
	}
	bool empty(Vector2i &poz, int nr, int &bonus) {
		Vector2i pozPX; pozPX.x = (poz.x - delta.x + 0.5) / px, pozPX.y = (poz.y - delta.y + 0.5) / px;
		if (pozPX.x <= 0 || pozPX.x >= mx || pozPX.y <= 0 || pozPX.y >= my) { 
			if (bonus == 1) {
				if (pozPX.x <= 0) {
					bon.setRotation(-90); bon.setPosition(poz.x, poz.y); win.draw(bon);
					poz.x = (mx - 1) * px + delta.x;
					bon.setRotation(90); bon.setPosition(mx * px + delta.x, poz.y); win.draw(bon);
				}
				else if (pozPX.x >= mx) {
					bon.setRotation(90); bon.setPosition(poz.x, poz.y); win.draw(bon);
					poz.x = delta.x + px;
					bon.setRotation(-90); bon.setPosition(delta.x, poz.y); win.draw(bon);
				}
				else if (pozPX.y <= 0) {
					bon.setRotation(0); bon.setPosition(poz.x, poz.y); win.draw(bon);
					poz.y = (my - 1) * px + delta.y;
					bon.setRotation(180); bon.setPosition(poz.x, my * px + delta.y); win.draw(bon);
				}
				else {
					bon.setRotation(180); bon.setPosition(poz.x, poz.y); win.draw(bon);
					poz.y = delta.y + px;
					bon.setRotation(0); bon.setPosition(poz.x, delta.y); win.draw(bon);
				}
				bonus = 0;
				return true;
			}
			else return false;
		}
		else if (map[pozPX.x][pozPX.y] > 0) {
			if (bonus == 2) { map[pozPX.x][pozPX.y] = nr, bonus = 0; return true; }
			else return false;
		}
		else if (map[pozPX.x][pozPX.y] < 0) { bonus = -map[pozPX.x][pozPX.y], map[pozPX.x][pozPX.y] = nr; newBonus(); return true; }
		else map[pozPX.x][pozPX.y] = nr;
		return true;
	}
	void bounds() {
		int bonus = 0;
		RectangleShape piksel; piksel.setFillColor(Color::Magenta); piksel.setSize(Vector2f(1, 1));
		for (int i = 0; i < X; i++) for (int j = 0; j < Y; j++) {
			if (!empty(Vector2i(i, j), 0, bonus)) { piksel.setPosition(i, j); win.draw(piksel); }
		}
	}
	void display(RenderWindow &win) {
		win.draw(bg);
		win.draw(layer);
	}
};

class vectorP;
class Player {
	friend class vectorP;
	RenderTexture layer; Sprite punkt, win; Vector2i poz, kier; bool klik;
public: int nr, bonus;
	Player() {}
	Player(const Texture &tx, Color C, int NR) : punkt(tx), nr(NR), bonus(0), klik(false) {
		layer.create(X, Y); layer.setSmooth(true); layer.clear(Color::Transparent);
		win.setTexture(layer.getTexture());
		punkt.setColor(C);
		punkt.setOrigin(13, 13);
		punkt.setScale(px * 1.0 / 8, px * 1.0 / 8);
	}
	Player(Player &P) : punkt(P.punkt), nr(P.nr), poz(P.poz), kier(P.kier), bonus(P.bonus) {
		layer.create(X, Y); layer.setSmooth(true); layer.clear(Color::Transparent);
		win.setTexture(layer.getTexture());
	}
	~Player() {}

	void newGame(int i, Map &map) {
		bonus = 0; klik = false;
		layer.clear(Color::Transparent);
		switch (i%4) {
		case 1: poz = Vector2i((7 * (X / 8))/px * px, (Y / 2) / px * px - (rand() % 3) * px), //poz = Vector2i(delta.x + px * 7 * mx / 8, delta.y + px * mx / 2 - (rand() % 3) * px),
				kier = Vector2i(-px/2, 0); break;
		case 0: poz = Vector2i((X / 8) / px * px, (Y / 2) / px * px + (rand() % 3) * px),
				kier = Vector2i(px/2, 0); break;
		case 2: poz = Vector2i((X / 2) / px * px + (1 - 2*(rand() % 2)) * (18 + rand() % 5) * px, (Y / 5) / px * px),
				kier = Vector2i(0, px/2); break;
		case 3: poz = Vector2i((X / 2) / px * px + (1 - 2*(rand() % 2)) * (18 + rand() % 5) * px, 4 * (Y / 5) / px * px),
				kier = Vector2i(0, -px/2); break;
		}
		map.set(nr, poz);
	}
	void setKier(int i) {
		if (!klik) switch (i % 4) {
		case 0: if (kier.x != 0) kier = Vector2i(0, -px/2); break;
		case 1: if (kier.y != 0) kier = Vector2i(px/2, 0); break;
		case 2: if (kier.x != 0) kier = Vector2i(0, px/2); break;
		case 3: if (kier.y != 0) kier = Vector2i(-px/2, 0); break;
		}
		klik = true;
	}
	bool move(Map &map) {
		if (punkt.getColor().a == 0) { Color C = win.getColor(); C.a = C.a / 2; win.setColor(C); return false; }
		poz += kier;
		punkt.setPosition(poz.x, poz.y);
		layer.draw(punkt);
		poz += kier;
		if (map.empty(poz, nr, bonus)) {
			punkt.setPosition(poz.x, poz.y);
			layer.draw(punkt);
			if (bonus > 0) {
				CircleShape C(2); C.setOrigin(2, 2); C.setPosition(poz.x, poz.y);
				if (bonus == 1) C.setFillColor(Color(50, 130, 244));
				else C.setFillColor(Color(255, 64, 96));
				layer.draw(C);
			}
			return true;
		}
		else return false;
	}
	Sprite& display() {
		layer.display();
		return win;
	}
};

class vectorP { vector<Player> P;
public:
	vectorP() : P() { P.clear(); }
	~vectorP() { P.clear(); }

	void setKier(int NR, int Kier) {
		for (vector<Player>::iterator i = P.begin(); i != P.end(); i++) if (i->nr == NR) { i->setKier(Kier); return; }
	}
	void newGame(int ilosc, Texture &tx, Map &map) {
		P.clear(); switch (ilosc) {
		case 4: P.push_back(Player(tx, Color(0, 255, 255), 4));
		case 3: P.push_back(Player(tx, Color(255, 255, 0), 3));
		case 2: P.push_back(Player(tx, Color(0, 255, 0), 2));
		case 1: P.push_back(Player(tx, Color(255, 0, 0), 1));
		}
		int pozycja;
		if (ilosc == 2) pozycja = 2 * (rand() % 3); else pozycja = rand();
		for (vector<Player>::iterator i = P.begin(); i != P.end(); i++, pozycja++) i->newGame(pozycja, map);
	}
	int move(Map &map, int &game) {
		game = 0;
		for (vector<Player>::iterator i = P.begin(); i != P.end(); i++) {
			if (i->win.getColor().a > 2) {
				if (i->move(map)) game = game * 10 + i->nr, i->klik = false;
				else { i->kier = Vector2i(0, 0); i->punkt.setColor(Color::Transparent); map.clear(i->nr); }
			}
		}
		return game;
	}
	RenderTexture& draw() {
		for (vector<Player>::iterator i = P.begin(); i != P.end(); i++)
			if (i->win.getColor().a>200) return i->layer;
	}
	void display(RenderWindow &win) {
		for (vector<Player>::iterator i = P.begin(); i != P.end(); i++) win.draw(i->display());
	}
};

int main()
{
	RenderWindow window(VideoMode(X, Y), "The TRON!");// , Style::Fullscreen);
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(60);
	Clock clock;
	srand(time(NULL));

	Texture background, point, bonus;
	if (!background.loadFromFile("images/background3.png")) return 1;
	if (!point.loadFromFile("images/point.png")) return 2;
	if (!bonus.loadFromFile("images/bonus.png")) return 3;
	Font arial;
	if (!arial.loadFromFile("images/arial.ttf")) return 3;

	vectorP P;
	Map map(background, bonus);
	int game = -1, iloscGr = GRACZY;

	while (window.isOpen())
	{
		if (game == -1) {
			P.newGame(iloscGr, point, map);
			map.clear();
			map.newBonus();
			game = 12;
		}
		clock.restart();
		int time = clock.getElapsedTime().asMilliseconds();

		Event e;
		while (window.pollEvent(e))
		{
			if (rand() % 100 == 1) map.newBonus();
			if (e.type == Event::KeyPressed) {
				if (iloscGr > 2) {
					if (e.key.code == Keyboard::Y) P.setKier(3, 0);
					else if (e.key.code == Keyboard::J) P.setKier(3, 1);
					else if (e.key.code == Keyboard::H) P.setKier(3, 2);
					else if (e.key.code == Keyboard::G) P.setKier(3, 3);

					if (iloscGr > 3) {
						if (e.key.code == Keyboard::Num8) P.setKier(3, 0);
						else if (e.key.code == Keyboard::Num6) P.setKier(3, 1);
						else if (e.key.code == Keyboard::Num5) P.setKier(3, 2);
						else if (e.key.code == Keyboard::Num4) P.setKier(3, 3);
					}
				}
				if (e.key.code == Keyboard::Up) P.setKier(1,0);
				else if (e.key.code == Keyboard::Right) P.setKier(1,1);
				else if (e.key.code == Keyboard::Down) P.setKier(1,2);
				else if (e.key.code == Keyboard::Left) P.setKier(1,3);

				else if (e.key.code == Keyboard::W) P.setKier(2,0);
				else if (e.key.code == Keyboard::D) P.setKier(2,1);
				else if (e.key.code == Keyboard::S) P.setKier(2,2);
				else if (e.key.code == Keyboard::A) P.setKier(2,3);

				else if (e.key.code == Keyboard::Escape) window.close();
				else if (game < 10 && e.key.code == Keyboard::Return) game = -1;
			}

			else if (e.type == Event::Closed) window.close();
		}
		
		if (game > 10) {
			if (P.move(map, game) < 10) {
				//map.bounds();
				Text txt; string s;
				if (game == 0) s = "Remis...";
				else s = "Wygral gracz ", s += char(48 + game), s += "!";
				txt.setFont(arial); txt.setCharacterSize(50); txt.setColor(Color::White); txt.setString(s);
				txt.setPosition(Vector2f(X / 2 - 174, Y / 4)); (P.draw()).draw(txt);
			}
		}
		else Sleep(300);

		window.clear();
		map.display(window);
		P.display(window);
		window.display();
		int timer = TICK - clock.getElapsedTime().asMilliseconds();
		if (timer > 0) Sleep(timer);
	}

	return 0;
}