#include <iostream>
#include <typeinfo> //for 'typeid' to work

class Base
{
  public:
    virtual ~Base() {}
};

class Derived : public Base
{
};

int main()
{
    Base b;
    Derived d;
    Base *ptr = &b;
    // The string returned by typeid::name is implementation-defined
    std::cout << typeid(b).name() << std::endl;    // Base (statically known at compile-time)
    std::cout << typeid(d).name() << std::endl;    // Derived (statically known at compile-time)
    std::cout << typeid(ptr).name() << std::endl;  // Base * (statically known at compile-time)
    std::cout << typeid(*ptr).name() << std::endl; // Derived (looked up dynamically at run-time
                                                   //           because it is the dereference of a
                                                   //           pointer to a polymorphic class)
    return 0;
}