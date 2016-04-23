#pragma once
#include "class_header.h"

///Rank.h
//Klasa do przechowywania listy osób w rankingu, dane pobierane z pliku
//Struktura Data przechowuje wyniki oraz funkcjê u¿ywan¹ do sortowania

class Rank
{
public:
	struct Data
	{
		int _val;
		std::string _name;
		static int compData(Data a, Data b)
		{
			return (a._val > b._val);
		}
	};

private:
	std::vector<Data> _data;
	std::string	_src;

public:
	Rank(std::string src);
	~Rank();
	void loadRankFromFile();
	void saveRankToFile();
	void addToRank(int val, std::string name);
	void sortRank();
	int getSizeRank();
	std::vector<Data>& getRank();
};