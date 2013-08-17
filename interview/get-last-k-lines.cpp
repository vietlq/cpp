#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <stdlib.h>
using namespace std;

void usage(const char * pAppName)
{
	std::cerr << "Usage: " << pAppName
	<< " <K_LINES> <FILE_NAME>" << std::endl;
}

void slow_print_last_k_lines(int k, std::istream & inStr)
{
	char tempStr[2048];
	std::list<std::string> lines;
	while(inStr.good())
	{
		inStr.getline(tempStr, 2047);
		lines.push_back(tempStr);
		// Remove extra line from the front
		if(lines.size() > k)
		{
			lines.pop_front();
		}
	}
	
	while(lines.size() > 0)
	{
		std::cout << lines.front() << std::endl;
		lines.pop_front();
	}
}

int main(int argc, char* argv[])
{
	if(argc < 3)
	{
		usage(argv[0]);
		return -1;
	}
	
	int k = atoi(argv[1]);
	if(k < 1)
	{
		std::cerr << "The number of lines must be positive!" << std::endl;
		return -2;
	}
	
	const char * pFileName = argv[2];
	std::ifstream inStr;
	inStr.open(pFileName, std::ios::in | std::ios::binary);
	
	slow_print_last_k_lines(k, inStr);
	
	inStr.close();
	
	return 0;
}

