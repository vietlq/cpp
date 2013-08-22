//
//  main.cpp
//  CodeTester
//
//  Created by Le Quoc Viet on 18/8/13.
//  Copyright (c) 2013 Le Quoc Viet. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

/*
class A
{
public:
    int x;
    explicit A(int xx): x(xx){}
    void virtual def() throw(int, double, long);
};

class B: A
{
public:
    void def() throw(double, int, long);
};
 */

/*
class A
{
public:
    void abc(int);
};

void (A::*abc)(int);
*/

class X
{   
public:
    virtual void fun() = 0;
};

// Is it possible?
void X::fun()
{
    std::cout << "Called from X!" << std::endl;
}

class Y: public X
{
public:
    void fun()
    {
        std::cout << "Called from Y!" << std::endl;
        
        X::fun();
    }
};

int main(int argc, const char * argv[])
{
    /*
    A a('7');
    A b(a);
    A c = b;
    //A d = 7;
     int n = 18;
     
     std::cout << std::hex << std::showbase << n;
     std::string abc;
     std::getline(std::cin, abc);
     
     //std::cout << b.x;

     */
    
    //char xyz[] = "";
    //std::cout << "sizeof(xyz) = " << sizeof(xyz) << std::endl;
    
    /*
    std::vector<int> v;
    for(int i = 0; i < 5; ++i) v.push_back(i);
    
    v.erase(std::find(v.rbegin(), v.rend(), 2).base());
    v.insert(std::find(v.rbegin(), v.rend(), 1).base(), 10);
    
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    */
    
    // You cannot create an instance of X, but free to define pure virtual methods of X
    //X x;
    
    // You cannot call non-static member function outside the class/its sub-classes
    //X::fun();
    
    Y y;
    y.fun();
    
    return 0;
}

