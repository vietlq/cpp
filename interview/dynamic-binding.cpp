#include <iostream>
using namespace std;

// Once virtual, forever virtual

class Person
{
public:
	Person() {}
	~Person() {}
	virtual void aboutMe() const
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

class GradStudent: public Student
{
public:
	GradStudent() {}
	~GradStudent() {}
	void aboutMe() const
	{
		std::cout << "I am an instance of GradStudent" << std::endl;
	}
};

int main()
{
	Person * p = new Student;
	Student * s = new Student;
	Student * gs = new GradStudent;
	Person * ps = new GradStudent;
	
	p->aboutMe();
	s->aboutMe();
	gs->aboutMe();
	ps->aboutMe();
	
	delete p;
	delete s;
	delete gs;
	delete ps;
	
	return 0;
}

