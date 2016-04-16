#include "head.h"
#include <fstream>
#include <algorithm>

void loadRank(std::string src, std::vector<Rank> &vr)
{
	std::fstream in;
	in.open(src, std::ios::in);

	if (!in.is_open())		//create file if doesn't exist
	{
		in.clear();
		in.open(src, std::ios::out);
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

			Rank temp;
			temp._name = name;
			temp._val = val;
			vr.push_back(temp);

			std::cout << name << val << std::endl;

		}
	}
}

void saveRank(std::string src, std::vector<Rank> &vr)
{
	std::fstream in;
	in.open(src, std::ios::out);
	for (int i = 0;i < vr.size();i++)
	{
		Rank temp = vr.at(i);
		in << temp._val << " " << temp._name << std::endl;
	}
}

int compRank(Rank a, Rank b)
{
	return (a._val > b._val);
}

bool addRank(int val, std::string name, std::vector<Rank> &vr)
{
	if (val > vr.at(vr.size()-1)._val)
	{
		Rank temp;
		temp._name = name;
		temp._val = val;
		vr.push_back(temp);
		std::sort(vr.begin(), vr.end(), compRank);
		while(vr.size() > 10)			// zapisuje tylko 10 najlepszych zawodnikow!!!!
			vr.pop_back();
		return true;
	}
	return false;
}