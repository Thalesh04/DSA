/* student class
test class
result class

*/
#include <iostream>
using namespace std;

class A
{
public:
    void m()
    {
        cout << "this is A" << endl;
    }
};

class B : public A
{
public:
    void n()
    {
        cout << "this is B" << endl;
    }
};

class C : public A
{
public:
    void o()
    {
        cout << "this is C" << endl;
    }
};
class D : public B, public C
{
public:
    void p()
    {
        cout << "this is D" << endl;
    }
};

int main()
{
    D d;
    d.m();
    d.n();
    d.o();
    d.p();
}