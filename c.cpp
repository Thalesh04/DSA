#include <iostream>
using namespace std;
class Student
{
public:
    int rollNo;
    void inputRollNo()
    {
        cout << "Enter roll no:" << endl;
        cin >> rollNo;
    }
};

class Test : public Student
{

public:
    int p, c, m, e, h;
    void n()
    {
        cout << "Enter Physics marks:" << endl;
        cin >> p;
        cout << "Enter Chemistry marks:" << endl;
        cin >> c;
        cout << "Enter Mathematics marks:" << endl;
        cin >> m;
        cout << "Enter English marks:" << endl;
        cin >> e;
        cout << "Enter Hindi marks:" << endl;
        cin >> h;
    }
};

class Result : public Test
{
public:
    int avg;
    int total;
    void Display()
    {
        total = p + c + m + e + h;
        avg = total / 5;

        cout << "Roll Number: " << rollNo << endl;
        cout << "Enter Physics marks:" << p << endl;
        cout << "Enter Chemistry marks:" << c << endl;
        cout << "Enter Mathematics marks:" << m << endl;
        cout << "Enter English marks:" << e << endl;
        cout << "Enter Hindi marks:" << h << endl;
        cout << "Average : " << avg << endl;
        cout << "Total: " << total << endl;
    }
};

int main()
{
    Result r;
    r.inputRollNo();
    r.n();
    r.Display();
}