#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace sf;

const int TICK = 1000/30, GROUND = 520; const float G = 9.82, M = 120, DT = TICK * 1.0 / 1000;
class Game; class Player; class Ball;

class Object {
public:
	Sprite S, Sh; float vx, vy, mass;
	Object(const Texture &tx, const Texture &txSh) : vx(0), vy(0) {
		S.setTexture(tx); Sh.setTexture(txSh); Sh.setColor(Color(0, 0, 0, 220));
	}
	void move() {
		if (vx != 0 || vy != 0) {
			if (S.getPosition().y < GROUND)	vy = vy + DT * G;
			S.move(vx * DT * M, vy * DT * M);
			Sh.setPosition(S.getPosition().x, GROUND + S.getPosition().y/16.25);
		}
	}
	void result(Object &P) {
		float v1 = sqrtf(vx*vx + vy*vy) + 0.0000001, v2 = sqrtf(P.vx*P.vx + P.vy*P.vy) + 0.0000001,
			cosA = vx / v1, sinA = vy / v1, cosB = P.vx / v2, sinB = P.vy / v2,
			distance = (S.getPosition().x - P.S.getPosition().x) * (S.getPosition().x - P.S.getPosition().x);
		distance += (S.getPosition().y - P.S.getPosition().y) * (S.getPosition().y - P.S.getPosition().y),
			distance = sqrtf(distance);
		float cosC = (S.getPosition().x - P.S.getPosition().x) / distance,
			sinC = (S.getPosition().y - P.S.getPosition().y) / distance,
			dv = (v1*(cosA*cosC + sinA*sinC)*(mass - P.mass) + 2 * P.mass*v2*(cosB*cosC + sinB*sinC)) / (mass + P.mass);

		vx = dv*cosC - v1*(sinA*cosC - sinC*cosA)*sinC, vy = dv*sinC + v1*(sinA*cosC - sinC*cosA)*cosC;
		std::cout << "C";
		//std::cout << v1 << " " << v2 << " " << cosA << " " << sinA << std::endl;
	}
};

class Player : public Object { bool nr;
public:
	Player(bool i, const Texture &tx, const Texture &txSh) : Object(tx, txSh), nr(i) {
		mass = 50;
		S.setOrigin(37, 58);
		Sh.setOrigin(25, 22);
		if (i) {
			S.setPosition(160, 520);
			S.setColor(Color(255, 0, 0, 230));
			Sh.setPosition(160, GROUND + 32);
		}
		else {
			S.setPosition(640, 520);
			S.setColor(Color(0, 255, 0, 230));
			Sh.setPosition(650, GROUND + 32);
		}
	}
	void stay() { vx = 0; }
	void left() { vx = -2; }
	void right() { vx = 2; }
	void jump() { if (S.getPosition().y >= GROUND) vy = -6; }
	void move() {
		if (nr) { if ((S.getPosition().x <= 0 && vx < 0) || (S.getPosition().x >= 370 && vx > 0)) vx = 0; }
		else { if ((S.getPosition().x >= 800 && vx > 0) || (S.getPosition().x <= 430 && vx < 0)) vx = 0; } 
		Object::move();
		if (S.getPosition().y > GROUND) { S.setPosition(S.getPosition().x, GROUND); vy = 0; }
	}
};
class Ball : public Object { bool stay, side; int push;
public:

	Ball(bool i, const Texture &tx, const Texture &txSh) : Object(tx, txSh), stay(0), push(0), side(i) {
		mass = 1;
		S.setOrigin(32, 32);
		S.setPosition(200 + 400 * i, 300);
		Sh.setOrigin(20, 18);
		Sh.setPosition(200 + 400 * i, GROUND + S.getPosition().y / 16.25);
	}
	void move() {
		if (stay) {
			if (vx > 6) vx = (vx + 6) / 2; else if (vx < -6) vx = (vx - 6) / 2;
			if (vy < -6) vy = (vy - 6) / 2;
			Object::move();
			side = (S.getPosition().x > 400);
			if (S.getPosition().y >= GROUND) { 
				S.setPosition(S.getPosition().x, GROUND); vy = -vy * 0.5;
			}
			if (S.getPosition().x <= 0 || S.getPosition().x >= 800) {
				S.setPosition(800 * int(S.getPosition().x / 800), S.getPosition().y); vx = -vx * 0.8;
			}
			net();
			//std::cout << "(" << S.getPosition().x << "," << S.getPosition().y << ")\n";
		}
	}
	bool collision(Object &P) {
		float dx2 = S.getPosition().x - P.S.getPosition().x, dy2 = S.getPosition().y - P.S.getPosition().y + 33;
		dx2 *= dx2, dy2 *= dy2;
		if (dx2 + dy2 < 3249) { if (push == 0) { push = 12; Object Ob(*this); result(P); P.result(Ob); return true; } }
		else {
			dy2 = S.getPosition().y - P.S.getPosition().y, dy2 *= dy2;
			if (dx2 + dy2 < 4225) { if (push == 0) { push = 12; result(P); return true; } }
			else if (push != 0) push--;
		}
		return false;
	}
	void result(Object &P) {
		Object::result(P);
		if (!stay) stay = true, vy -= 4, vx += 1 - int(S.getPosition().x / 300);
		else if (P.S.getPosition().y >= GROUND) vy -= 2;
		else vy -= 1;
	}
	void net() {
		if (S.getPosition().y > 250 && S.getPosition().y < 460) {
			if ((side && S.getPosition().x < 428 && vx < 0) || (!side && S.getPosition().x > 372 && vx > 0)) vx *= -0.7;
		}
	}
};

class Game { public:
	RenderWindow *win; static Texture blobby, ball, blobbySh, ballSh; static bool restart; Clock clock; Player P1, P2; Ball B;
	
	// Konstruktor nowej gry
	Game(RenderWindow *WIN) : win(WIN), P1(0, blobby, blobbySh), P2(1, blobby, blobbySh), B(rand() % 2, ball, ballSh)
		{ clock.restart(); }

	// Obsluga okna gry
	void play() {
		int timer = clock.getElapsedTime().asMilliseconds();

		Event e;
		while (win->pollEvent(e))
		{
			if (e.type == Event::Closed) win->close();

			if (e.type == Event::KeyPressed) {
				if (e.key.code == Keyboard::Up) P1.jump();
				else if (e.key.code == Keyboard::W) P2.jump();
				else if (e.key.code == Keyboard::Escape) restart = true;
			}

			if (Keyboard::isKeyPressed(sf::Keyboard::Right)) P1.right();
			else if (Keyboard::isKeyPressed(sf::Keyboard::Left)) P1.left();
			else P1.stay();

			if (Keyboard::isKeyPressed(sf::Keyboard::D)) P2.right();
			else if (Keyboard::isKeyPressed(sf::Keyboard::A)) P2.left();
			else P2.stay();
		}
		P1.move(); P2.move(); B.move();
		B.collision(P1); B.collision(P2);
		timer = timer + TICK - clock.getElapsedTime().asMilliseconds();
		if (timer > 0) Sleep(timer);
		else while (timer < 0) {
			std::cout << '!';
			P1.move(); P2.move(); B.move();
			B.collision(P1); B.collision(P2);
			timer += TICK;
		}
	}
	void draw() {
		win->draw(P1.Sh);
		win->draw(P2.Sh);
		win->draw(B.Sh);
		win->draw(P1.S);
		win->draw(P2.S);
		win->draw(B.S);
	}
};


Texture Game::blobby, Game::ball, Game::blobbySh, Game::ballSh;
bool Game::restart = false;
int main()
{
	srand(time(0));
	RenderWindow window(VideoMode(800, 600), "Blobby Volley!");
	window.setFramerateLimit(60);
	//window.setKeyRepeatEnabled(false);
	if (!Game::blobby.loadFromFile("images/blobby.png")) return 1;
	if (!Game::ball.loadFromFile("images/ball.png")) return 1;
	if (!Game::blobbySh.loadFromFile("images/blobby_shadow.png")) return 1;
	if (!Game::ballSh.loadFromFile("images/ball_shadow.png")) return 1;
	Game *game = new Game(&window);

	Texture t1, t2;
	if (!t1.loadFromFile("images/background.png")) return 1;
	if (!t2.loadFromFile("images/net.png")) return 1;
	Sprite bg(t1), net(t2);
	net.setOrigin(7, 323); net.setPosition(400, 600);

	while (window.isOpen())
	{
		window.clear();
		window.draw(bg);
		game -> play();
		game -> draw();
		window.draw(net);
		window.display();
		if (Game::restart) { delete game; Game::restart = false, game = new Game(&window); }
	}

	delete game;
	return 0;
}