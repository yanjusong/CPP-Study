#include <iostream>
using namespace std;

class Base
{
  public:
    virtual void foo()
    {
        cout << "in Base::foo()\n";
    }
};

class Derived1 : public Base
{
  public:
    virtual void foo()
    {
        cout << "in Derived1::foo()\n";
    }
};

class Derived2 : private Base
{
  public:
    virtual void foo()
    {
        cout << "in Derived2::foo()\n";
    }
};

int main()
{
    Derived1 d1;
    Base *b1 = (Base *)(&d1); // allowed
    Base *b2 = static_cast<Base *>(&d1);
    b1->foo();
    b2->foo();

    Derived2 d2;
    Base *b3 = (Base *)(&d2); // allowed
    // error: cannot cast 'Derived2' to its private base class 'Base'
    // Base *b4 = static_cast<Base *>(&d2);

    b3->foo();

    return 0;
}
