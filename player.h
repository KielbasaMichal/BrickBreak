#pragma once
#include "class_header.h"

class player
{
	std::string _name;
	int _life;
	int _score;
	
public:
	player(std::string name);
	~player();

	std::string getName();
	int getLife();
	int getScore();
	void setScore(int value);
};

