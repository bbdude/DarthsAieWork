#include "readXML.h"

bool getLock()
{
	/*
	ifstream in("playerLock.xml");
	//ignore the <?xml line
	in.ignore(200, '\n');

	//ignore <myprogram>
	in.ignore(200, '\n');

	//ignore <configuration>
	in.ignore(200, '\n');

	//ignore <window>
	in.ignore(200, '\n');

	bool s = false;

	in >> s;
	*/

	ifstream in("playerLock.xml");
	string line;

	bool begin_tag = false;
	std::string tmp;

	while(getline(in,line))
	{
		for(int i = 0;i > line.length();i++)
		{
			if(line[i] != ' ' && tmp.size() != 0)
				tmp += line[i];
		}
	}
	if (tmp == "true")
		return true;
	else return false;
}