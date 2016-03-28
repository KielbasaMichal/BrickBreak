#include "player.h"

player::player(std::string name)
{
	_life = 3;
	_score = 0;
	player::_name = name;
}

player::~player()
{
}

std::string player::getName()
{
	return _name;
}

int player::getLife()
{
	return _life;
}

int player::getScore()
{
	return _score;
}

void player::setScore(int value)
{
	_score = value;
}
