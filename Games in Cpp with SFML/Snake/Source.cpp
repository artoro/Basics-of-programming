#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <time.h>
using namespace sf;

class Point { public: int x, y;
	Point() : x(-2), y(-2) {}
	Point(int X, int Y) : x(X), y(Y) {}
	Point& operator+(const Point &P) { x += P.x, y += P.y; return *this; }
	bool operator==(const Point &P) { return x == P.x && y == P.y; }
	operator Vector2f const() { return Vector2f(x * 16, y * 16); }
};

// USTAWIENIA GRY
const int X = 20, Y = 20; int okno = 0, TICK = 50, szybkosc = 5; bool sciany = true;

int main()
{
	srand(time(NULL));
	RenderWindow window(VideoMode(16 * X, 16 * Y), "Snake");
	window.setFramerateLimit(60);
	Clock clock;

	// Sprite'y: s-snake, p-point, background-tlo, ...
	Texture t1, m1, num;
	if (!t1.loadFromFile("images/white.png")) return -2;
	if (!m1.loadFromFile("images/menu.png")) return -3;
	if (!num.loadFromFile("images/num.png")) return -4;
	Sprite s(t1), p(t1), background(t1), title(m1, IntRect(0, 0, 16 * X, 16 * 6)), mline(m1), number(num);
	s.setColor(Color(255, 0, 0));
	p.setColor(Color(0, 255, 0));
	RectangleShape red(Vector2f(X * 16, 32));
	red.setFillColor(Color(220, 0, 0));

	do {
		red.setPosition(Vector2f(0, 160));
		// Poczatkowe ustawienie snake'a, point'u oraz kierunku ruchu snake'a
		int slong = 4, ssize = 25;
		Point *snake = new Point[ssize], point(X / 4 + rand() % (X / 2), Y / 4 + rand() % (Y / 2)), dir(0, 0);
		for (int i = 0; i < slong; i++) snake[i].x = slong - 1 - i, snake[i].y = 0;
		p.setPosition(point);

		// PETLA GLOWNA
		while (window.isOpen())
		{
			clock.restart();
			window.clear(Color(200, 200, 200));

			// STEROWANIE
			Event e;
			while (window.pollEvent(e))
			{
				if (e.type == Event::Closed || (e.type == Event::KeyPressed && e.key.code == Keyboard::Escape)) {
					window.close(); okno = 4; continue;
				}

				if (e.type == Event::KeyPressed) {
					bool changed = false;
					if (e.key.code == Keyboard::Up && dir.y == 0) dir = Point(0, -1), changed = true;
					else if (e.key.code == Keyboard::Down && dir.y == 0) dir = Point(0, 1), changed = true;
					else if (e.key.code == Keyboard::Left && dir.x == 0) dir = Point(-1, 0), changed = true;
					else if (e.key.code == Keyboard::Right || e.key.code == Keyboard::Return && dir.x == 0)
						dir = Point(1, 0), changed = true;
					while (window.pollEvent(e) && changed);
				}
			}

			if (okno < 3) {
				window.draw(title);
				window.draw(red);
				if (dir.y == -1) { if (red.getPosition().y != 160) { red.move(Vector2f(0, -8)); TICK = 25; } else dir = Point(0, 0), TICK = 50; }
				else if (dir.y == 1) { if (red.getPosition().y != 240) { red.move(Vector2f(0, 8)); TICK = 25; } else dir = Point(0, 0), TICK = 50; }

				//STEROWANIE MENU
				if (okno == 0 && dir.x == 1) {
					if (red.getPosition().y < 216) {
						okno = 3, dir = Point(0, 1), TICK = 500 / szybkosc, red.setPosition(Vector2f(0, 144));
						continue;
					}
					else { okno = 1, dir = Point(0, 0), red.setPosition(Vector2f(0, 160)); continue; }
				}
				else if (okno == 1) {
					if (dir.x == 1) {
						if (red.getPosition().y < 216) { (szybkosc < 9) ? szybkosc++ : szybkosc = 1; dir = Point(0, 0); continue; }
						else { sciany = !sciany, dir = Point(0, 0); continue; }
					}
					else if (dir.x == -1) { okno = 0, dir = Point(0, 0), red.setPosition(Vector2f(0, 160)); continue; }
				}

				for (int j = 6; j < Y; j++) for (int i = 0; i < X; i++) { // wyswietla menu, ustawienia i game over
					background.setPosition(Vector2f(16 * i, 16 * j));
					window.draw(background);
					if (okno < 2 && (j == 10 || j == 15)) {
						mline.setTextureRect(IntRect(0, 96 + 32 * (j / 11) + 64 * okno, 320, 32));
						mline.setPosition(Vector2f(0, 16 * j));
						window.draw(mline);
						i = X, j++;
					}
					else if (okno == 2 && (j == 9 || j == 13 || j == 16)) {
						mline.setTextureRect(IntRect(0, 192 + 32 * (j / 5), 320, 32));
						mline.setPosition(Vector2f(0, 16 * j));
						window.draw(mline);
						i = X, j++;
					}
				}
				if (okno == 1) { // wyswietla wartosci w ustawieniach
					number.setTextureRect(IntRect(szybkosc * 32, 0, 32, 32));
					number.setPosition(Vector2f(272, 160));
					window.draw(number);
					int onoff; (sciany) ? onoff = 320 : onoff = 416;
					number.setTextureRect(IntRect(onoff, 0, 96, 32));
					number.setPosition(Vector2f(208, 240));
					window.draw(number);
				}
				else if (okno == 2) { // wyswietla wynik na koniec gry
					int points = slong - 4;
					if (points < 10) {
						number.setTextureRect(IntRect(points * 32, 0, 32, 32));
						number.setPosition(Vector2f(144, 256));
						window.draw(number);
					}
					else if (points < 100) {
						number.setTextureRect(IntRect((points / 10) * 32, 0, 32, 32));
						number.setPosition(Vector2f(128, 256));
						window.draw(number);
						number.setTextureRect(IntRect((points % 10) * 32, 0, 32, 32));
						number.setPosition(Vector2f(160, 256));
						window.draw(number);
					}
					else {
						number.setTextureRect(IntRect((points / 100) * 32, 0, 32, 32));
						number.setPosition(Vector2f(112, 256));
						window.draw(number);
						number.setTextureRect(IntRect((points % 100) / 10 * 32, 0, 32, 32));
						number.setPosition(Vector2f(144, 256));
						window.draw(number);
						number.setTextureRect(IntRect((points % 10) * 32, 0, 32, 32));
						number.setPosition(Vector2f(176, 256));
						window.draw(number);
					}
				}
			}

			else if (okno == 3) {
				// BACKGROUND okienka
				for (int i = 0; i < X; i++) for (int j = 0; j < Y; j++) {
					background.setPosition(Vector2f(16 * i, 16 * j));
					window.draw(background);
				}
				window.draw(p); //Point

				// ZJEDZENIE POINT'a
				if (snake[0] == point) {
					slong++;
					if (slong == ssize - 1) { // jesli braknie pamieci weza
						ssize *= 2;
						Point *K = new Point[ssize];
						for (int i = 0; i < slong; i++) K[i] = snake[i];
						delete[] snake;
						snake = K;
					}
					for (int i = 0; i < slong; i++) { // ustawia nowy point na pustym polu
						if (i == 0) point = Point(rand() % X, rand() % Y);
						if (snake[i] == point) i = -1;
					}
					p.setPosition(point);
					window.draw(p);
				}

				// RUCH SNAKE'a
				for (int i = 3; i <= slong; i++) if (snake[i] == snake[0]) { okno = 2, TICK = 50, dir = Point(0, 0); continue; } // sprawdza, czy sie nie ugryzl
				for (int i = slong; i > 0; i--) { snake[i] = snake[i - 1]; s.setPosition(snake[i]); window.draw(s); } // przesuwa ogon
				snake[0] = snake[0] + dir; // przesuwa glowe
				if (snake[0].x < 0 || snake[0].x >= X || snake[0].y < 0 || snake[0].y >= Y) { // sprawdza kolizje ze scianami
					if (sciany) { okno = 2, TICK = 50, dir = Point(0, 0); continue; }
					else if (snake[0].x < 0) snake[0] = Point(X - 1, snake[0].y);
					else if (snake[0].x >= X) snake[0] = Point(0, snake[0].y);
					else if (snake[0].y < 0) snake[0] = Point(snake[0].x, Y - 1);
					else snake[0] = Point(snake[0].x, 0);
				}
				s.setPosition(snake[0]); window.draw(s);
			}

			//OKNO GAME OVER
			if (okno == 2) {
				Sleep(100);
				if (ssize >= 25) for (dir = Point(0, 0); window.pollEvent(e); ssize=24);
				if (dir.x != 0 || dir.y != 0) { okno = 0; break; }
			}
			// ODSWIEZA I WYSWIETLA OKIENKO
			window.display();
			{
				int time = TICK - clock.getElapsedTime().asMilliseconds();
				if (time < 0) time = 0;
				Sleep(time);
			}
		}

		delete[] snake;
	} while (okno == 0);
	system("PAUSE");
	return 0; // zwraca ilosc zdobytych punktow
}