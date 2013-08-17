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

void print_last_k_lines(int k, std::istream & inStr, const size_t MAX_LINE_LEN = 2048)
{
	char lines[k][MAX_LINE_LEN];
	int idx = 0;
	int count = 0;
	
	while(inStr.good())
	{
		inStr.getline(lines[idx], MAX_LINE_LEN - 1);
		//printf("lines[%d] = %s\n", idx, lines[idx]);
		idx = (idx + 1) % k;
		++count;
	}
	
	count = (count > k) ? k : count;
	
	for(int temp = 0; temp < count; ++temp)
	{
		std::cout << lines[(idx + temp) % k] << std::endl;
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
	
	print_last_k_lines(k, inStr);
	
	inStr.close();
	
	return 0;
}

