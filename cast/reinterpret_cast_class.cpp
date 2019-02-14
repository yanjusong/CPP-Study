#include <iostream>
using namespace std;

class A
{
  public:
    void fun_a()
    {
        cout << "In class A\n";
    }
};

class B
{
  public:
    void fun_b()
    {
        cout << "In class B\n";
    }
};

int main()
{
    // creating object of class B
    B *x = new B();

    // converting the pointer to object
    // referenced of class B to class A
    A *new_a = reinterpret_cast<A *>(x);

    // accessing the function of class A
    // unsafe
    new_a->fun_a();
    return 0;
}
