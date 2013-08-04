#include <iostream>
//#include <fstream>
#include <queue>

typedef unsigned long base_type;
typedef std::priority_queue<base_type, std::vector<base_type>, std::greater<base_type> > toy_pq_t;

base_type most_toys(std::istream & istr)
{
	//
	base_type N, price, tempPrice;
	unsigned long long K, total;
	toy_pq_t toyPrices;
    int count = 0;
    
	//
	istr >> N >> K;
    
    total = 0;
	price = 0;
	while(count < N)
	{
		istr >> price;
        
		if((price > 0) && (price <= K))
		{
			if(total + price <= K)
			{
				toyPrices.push(price);
				total += price;
			}
			else if(total + price - toyPrices.top() <= K)
			{
				tempPrice = toyPrices.top();
				toyPrices.pop();
				toyPrices.push(price);
				total += price - tempPrice;
			}
		}
        
		price = 0;
        ++count;
	}
    
	return  toyPrices.size();
}

int main()
{
	printf("%lu\n", most_toys(std::cin));
    //std::ifstream istr("/Users/vietlq/projects/hacker-rank-2013-08/01-mark-and-toys/test07.txt");
    //printf("%lu\n", most_toys(istr));
    
	return 0;
}
