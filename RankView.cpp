#include "RankView.h"
#include <fstream>
#include <algorithm>


void RankView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < _rank.size(); i++)
		target.draw(_rank[i]);
}

RankView::RankView(std::string src, int screen_x, int screen_y, int x, int y, double percent_size_x, sf::Font & font, int font_size, sf::Color color, sf::RenderWindow &window)
{
	_source_file = src;
	_screen_width = screen_x;
	_screen_height = screen_y;
	_x = x;
	_y = y;
	_font_size = font_size;
	_size.x = (_screen_width * percent_size_x);
	_size.y = (_font_size * 1.5);
	_font = &font;
	_color = color;
	_window = &window;
}

RankView::~RankView()
{
}

void RankView::loadRankFromFile()
{
	int lp = 1;
	int temp_y = _y;
	//load data in format "scrore name"
	std::fstream in;
	in.open(_source_file, std::ios::in);

	if (!in.is_open())		//create file if doesn't exist
	{
		in.clear();
		in.open(_source_file, std::ios::out);
		in.close();
	}
	else
	{
		int val = 0;
		std::string get = "", name = "";
		while (std::getline(in, get))
		{
			val = atoi(get.c_str());
			name = get.substr(get.find(" ") + 1);

			RankPosition temp(lp, name, val, _size, _color, *_font, _font_size, _x, temp_y);
			
			_rank.push_back(temp);
			temp_y += _size.y + 20;
			lp++;
		}
	}
	last_y = temp_y;
	return;
}

void RankView::saveRankToFile()
{
	std::fstream out;
	out.open(_source_file, std::ios::out);
	for (int i = 0; i < _rank.size(); i++)
		out << _rank[i].getScore() << " " << _rank[i].getNick() << std::endl;
}

void RankView::addToRank(int val, std::string name)
{
	RankPosition temp(_rank.size(), name, val, _size, _color, *_font, _font_size, _x, last_y);

	_rank.push_back(temp);
	last_y += _size.y + 20;
}

void RankView::sortRank()
{
	std::sort(_rank.begin(), _rank.end(), RankPosition::compScore);

	while (_rank.size()> 50)
	{
		_rank.pop_back();
	}
	int temp_y = _y;
	for (int i = 0; i < _rank.size(); i++)
	{
		_rank[i].updateLp(i + 1);
		_rank[i].setPosY(temp_y);

		temp_y += _size.y + 20;
	}
}

void RankView::RankPosition::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(_back);
	for (int i = 0; i < 3;i++)
		target.draw(_text[i]);
}

RankView::RankPosition::RankPosition(int lp, std::string nick, int score, sf::Vector2f size, sf::Color color, sf::Font &font, int &font_size, int x , int y)
{
	_back.setFillColor(color);
	_back.setSize(size);
	_back.setPosition(x, y);

	_Lp = lp;
	_nick = nick;
	_Score = score;

	_text[0].setString(std::to_string(_Lp));
	_text[1].setString(_nick);
	_text[2].setString(std::to_string(_Score));

	for (int i = 0; i < 3;i++)
	{
		_text[i].setFont(font);
		_text[i].setCharacterSize(font_size);
		_text[i].setColor(sf::Color::Black);
		sf::FloatRect title_pos = _text[i].getLocalBounds();
		_text[i].setOrigin(title_pos.width / 2, title_pos.height / 2);

		switch (i)
		{
		case 0:
			_text[i].setPosition(x + title_pos.width + size.x*0.01, y + size.y/2);
			break;

		case 1:
			_text[i].setPosition(x + (size.x * 0.2) + (title_pos.width/2), y + (size.y / 2));
			break;

		case 2:
			_text[i].setPosition(x + size.x - (title_pos.width/2) - size.x*0.01, y + size.y / 2);
			break;
		}
	}
}

void RankView::RankPosition::updateLp(int position)
{
	_Lp = position;
	_text[0].setString(std::to_string(_Lp));
}

int RankView::RankPosition::getScore()
{
	return _Score;
}

std::string RankView::RankPosition::getNick()
{
	return _nick;
}

int RankView::RankPosition::compScore(RankPosition a, RankPosition b)
{
	return (a._Score > b._Score);
}

void RankView::RankPosition::setPosY(int y)
{
	int size_y = _back.getGlobalBounds().height;
	_back.setPosition(_back.getGlobalBounds().left, y);
	for (int i = 0; i < 3;i++)
	{
		sf::FloatRect title_pos = _text[i].getLocalBounds();
		_text[i].setOrigin(title_pos.width / 2, title_pos.height / 2);
		_text[i].setPosition(_text[i].getGlobalBounds().left, y + size_y / 2);
	}

}
