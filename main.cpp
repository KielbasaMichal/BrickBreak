#include "head.h"


sf::RenderWindow windows(sf::VideoMode(WIDTH, HEIGHT), "Brick Break", sf::Style::Titlebar);
State States = Start;
sf::Font font;
Rank rank("data/rank.txt");

int main()
{
	if (!font.loadFromFile("data/FunSized.ttf"))
	{
		std::cout << "Nie znaleziono czcionek!!!!";
		return -1;
	}

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
		case TopP:
			//TODO topp_screen();
			break;
		}

	}

	rank.saveRankToFile();
	return 0;
}