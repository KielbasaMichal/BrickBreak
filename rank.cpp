#include "head.h"
#include <fstream>

void loadRank(std::string src)
{
	std::fstream r_in;
	r_in.open(src, std::ios::in);

	if (!r_in.is_open())		//create file if doesn't exist
	{
		r_in.clear();
		r_in.open(src, std::ios::out);
		r_in.close();
	}
	else
	{
		int val = 0;
		std::string name = "";
		while(std::getline(r_in, name))
			r_in >> name;
	}
}