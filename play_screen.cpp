#include "head.h"

using namespace std;

vector <block*> Block;
ball *Ball;

//Dane to okna alertu
string tekst[] = { "OK", "End"};

void ok_but(sf::RenderWindow& windows)
{
	States = Start;
	windows.close();
}

void end_but(sf::RenderWindow& windows)
{
	States = End;
	windows.close();
}
void(*func[])(sf::RenderWindow&) = { ok_but, end_but };
//Koniec danych do okna alertu

//Funkcje do budowy ryzgrywki
void create_block(float x, float y, float width, float heigth, sf::Vector2f size, b2World &world, sf::Texture* tex, int ile_tex);
void create_ball(float r, float x, float y, b2World &world, sf::Texture &tex);

void play_screen()
{
	//Load texture
	sf::Texture button_back, block_back[5], wall_back, wall_back2, ball_back;
	button_back.loadFromFile("data/button0.png");
	for (int i = 0;i < 5;i++)
		block_back[i].loadFromFile("data/block" + to_string(i) + ".png");
	wall_back.loadFromFile("data/wall0.png");
	wall_back2.loadFromFile("data/wall0.png");
	ball_back.loadFromFile("data/ball.png");

	//Game status
	bool game_start = false;

	//Box2d create world
	b2World world(b2Vec2(0.f, 0.f));

	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	//Listener
	ContactListener Listener;
	world.SetContactListener(&Listener);

	button back(sf::Vector2f(150, 70), sf::Vector2f(75, 35), "BACK", font, 30, sf::Color::Black, button_back);
	
	//Start create game object
		const float pal_size_x = 150;
		const float pal_size_y = 50;
		paddle pal(sf::Vector2f(pal_size_x, pal_size_y), sf::Vector2f(650, HEIGHT*0.9+pal_size_x/2), world, "data/paddle0.png");
	//board
		//wymiary elementow pionowych
		const float wid_p = 50;
		const float hei_p = HEIGHT;
	
		wall wall_1(wid_p, hei_p, WIDTH / 4 + wid_p / 2, hei_p / 2, world, wall_back);
		wall wall_2(wid_p, hei_p, WIDTH - wid_p / 2, hei_p / 2, world, wall_back);
	
		//wymiary elementow horyzontalnych
		const float wid_h = ((WIDTH / 4) * 3);
		const float hei_h = 50;
	
		wall wall_3(wid_h, hei_h, wid_h - (WIDTH/8), hei_h/2, world, wall_back2);
	//Tlo planszy
		board board(wid_h, hei_p*0.9, WIDTH / 4, 0.f, "data/board.png");

	//Elementy do gry
		create_block(WIDTH/4+wid_p, hei_h, wid_h - 2*wid_p, HEIGHT*0.5, sf::Vector2f(40, 40), world, block_back, 5);
		create_ball(15, 700, 550, world, ball_back);
	//End create object

	//Counter
	counter Counter(sf::Vector2f(150, 75), sf::Vector2f(20, 200), font, button_back);

	//Static step object
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

	while (States == Play)
	{
		timeSinceLastUpdate += clock.restart();
		sf::Event event;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			while (windows.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					States = End;
				if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
				{
					if (back.check_mouse_click(windows))
						States = Start;
				}
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && !game_start)
				{
					Ball->getBody()->ApplyForce(b2Vec2(150.f, 150.f), Ball->getBody()->GetWorldCenter(), true);
					game_start = true;
				}

			} //while

			world.Step(timeStep, velocityIterations, positionIterations);		//Box2d update
			
			Ball->update_pos();

			//if (game_start)
			{
				sf::Vector2f pos_mouse = (sf::Vector2f)sf::Mouse::getPosition(windows);
				if (pos_mouse.x >= WIDTH - wid_p - pal_size_x/2)
					pal.update_pos(WIDTH - wid_p - pal_size_x/2, 620.f);
				else if (pos_mouse.x <= WIDTH / 4 + wid_p + pal_size_x/2)
					pal.update_pos(WIDTH / 4 + wid_p + pal_size_x/2, 620.f);
				else
					pal.update_pos(pos_mouse.x, 620.f);
			}
			
			for (unsigned int i = 0; i < Block.size(); i++)				//check block
			{
				if (Block.at(i)->isContact())
				{
					delete Block.at(i);
					Block.erase(Block.begin() + i);
					i--;
					Counter.increaseValue(10);
				}
			}

			//Win
			if (Block.empty())
				alert_screen("Gratulacje wygranej!!!", 2, tekst, func);

			//Lose
			if (!board.isContain(Ball->getPosition()))
				alert_screen("Niestety straciles pilke!!!", 2, tekst, func);
			
			timeSinceLastUpdate -= TimePerFrame;
		}
		windows.clear(sf::Color::Black);

		windows.draw(board);
		windows.draw(wall_1);
		windows.draw(wall_2);
		windows.draw(wall_3);

		for (unsigned int i = 0;i < Block.size(); i++)
			windows.draw(*Block[i]);

		windows.draw(*Ball);
		windows.draw(pal);

		windows.draw(back);
		windows.draw(Counter);

		windows.display();
	} //while
}


void create_block(float x, float y, float width, float heigth, sf::Vector2f size, b2World &world, sf::Texture* tex, int ile_tex)
{
	int ktora = 0, next = 0;
	bool offset = false;
	sf::Vector2f size2;
	Block.clear();
	float y2 = y + size.y / 2;
	for (; y2+size.y < y + heigth; y2 += size.y)
	{
		for (float x2 = x; x2 < x + width; x2 += size.x)
		{
			while (ktora == next)
				next = rand() % ile_tex;
			ktora = next;
			if (offset)
			{
				Block.push_back(new block(size2, sf::Vector2f(x2 + size2.x / 2, y2), world, *(tex + ktora)));
				x2 -= (size.x - size2.x);
				offset = false;
			}
			else if (x2 + size.x < x + width)
			{
				Block.push_back(new block(size, sf::Vector2f(x2 + size.x / 2, y2), world, *(tex + ktora)));
			}
			else
			{
				size2.x = (x + width) - x2;
				size2.y = size.y;
				Block.push_back(new block(size2, sf::Vector2f(x2 + size2.x / 2, y2), world, *(tex + ktora)));
				offset = true;
			}
			//cout << x2 << " ; " << x + width << endl;
		}
		cout << offset << endl;
	}
}

void create_ball(float r, float x, float y, b2World &world, sf::Texture &tex)
{
	delete Ball;
	Ball = new ball(15, sf::Vector2f(x, y), world, tex);
}