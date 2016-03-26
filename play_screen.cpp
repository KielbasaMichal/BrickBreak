#include "head.h"


vector <block*> Block;

//Dane to okna alertu
string tekst[] = { "OK", "End", "aaaaa", "bbbb" };

void ok_but(sf::RenderWindow& windows)
{
	cout << "OK Button" << endl;
	States = Start;
	windows.close();
}

void end_but(sf::RenderWindow& windows)
{
	cout << "Cancle Button" << endl;
	States = End;
	windows.close();
}
void(*func[])(sf::RenderWindow&) = { ok_but, end_but };
//Koniec danych do okna alertu

void play_screen()
{
	//Game status
	bool game_start = false;

	//Box2d create world
	b2World world(b2Vec2(0.f, 0.f));

	//Listener
	ContactListener Listener;
	world.SetContactListener(&Listener);

	float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	button back(sf::Vector2f(150, 75), sf::Vector2f(5, 5), "BACK", font, sf::Color::Yellow);
	
	//Start create game object
	block::rand_init();			//srand for using rand

	Block.clear();
	for (int i = 0; i < 7; i++)
	{
		Block.push_back(new block(50.f, sf::Vector2f(350.f + i * 100, 200.f), world));
	}

	ball ball(15, sf::Vector2f(800, 400), world);
	paddle pal(150, 50, sf::Vector2f(650, 620), world, sf::Color::Magenta);

	//board
	wall wall_1(50.f, 600.f, 200.f, 50.f, world, sf::Color::Green);
	wall wall_2(50.f, 600.f, 1100.f, 50.f, world, sf::Color::Green);
	wall wall_3(850.f, 50.f, 250.f, 50.f, world, sf::Color::Green);
	board board(850.f, 550.f, 250.f, 100.f);	
	//End create object

	//Counter
	counter Counter(sf::Vector2f(150, 75), sf::Vector2f(20, 200), font, sf::Color::Yellow);

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
					ball.getBody()->ApplyForce(b2Vec2(300.f, 300.f), ball.getBody()->GetWorldCenter(), true);
					game_start = true;
				}

			} //while

			world.Step(timeStep, velocityIterations, positionIterations);		//Box2d update
			
			ball.update_pos();

			if (game_start)
			{
				sf::Vector2f pos_mouse = (sf::Vector2f)sf::Mouse::getPosition(windows);
				if (pos_mouse.x >= 1025)
					pal.update_pos(1025.f, 620.f);
				else if (pos_mouse.x <= 325)
					pal.update_pos(325.f, 620.f);
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
					Counter.increaseValue(200);
				}
			}

			//Win
			if (Block.empty())
				alert_screen("Gratulacje wygranej!!!", 2, tekst, func);

			//Lose
			if (!board.isContain(ball.getPosition()))
				alert_screen("Niestety straciles pilke!!!", 2, tekst, func);

			timeSinceLastUpdate -= TimePerFrame;
		}
		windows.clear(sf::Color::Black);

		windows.draw(board);
		windows.draw(ball);

		for (unsigned int i = 0;i < Block.size(); i++)
			windows.draw(*Block[i]);

		windows.draw(wall_1);
		windows.draw(wall_2);
		windows.draw(wall_3);
		windows.draw(back);
		windows.draw(pal);
		windows.draw(Counter);

		windows.display();
	} //while
}