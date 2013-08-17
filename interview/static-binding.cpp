#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		std::cout << "Initializing an instance of Person" << std::endl;
	}
	
	// Expect memory leaks if the sub-class has more data members or virtual functions. To remedy: Make the destructor virtual
	~Person()
	{
		std::cout << "Deleting an instance of Person" << std::endl;
	}
	
	void aboutMe() const
	{
		std::cout << "I am an instance of Person" << std::endl;
	}
};

class Student: public Person
{
public:
	Student()
	{
		std::cout << "Initializing an instance of Student" << std::endl;
	}
	
	// Expect memory leaks if the sub-class has more data members or virtual functions. To remedy: Make the destructor virtual
	~Student()
	{
		std::cout << "Deleting an instance of Student" << std::endl;
	}
	
	void aboutMe() const
	{
		std::cout << "I am an instance of Student" << std::endl;
	}
};

class GradStudent: public Student
{
public:
	GradStudent()
	{
		std::cout << "Initializing an instance of GradStudent" << std::endl;
	}
	
	~GradStudent()
	{
		std::cout << "Deleting an instance of GradStudent" << std::endl;
	}
	
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
