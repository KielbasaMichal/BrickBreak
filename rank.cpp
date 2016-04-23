#include "head.h"
#include <fstream>
#include <algorithm>
#include "Rank.h"

void Rank::loadRankFromFile()
{
	//load data in format "scrore name"
	std::fstream in;
	in.open(_src, std::ios::in);

	if (!in.is_open())		//create file if doesn't exist
	{
		in.clear();
		in.open(_src, std::ios::out);
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

			Data temp;
			temp._name = name;
			temp._val = val;
			_data.push_back(temp);
		}
	}
	return;
}

void Rank::saveRankToFile()
{
	std::fstream in;
	in.open(_src, std::ios::out);
	for (int unsigned i = 0;i < _data.size();i++)
	{
		Data temp = _data.at(i);
		in << temp._val << " " << temp._name << std::endl;
	}
	return;
}


void Rank::addToRank(int val, std::string name)
{
	if (val > _data.at(_data.size() - 1)._val)
	{
		Data temp;
		temp._name = name;
		temp._val = val;
		_data.push_back(temp);
		sortRank();
	}
	return;
}

void Rank::sortRank()
{
	std::sort(_data.begin(), _data.end(), Data::compData);

	while (_data.size() > 10)							// przechowuje tylko 10 najlepszych wyników!!!!
		_data.pop_back();
	return;
}

int Rank::getSizeRank()
{
	return _data.size();
}

std::vector<Rank::Data>& Rank::getRank()
{
	return _data;
}

Rank::Rank(std::string src) : _src(src)
{
	loadRankFromFile();
	sortRank();
}

Rank::~Rank()
{
}