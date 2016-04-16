#include "head.h"


sf::RenderWindow windows(sf::VideoMode(WIDTH, HEIGHT), "Brick Break", sf::Style::Titlebar);
State States = Start;
sf::Font font;

std::vector <Rank> rank;

int main()
{
	std::cout << "Hello !!!!";
	if (!font.loadFromFile("data/FunSized.ttf"))
	{
		std::cout << "Nie znaleziono czcionek!!!!";
		return -2;
	}

	loadRank("data/rank.txt");

	while (States != End)
	{
		switch (States)
		{
		case End:
			break;
		case Start:
			start_screen();
			break;
		case Play:
			play_screen();
			break;
		}

	}

}