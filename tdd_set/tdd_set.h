#ifndef SET_H
#define SET_H

/*
This class passes all test cases given.
The idea is not to implement the most efficient
set data structure.
The idea is to play with TDD concepts.
I would refactor this to use BST not an array bounded by 1024.
*/

class Set
{
public:
	Set(): _size(0), _pArr(0)
	{
		_pArr = new int[1024];
	}
	
	~Set()
	{
		delete[] _pArr;
	}
	
	bool isEmpty() const
	{
		return (_size < 1);
	}
	
	void add(int value)
	{
		if(! contains(value))
		{
			_pArr[_size] = value;
			++_size;
		}
	}
	
	int size() const
	{
		return _size;
	}
	
	bool contains(int value) const
	{
		return (getIndexOf(value) > -1);
	}
	
	void remove(int value)
	{
		int idx = getIndexOf(value);
		
		if(idx > -1)
		{
			if(idx < _size - 1)
			{
				_pArr[idx] = _pArr[_size - 1];
			}
			--_size;
		}
	}
private:
	int _size;
	int * _pArr;
	
	int getIndexOf(int value) const
	{
		int idx = 0;
		
		while((idx < _size) && (_pArr[idx] != value))
		{
			++idx;
		}
		
		return ((idx < _size) ? idx : -1);	
	}
};

#endif // SET_H
