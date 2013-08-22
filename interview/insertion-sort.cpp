#include <iostream>
#include <algorithm>

template<typename BidirIterator>
void insertion_sort(BidirIterator first, BidirIterator last)
{
	BidirIterator currIt = first;
    // Get to the second element
    ++currIt;
    
	for(; currIt != last; ++currIt)
	{
		BidirIterator tempRunner = currIt;
		BidirIterator tempChaser = currIt;
        --tempRunner;
        
		for(; tempRunner != first; --tempRunner)
		{
			if(*tempRunner > *tempChaser)
			{
				std::swap(*tempRunner, *tempChaser);
                tempChaser = tempRunner;
			}
            else
            {
                break;
            }
		}
        
        // This is for Bidirectional Iterators, we have to check the first one
        if(*first > *tempChaser)
        {
            std::swap(*first, *tempChaser);
        }
	}
}

template<typename RandomIterator>
void insertion_sort_rand_it(RandomIterator first, RandomIterator last)
{
    // Get to the second element
	RandomIterator currIt = first + 1;
    const RandomIterator lowerBound = first - 1;
    
	for(; currIt != last; ++currIt)
	{
		RandomIterator tempRunner = currIt - 1;
		RandomIterator tempChaser = currIt;
        
		for(; tempRunner != lowerBound; --tempRunner)
		{
			if(*tempRunner > *tempChaser)
			{
				std::swap(*tempRunner, *tempChaser);
                tempChaser = tempRunner;
			}
            else
            {
                break;
            }
		}
	}
}

int main()
{
	int a[] = {3, 9999, 10, 100, 37, 37623, 88, 7, 2};
    size_t size = sizeof(a)/sizeof(int);
    
    printf("Before sorting:\n");
    for(size_t idx = 0; idx < size; ++idx)
    {
        printf("a[%lu] = %d\n", idx, a[idx]);
    }
    
    insertion_sort_rand_it(a, a + size);
    
    printf("\nAfter sorting:\n");
    for(size_t idx = 0; idx < size; ++idx)
    {
        printf("a[%lu] = %d\n", idx, a[idx]);
    }
    
	return 0;
}

