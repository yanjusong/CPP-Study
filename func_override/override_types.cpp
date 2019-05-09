#include <iostream>
using namespace std;

// C++函数重载判断
// 1.参数类型
// 2.参数个数
// 3.参数是否被const修饰

void print(const string &info)
{
    cout << info << endl;
}

class Student
{
public:
    void foo() 
    {
        print("void foo()");
    }

    void foo(int x) 
    {
        print("void foo(int)");
    }

    // error
    // void foo(const int &x) 
    // {
    //     print("void foo(const int&)");
    // }

    // error
    // int foo(int x) 
    // {
    //     print("void foo(int)");
    //     return 0;
    // }

    void foo(int x) const
    {
        print("void foo(int) const");
    }

    void foo(double d)
    {
        print("void foo(double)");
    }

    void foo(float d)
    {
        print("void foo(float)");
    }

    void foo(string s)
    {
        print("void foo(string)");
    }

    void foo(int x, int y)
    {
        print("void foo(int, int)");
    }
};

void callFunc(const Student &s)
{
    s.foo(1);
}

int main()
{
    Student s;
    s.foo(1);
    s.foo("1");
    s.foo(0.1);
    s.foo(float(1));
    s.foo(1, 1);

    const Student &cs = s;
    cs.foo(1);
    // cs.foo("1"); // error

    callFunc(s);

    return 0;
}
