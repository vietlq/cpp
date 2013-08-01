#include <stdio.h>
#include <stdlib.h>

void escape_space(char * str)
{
	size_t n = 0, // String len
		k = 0, // the number of spaces
		idx1 = 0, // the index in the original string
		idx2 = 0; // the index in the modified string
	char * p = str;
	// Find the length of the string & number of spaces
	while((NULL != p) && (0 != *p))
	{
		if(' ' == *p) ++k;
		++p; ++n;
	}
	
	// Assign idx1 & idx2 to the 
	idx1 = n - 1;
	idx2 = idx1 + 2*k;
	while(idx2 > idx1)
	{
		if(' ' == str[idx1])
		{
			str[idx2 - 2] = '%';
			str[idx2 - 1] = '2';
			str[idx2] = '0';
			idx2 -= 3;
		}
		else
		{
			str[idx2] = str[idx1];
			--idx2;
		}
		--idx1;
	}
}

int main()
{
	char str[1024] = "The quick brown fox jumps over the lazy dog";
	printf("Before: %s\n", str);
	escape_space(str);
	printf("After: %s\n", str);
	return 0;
}

