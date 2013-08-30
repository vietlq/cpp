/*
Given a n x n matrix

4 4 20 9
2 -1 30 5
40 2 -6 9
10 11 7 11

Find the maximum sum of paths of length n of adjacent cells,
so that no adjacent cell are on the same horizontal line
*/

/*
This can be solved in linear time O(N) where N = n*n
and with linear extra space 2*n
*/

#include <iostream>
#include <algorithm>
#include <iterator>

int main(int argc, char* argv[])
{
	int rows, cols;
	int * values = NULL;
	
	std::cin >> rows >> cols;
	values = new int[rows*cols];
	
	for(int r = 0; r < rows; ++r)
	{
		for(int c = 0; c < cols; ++c)
		{
			std::cin >> values[r*cols + c];
		}
	}
	
	int * prevSum = new int[cols];
	int * currSum = new int[cols];
	
	std::copy(&values[0], &values[0] + cols, prevSum);
	
	for(int r = 1; r < rows; ++r)
	{
		std::copy(&values[r*cols], &values[r*cols] + cols, currSum);
		for(int c = 0; c < cols; ++c)
		{
			int tempMaxSum = currSum[c] + prevSum[c];
			const int minCol = std::max(0, c - 1);
			const int maxCol = std::min(c + 1, cols - 1);
			for(int prevCol = minCol; prevCol < maxCol; ++prevCol)
			{
				int tempSum = currSum[c] + prevSum[prevCol];
				tempMaxSum = std::max(tempMaxSum, tempSum);
			}
			currSum[c] = tempMaxSum;
		}
		std::copy(currSum, currSum + cols, prevSum);
	}
	
	//std::cout << "\nLast row:\n";
	//std::for_each(prevSum, prevSum + cols, [](int x) { std::cout << x << " "; });
	//std::cout << std::endl;
	std::cout << "The max sum of all paths is: " << *std::max_element(prevSum, prevSum + cols) << std::endl;
	
	delete[] currSum;
	delete[] prevSum;
	delete[] values;
	
	return 0;
}

