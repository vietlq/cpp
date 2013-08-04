#include <iostream>
//#include <fstream>
#include <algorithm>

typedef unsigned long base_type;

base_type most_toys(std::istream & istr)
{
	//
	base_type N, toys;
	unsigned long long K, total;
	base_type * toyPrices = NULL;
    
	//
	istr >> N >> K;
    //
    toyPrices = new base_type[N];
    //
    int idx = 0;
	while(idx < N)
	{
		istr >> toyPrices[idx];
        ++idx;
	}
    
    // Sort
    std::stable_sort(toyPrices, toyPrices + N);
    
    toys = 0;
    total = 0;
    while(total + toyPrices[toys] <= K)
    {
        total += toyPrices[toys];
        ++toys;
    }
    
    // Clean up
    delete[] toyPrices;
    
    return toys;
}

int main()
{
	printf("%lu\n", most_toys(std::cin));
    //char theFile[] = "/Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/01-mark-and-toys/test07.txt";
    //std::ifstream istr(theFile);
    //printf("%lu\n", most_toys(istr));
    
	return 0;
}
