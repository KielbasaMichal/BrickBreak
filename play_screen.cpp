#include "head.h"
#include "play_screen.h"

void play_screen()
{
	//Box2d
	b2World world(b2Vec2(0.f, 0.f));
		float32 timeStep = 1.0f / 60.0f;
		int32 velocityIterations = 6;
		int32 positionIterations = 2;
	//Listener
		ContactListener Listener;
		world.SetContactListener(&Listener);
	//End Box2d
		
	//SFML
		
	loadTexture(TextureSrc, 10);
	//Elementy do gry
		button back(sf::Vector2f(150, 70), sf::Vector2f(75, 35), "BACK", font, 30, sf::Color::Black, Texture.at(5));
		paddle paddle(sf::Vector2f(paddle_size_x, paddle_size_y), sf::Vector2f(WIDTH*0.625, HEIGHT*0.9 - paddle_size_y / 2), world, Texture[8]);
		wall wall_left(board_border_size, HEIGHT, WIDTH / 4 + board_border_size / 2, HEIGHT / 2, world, Texture.at(6));
		wall wall_right(board_border_size, HEIGHT, WIDTH - board_border_size / 2, HEIGHT / 2, world, Texture.at(6));
		wall wall_top(((WIDTH / 4) * 3), board_border_size, ((WIDTH / 4) * 3) - (WIDTH / 8), board_border_size / 2, world, Texture.at(6));
		board board_background(((WIDTH / 4) * 3), HEIGHT*0.9, WIDTH / 4, 0.f, Texture.at(9));
		create_block(WIDTH/4+board_border_size, board_border_size, ((WIDTH / 4) * 3) - 2*board_border_size, HEIGHT*0.5, sf::Vector2f(40, 40), world, Texture, 5);
		create_ball(15, 700, 550, world, Texture[7]);
		IntCount Counter(sf::Vector2f(200, 75), sf::Vector2f(120, 200), font, Texture.at(5), 40, sf::Color::Black);
			sf::Font sFont;
			sFont.loadFromFile("data/My_Big_Heart.ttf");
		SymbolCount SCounter(sf::Vector2f(200, 75), sf::Vector2f(120, 300), sFont, Texture.at(5), 50, sf::Color::Red, '*');
	//End SFML

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
					if (back.mouse_over_button(windows))
						States = Start;
				}
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
				{
					Ball->ApplyForce(b2Vec2(150.f, 150.f), Ball->getBody()->GetWorldCenter());
					
				}

			} //while

			world.Step(timeStep, velocityIterations, positionIterations);		//Box2d update world
			
			Ball->update_pos();
			paddle.update_pos_x_in_rage((sf::Vector2f)sf::Mouse::getPosition(windows), WIDTH / 4 + board_border_size, WIDTH - board_border_size);
			
			for (unsigned int i = 0; i < Block.size(); i++)				//check block flag
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
			if (!board_background.isContain(Ball->getPosition()) && SCounter.getValue())
			{
				SCounter.deleteOne();
				if (SCounter.getValue())
				{
					alert_screen("Niestety straciles pilke!!!", 2, tekst, func);
					create_ball(15, 700, 550, world, Texture.at(7));
				}
				else
				{
					alert_screen("Nie masz juz zyc : ( !!!", 2, tekst, func);
				}
			}
			timeSinceLastUpdate -= TimePerFrame;
		}
		windows.clear(sf::Color::Black);

		windows.draw(board_background);
		windows.draw(wall_left);
		windows.draw(wall_right);
		windows.draw(wall_top);

		for (unsigned int i = 0;i < Block.size(); i++)
			windows.draw(*Block[i]);

		windows.draw(*Ball);
		windows.draw(paddle);

		windows.draw(back);
		windows.draw(Counter);
		windows.draw(SCounter);

		windows.display();
	} //while
}