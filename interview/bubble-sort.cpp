#include <iostream>
#include <algorithm>

template<typename BidirIterator>
void bubble_sort(BidirIterator first, BidirIterator last)
{
	BidirIterator lastEleIt = last;
    // Get to the last element
    --lastEleIt;
    
	for(; lastEleIt != first; --lastEleIt)
	{
		BidirIterator tempLowerIt = first;
		for(; tempLowerIt != lastEleIt; ++tempLowerIt)
		{
			if(*tempLowerIt > *lastEleIt)
			{
				std::swap(*tempLowerIt, *lastEleIt);
			}
		}
	}
}

int main()
{
	int a[] = {3, 9999, 10, 100, 37, 37623, 88, 7, 2};
    size_t size = sizeof(a)/sizeof(int);
    
    for(size_t idx = 0; idx < size; ++idx)
    {
        printf("a[%lu] = %d\n", idx, a[idx]);
    }
    
    bubble_sort(a, a + size);
    
    for(size_t idx = 0; idx < size; ++idx)
    {
        printf("a[%lu] = %d\n", idx, a[idx]);
    }
    
	return 0;
}

