#include <iostream>
using namespace std;

class Person
{
public:
	Person() {}
	~Person() {}
	void aboutMe() const
	{
		std::cout << "I am an instance of Person" << std::endl;
	}
};

class Student: public Person
{
public:
	Student() {}
	~Student() {}
	void aboutMe() const
	{
		std::cout << "I am an instance of Student" << std::endl;
	}
};

int main()
{
	Person * p = new Student;
	Student * s = new Student;
	
	p->aboutMe();
	s->aboutMe();
	
	delete p;
	delete s;
	
	return 0;
}

